#include "Compile/BTCompilerVMBackend.h"
#include "Compile\BTFunctionContext.h"
#include "BlueprintEditor/Core/Architect/K3Node.h"
#include "BTScript.h"
#include "Compile/BTBlueprintCompiledStatement.h"
#include "HAL\UnrealMemory.h"
#include "UObject\NameTypes.h"
#include "Serialization\ArchiveUObject.h"
#include "Serialization\Archive.h"
#include "UObject\UnrealType.h"
#include "EdGraph\EdGraphNode.h"
#include "UObject\Script.h"
#include "Internationalization\TextPackageNamespaceUtil.h"
#include "Misc\DefaultValueHelper.h"
#include "Compile/BTCompilationContext.h"
#include "BlueprintEditor\Core\Architect\VariableNode.h"

#if PLATFORM_WINDOWS
#pragma optimize("", off)
#endif // PLATFORM_WINDOWS


FVM::FVM(FBTFunctionContext* NewFunctionList) : FunctionList(NewFunctionList)
{
}

bool FVM::CheckNodeOrder(UEdGraphNode* NodeA, UEdGraphNode* NodeB)
{
	check(!FunctionList->LinearExecutionList.IsEmpty() && NodeA && NodeB);
	if (NodeA == NodeB)
	{
		return false;
	}

	for (auto& TempNode : FunctionList->LinearExecutionList)
	{
		if (TempNode == NodeA)
		{
			return true;
		}

		if (TempNode == NodeB)
		{
			return false;
		}
	}

	return false;
}

namespace BTScriptCode
{
	class FScriptCodeWriter : public FArchiveUObject
	{
	public:
		static TMap<UFunction*, uint32> BufferPos;

		UFunction* Function;
		TArray<uint8>& ScriptBuffer;
		uint32 Pos;

	public:
		FScriptCodeWriter(UFunction* InFunction) : Function(InFunction), ScriptBuffer(InFunction->Script), Pos(0)
		{
			if (!BufferPos.Contains(InFunction))
			{
				ScriptBuffer.Empty();
			}
		}



		static void ClearStaticBufferPos()
		{
			BufferPos.Empty();
		}

		void LoadBufferPos()
		{
			if (BufferPos.Contains(Function))
			{
				Pos = BufferPos[Function];
			}
		}
		void SaveBufferPos()
		{
			if (BufferPos.Contains(Function))
			{
				BufferPos[Function] = Pos;
			}
			else
			{
				BufferPos.Add(Function, Pos);
			}
		}

		//V����Ҫ���л���ֵ��Length���ֽڳ���
		virtual void Serialize(void* V, int64 Length) override
		{
			/*if(IsLoading())
			{
				check(ScriptBuffer.IsValidIndex(Pos - Length));
				Pos-=Length;
				FMemory::Memcpy(V, &(ScriptBuffer[Pos]), Length);
			}
			else*/
			LoadBufferPos();
			{
				int32 Start = ScriptBuffer.AddUninitialized(Length);
				check(Start == Pos);
				FMemory::Memcpy(&(ScriptBuffer[Start]), V, Length);
				Pos += Length;
			}
			SaveBufferPos();
		}
		
		using FArchiveUObject::operator<<;

		virtual FArchive& operator<<(FName& Name) override
		{
			//�ƺ�����Ҫloading

			FArchive& Ar = *this;

			/*if (Ar.IsLoading())
			{
				uint32 DisplayIndex = 0;
				uint32 ComparisonIndex = 0;
				int32 Number = 0;
				Ar << Number << ComparisonIndex << DisplayIndex;

				Name = FName(FNameEntryId::FromUnstableInt(ComparisonIndex), FNameEntryId::FromUnstableInt(DisplayIndex), Number);
			}
			else*/
			{
				uint32 DisplayIndex = Name.GetDisplayIndex().ToUnstableInt();
				uint32 ComparisonIndex = Name.GetComparisonIndex().ToUnstableInt();
				int32 Number = Name.GetNumber();
				Ar << DisplayIndex << ComparisonIndex << Number;
			}

			return Ar;
		}

		virtual FArchive& operator<<(UObject*& Object) override
		{
			ScriptPointerType ObjPtr = (ScriptPointerType)Object;
			(*this) << ObjPtr;
			return *this;
		}

		virtual FArchive& operator<<(FProperty* Property)
		{
			ScriptPointerType ObjPtr = (ScriptPointerType)Property;
			(*this) << ObjPtr;
			return *this;
		}

		virtual FArchive& operator<<(TCHAR* Str)
		{
			Serialize(Str, FCString::Strlen(Str) + 1);
			return *this;
		}

		virtual FArchive& operator<<(EVMCommand Command)
		{
			checkSlow(Command < 0xFF);
			uint8 Byte = Command;
			Serialize(&Byte, sizeof(Byte));
			return *this;
		}

		virtual FArchive& operator<<(EBlueprintTextLiteralType TextLiteralType)
		{
			uint8 Byte = (uint8)TextLiteralType;
			Serialize(&Byte, sizeof(Byte));
			return *this;
		}

	};

	TMap<UFunction*, uint32> FScriptCodeWriter::BufferPos{};
}

struct FScriptBuilder
{
public:
	BTScriptCode::FScriptCodeWriter Writer;
	UFunction* Function;
public:
	FScriptBuilder(UFunction* InFunction) : Writer(InFunction), Function(InFunction){}

	static void ClearStaticBufferPos()
	{
		BTScriptCode::FScriptCodeWriter::ClearStaticBufferPos();
	}

	void SeriealizeLiteralString(const FString& Str)
	{
		if (FCString::IsPureAnsi(*Str))//*Str <= 0x7f, (*Str)++
		{
			Writer << EVMCommand::VMC_String;
			uint8 OutChar;
			for (const TCHAR* Ch = *Str; *Ch; ++Ch)
			{
				OutChar = CharCast<ANSICHAR>(*Ch);
				Writer << OutChar;
			}
			OutChar = 0;
			Writer << OutChar;
		}
	}

	//���л���Pin�Ķ��ӣ��Լ���ֵ
	void SeriealizeNormalTerminal(FProperty* CoerceProperty, TSharedPtr<FFunctionTerminal> ValueAddr)
	{

		if (CoerceProperty->IsA<FStrProperty>())
		{
			SeriealizeLiteralString(ValueAddr->DefaultValue);
		}
		else if (CoerceProperty->IsA<FObjectProperty>() || CoerceProperty->IsA<FClassProperty>())
		{

			if (ValueAddr->DefaultValue.IsEmpty())
			{
				Writer << VMC_NullObject;
			}
			else
			{
				UObject* Obj = LoadObject<UObject>(nullptr, *ValueAddr->DefaultValue);
				if(Obj)
				{
					Writer << VMC_Object;
					Writer << Obj;
				}
				else
				{
					Writer << VMC_NullObject;
				}
			}
		}
		else if (CoerceProperty->IsA<FByteProperty>())
		{
			uint8 Value = FCString::Atoi(*ValueAddr->DefaultValue);
			Writer << VMC_Byte;
			Writer << Value;
		}
		else if (CoerceProperty->IsA<FBoolProperty>())
		{
			bool Value = ValueAddr->DefaultValue.ToBool();
			if (Value)
			{
				Writer << EVMCommand::VMC_True;
			}
			else
			{
				Writer << EVMCommand::VMC_False;
			}
		}
		else if (CoerceProperty->IsA<FIntProperty>())
		{
			int32 Value = FCString::Atoi(*ValueAddr->DefaultValue);
			Writer << EVMCommand::VMC_Int32;
			Writer << Value;
		}
		else if (CoerceProperty->IsA<FInt64Property>())
		{
			int64 Value = FCString::Atoi64(*ValueAddr->DefaultValue);

			Writer << EVMCommand::VMC_Int64;
			Writer << Value;
		}
		else if (CoerceProperty->IsA<FFloatProperty>())
		{
			float Value = FCString::Atof(*ValueAddr->DefaultValue);
			Writer << EVMCommand::VMC_Float;
			Writer << Value;
		}
		else if (CoerceProperty->IsA<FDoubleProperty>())
		{
			double Value = FCString::Atod(*ValueAddr->DefaultValue);
			Writer << EVMCommand::VMC_Double;
			Writer << Value;
		}
		else if (CoerceProperty->IsA<FNameProperty>())
		{
			FName Name(*ValueAddr->DefaultValue);
			Writer << EVMCommand::VMC_Name;
			Writer << Name;
		}
		else if (CoerceProperty->IsA<FStructProperty>())
		{
			FStructProperty* StructProperty = CastField<FStructProperty>(CoerceProperty);
			UScriptStruct* Struct = StructProperty->Struct;
			if (Struct == TBaseStructure<FVector>::Get())
			{
				FVector Vector = FVector::ZeroVector;
				if (!ValueAddr->DefaultValue.IsEmpty())
				{
					//�����ַ����Ƿ����Զ����ʽ��vector
					const bool bParseUsingCustomFormat = FDefaultValueHelper::ParseVector(ValueAddr->DefaultValue, Vector);
					//Vector.InitFromString()
					if (!bParseUsingCustomFormat)
					{
						Struct->ImportText(*ValueAddr->DefaultValue, &Vector, nullptr, EPropertyPortFlags::PPF_None, nullptr, GetPathNameSafe(StructProperty));
					}
				}
				Writer << VMC_Vector;
				Writer << Vector;
			}
			else if (Struct == TBaseStructure<FTransform>::Get())
			{
				FTransform Transform = FTransform::Identity;
				if (!ValueAddr->DefaultValue.IsEmpty())
				{
					//�����ַ����Ƿ����Զ����ʽ��vector
					const bool bParseUsingCustomFormat = Transform.InitFromString(ValueAddr->DefaultValue);
					if (!bParseUsingCustomFormat)
					{
						Struct->ImportText(*ValueAddr->DefaultValue, &Transform, nullptr, EPropertyPortFlags::PPF_None, nullptr, GetPathNameSafe(StructProperty));
					}
				}
				Writer << VMC_Transform;
				Writer << Transform;
			}
			else if (Struct == TBaseStructure<FRotator>::Get())
			{
				FRotator Rotator = FRotator::ZeroRotator;
				if (!ValueAddr->DefaultValue.IsEmpty())
				{
					//�����ַ����Ƿ����Զ����ʽ��vector
					const bool bParseUsingCustomFormat = FDefaultValueHelper::ParseRotator(ValueAddr->DefaultValue, Rotator);
					if (!bParseUsingCustomFormat)
					{
						Struct->ImportText(*ValueAddr->DefaultValue, &Rotator, nullptr, EPropertyPortFlags::PPF_None, nullptr, GetPathNameSafe(StructProperty));
					}
				}
				Writer << VMC_Rotation;
				Writer << Rotator;
			}
			else if (Struct == TBaseStructure<FLinearColor>::Get())
			{
				FLinearColor Color(0,0,0,0);
				Color.InitFromString(ValueAddr->DefaultValue);

				Writer << VMC_LinearColor;
				Writer << Color.R;
				Writer << Color.G;
				Writer << Color.B;
				Writer << Color.A;
			}
		}
		else if (CoerceProperty->IsA<FTextProperty>())
		{
			Writer << EVMCommand::VMC_Text;

			const FString& StrValue = FTextInspector::GetDisplayString(ValueAddr->DefaultTextValue);

			if (ValueAddr->DefaultTextValue.IsEmpty())
			{
				Writer << EBlueprintTextLiteralType::Empty;
			}
			else if (ValueAddr->DefaultTextValue.IsCultureInvariant())
			{
				Writer << EBlueprintTextLiteralType::InvariantText;
				SeriealizeLiteralString(StrValue);
			}
			else
			{
				bool bLocalized = false;
				FString Namespace;
				FString Key;
				const FString* SourceStr = FTextInspector::GetSourceString(ValueAddr->DefaultTextValue);

				if (SourceStr && ValueAddr->DefaultTextValue.ShouldGatherForLocalization())
				{
					FTextId Id = FTextInspector::GetTextId(ValueAddr->DefaultTextValue);
					bLocalized = !Id.IsEmpty();

					//��ʱ�����ռ�Ϊ �����ռ����� + ���Ĺ�ϣ
					Namespace = Id.GetNamespace().GetChars();
					Key = Id.GetKey().GetChars();
				}

				if (bLocalized)
				{
					Namespace = TextNamespaceUtil::StripPackageNamespace(Namespace);

					Writer << EBlueprintTextLiteralType::LocalizedText;
					SeriealizeLiteralString(Namespace);
					SeriealizeLiteralString(Key);
					SeriealizeLiteralString(*SourceStr);
				}
				else
				{
					Writer << EBlueprintTextLiteralType::LiteralString;
					SeriealizeLiteralString(StrValue);
				}

			}

		}
	}

	

	virtual ~FScriptBuilder(){}

};


void FVM::SeriealizeTerminal(UK3Node* Node)
{

	FScriptBuilder TerminialBuilder(Node->Function);
	//����ֵ���л���UFunction��, λ��Ϊ��ǰ��
	SeriealizeReturnValue(TerminialBuilder, Node);

	for (TFieldIterator<FProperty> Iter(Node->Function); Iter; ++Iter)
	{
		FProperty* Prop = *Iter;
		if (!(Prop->PropertyFlags & CPF_ReturnParm))
		{
			TArray<TSharedPtr<FFunctionTerminal>> Terminals = FunctionList->FindTerminalArrayByProperty(Node, Prop);
						
			if(Terminals.Num() >= 1)
			{
				TSharedPtr<FFunctionTerminal> InputTerminal;
				if (Terminals.Num() == 2)
				{
					TSharedPtr<FFunctionTerminal> OutputTerminal;
					if (Terminals[0]->Direction == EGPD_Input)
					{
						InputTerminal = Terminals[0];
						OutputTerminal = Terminals[1];
					}
					else
					{
						InputTerminal = Terminals[1];
						OutputTerminal = Terminals[0];
					}

					if (InputTerminal->IsLink())
					{
						
						UK3Node* K3Node = Cast<UK3Node>(InputTerminal->InputPin->GetOwningNode());
						if (K3Node->IsPure())
						{
							//�Ȳ鿴�ǲ��Ǵ��ڵ㣬�����Ȼ��鿴��û�б����л���
							SeriealizePureFunction(TerminialBuilder, K3Node);
						}
						else if (K3Node->IsA<UVariableNode>())
						{
							//�Ȳ鿴�ǲ�����ͼ�����ڵ㣬�����Ȼ��鿴��û�б����л���
							if(SeriealizeBPVariable(TerminialBuilder, K3Node, InputTerminal->InputPin, Prop))
							{
								continue;
							}
						}

						//�����룬��ΪPin����
						if (OutputTerminal->IsLink())
						{
							// VMC_LoadAndSaveValue
							//      FGuid
							//      FGuid
							//�����
							TerminialBuilder.Writer << EVMCommand::VMC_LoadAndSaveValue;
							TerminialBuilder.Writer << InputTerminal->InputPin->PinId;
							TerminialBuilder.Writer << OutputTerminal->PinId;
						}
						else
						{
							// VMC_LoadValue
							//  FGuid
							// û�����
							TerminialBuilder.Writer << EVMCommand::VMC_LoadValue;
							TerminialBuilder.Writer << InputTerminal->InputPin->PinId;
						}
					}
					else
					{
						// �����룬��Ϊ���ı�����
						if (OutputTerminal->IsLink())
						{
							// VMC_SaveValue
							//  FGuid
							// VMC_Int32
							//    1
							// �����
							TerminialBuilder.Writer << EVMCommand::VMC_SaveValue;
							TerminialBuilder.Writer << OutputTerminal->PinId;
							TerminialBuilder.SeriealizeNormalTerminal(Prop, InputTerminal);
						}
						else
						{
							// û����������մ��ı���ʽ
							TerminialBuilder.Writer << EVMCommand::VMC_PureText;
							TerminialBuilder.SeriealizeNormalTerminal(Prop, InputTerminal);
						}
					}

				}
				else
				{
					InputTerminal = Terminals[0];

					

					if (InputTerminal->IsLink())
					{
						UK3Node* K3Node = Cast<UK3Node>(InputTerminal->InputPin->GetOwningNode());
						if (K3Node->IsPure())
						{
							//�Ȳ鿴�ǲ��Ǵ��ڵ㣬�����Ȼ��鿴��û�б����л���
							SeriealizePureFunction(TerminialBuilder, K3Node);
						}
						else if (K3Node->IsA<UVariableNode>())
						{
							//�Ȳ鿴�ǲ�����ͼ�����ڵ㣬�����Ȼ��鿴��û�б����л���
							if (SeriealizeBPVariable(TerminialBuilder, K3Node, InputTerminal->InputPin, Prop))
							{
								continue;
							}
						}

						// VMC_LoadValue
						//  FGuid
						//ֻ�����룬��ΪPin����
						TerminialBuilder.Writer << EVMCommand::VMC_LoadValue;
						TerminialBuilder.Writer << InputTerminal->InputPin->PinId;

					}
					else
					{
						// VMC_PureText
						//  VMC_Name
						//ֻ�����룬��Ϊ���ı�����
						TerminialBuilder.Writer << EVMCommand::VMC_PureText;
						TerminialBuilder.SeriealizeNormalTerminal(Prop, InputTerminal);
					}

				}
			}

		}
	}
}

void FVM::SeriealizeReturnValue(FScriptBuilder& ScriptBuilder,UK3Node* Node)
{
	FProperty* ReturnValueProp = nullptr;
	for (TFieldIterator<FProperty> Iter(Node->Function); Iter; ++Iter)
	{
		FProperty* Temp = *Iter;
		if (Temp->PropertyFlags & CPF_ReturnParm)
		{
			ReturnValueProp = Temp;
		}
	}

	//1.�޷���ֵ��ֱ������,
	//2.�з���ֵ�����޽ڵ��Pin���ã���Ҫ�洢
	//3.�з���ֵ����Ҫ�洢

	if (ReturnValueProp)
	{
		//�з���ֵ��������û�б���¶
		TSharedPtr<FFunctionTerminal> ReturnValueTerminal = FunctionList->FindTerminalByProperty(Node, ReturnValueProp, EEdGraphPinDirection::EGPD_Output);
		if (ReturnValueTerminal.IsValid())
		{
			if(ReturnValueTerminal->IsLink())
			{
				// VMC_ReturnParam
				//     Size
				//     FGuid

				//�з���ֵ���ұ������ڵ�����
				ScriptBuilder.Writer << VMC_ReturnParam;
				ScriptBuilder.Writer << ReturnValueTerminal->PinId;	
				return;
			}
			ScriptBuilder.Writer << VMC_NoReturnParam;
			return;
		}
	}
}

void FVM::SeriealizePureFunction(FScriptBuilder& ScriptBuilder, UK3Node* Node)
{
	if (NonLinearExectueNode.Find(Node) == INDEX_NONE)
	{
		//����û�����л�
		ScriptBuilder.Writer << EVMCommand::VMC_Function;
		ScriptBuilder.Writer << Node->Function;
		SeriealizeTerminal(Node);
		NonLinearExectueNode.Add(Node);
	}
}

bool FVM::SeriealizeBPVariable(FScriptBuilder& ScriptBuilder, UK3Node* Node, UEdGraphPin* InPin, FProperty* Property)
{
	if (NonLinearExectueNode.Find(Node) == INDEX_NONE)
	{
		TSharedPtr<FFunctionTerminal> BPVariableTerminals = FunctionList->FindTerminalByPin(Node, InPin, EEdGraphPinDirection::EGPD_Output);
		ScriptBuilder.Writer << VMC_SaveValue;
		ScriptBuilder.Writer << BPVariableTerminals->PinId;
		ScriptBuilder.SeriealizeNormalTerminal(Property, BPVariableTerminals);
		NonLinearExectueNode.Add(Node);
		return true;
	}
	return false;
}

void FVM::GenerateByteCode()
{	
	if (!FunctionList)
	{
		return;
	}

	NonLinearExectueNode.Empty();

	//�ֽ���д��UFunction��Script
	UK3Node* EventNode = Cast<UK3Node>(FunctionList->LinearExecutionList[0]);
	FScriptBuilder ScriptBuilder(EventNode->Function);

	for (auto& TempVMStatePair : FunctionList->ListVMStatement)
	{
		if (UK3Node* Node = Cast<UK3Node>(TempVMStatePair.Key))
		{

			switch (TempVMStatePair.Value)
			{
			case VMS_CallFunc:
			{
				
				TArray<TSharedPtr<FFunctionTerminal>> TerminalArray = FunctionList->Find(Node);

				if (TerminalArray.Num())
				{
					ScriptBuilder.Writer << VMC_ExternalParam;
				}

				for (auto& Terminal : TerminalArray)
				{
					ScriptBuilder.Writer << Terminal->PinId;
				}
				break;
			}
			case VMS_Next:
			{		
				//����ֵ
				ScriptBuilder.Writer << EVMCommand::VMC_Function;
				ScriptBuilder.Writer << Node->Function;

			
				//����
				SeriealizeTerminal(Node);
				break;
			}

			default:
				break;
			}
		}
	}

	//��������
	ScriptBuilder.Writer << EVMCommand::VMC_EndThread;

	FScriptBuilder::ClearStaticBufferPos();
}


#if PLATFORM_WINDOWS
#pragma optimize("", on)
#endif // PLATFORM_WINDOWS