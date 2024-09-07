#include "BlueprintEditor/Core/Architect/K3Node.h"
#include "UObject\Class.h"
#include "Internationalization\Text.h"
#include "Type/BlueprintTypeEType.h"
#include "UObject\UnrealTypePrivate.h"

#pragma optimize("", off)
class FMappingTable
{
public:
	
	static FMappingTable* Get()
	{
		static FMappingTable Table;
		return &Table;
	}

	~FMappingTable(){MappingTable.Empty(); }

	const FName* GetCategory(const FField* InDefaultObject) const;
	const FName& GetRealCategory(const FName& InCategory) const;
	const FName& GetSubCategory(const FName& InCategory) const;
	UObject* GetSubCategoryObject(FProperty* InProperty) const;


private:
	FMappingTable();
	TMap<const FField*, const FName*> MappingTable;
};

FMappingTable::FMappingTable()
{

	MappingTable.Add({ FBoolProperty::StaticClass()->GetDefaultObject(), &FPC_Public::PC_Boolean});
	MappingTable.Add({ FByteProperty::StaticClass()->GetDefaultObject(), &FPC_Public::PC_Byte });
	MappingTable.Add({ FIntProperty::StaticClass()->GetDefaultObject(), &FPC_Public::PC_Int });
	MappingTable.Add({ FInt64Property::StaticClass()->GetDefaultObject(), &FPC_Public::PC_Int64 });
	MappingTable.Add({ FFloatProperty::StaticClass()->GetDefaultObject(), &FPC_Public::PC_Float });
	MappingTable.Add({ FDoubleProperty::StaticClass()->GetDefaultObject(), &FPC_Public::PC_Double });

	MappingTable.Add({ FClassProperty::StaticClass()->GetDefaultObject(), &FPC_Public::PC_Class });
	MappingTable.Add({ FStructProperty::StaticClass()->GetDefaultObject(), &FPC_Public::PC_Struct });
	MappingTable.Add({ FEnumProperty::StaticClass()->GetDefaultObject(), &FPC_Public::PC_Enum });
	MappingTable.Add({ FInterfaceProperty::StaticClass()->GetDefaultObject(), &FPC_Public::PC_Interface });

	MappingTable.Add({ FNameProperty::StaticClass()->GetDefaultObject(), &FPC_Public::PC_Name });
	MappingTable.Add({ FStrProperty::StaticClass()->GetDefaultObject(), &FPC_Public::PC_String });
	MappingTable.Add({ FTextProperty::StaticClass()->GetDefaultObject(), &FPC_Public::PC_Text });

	
	MappingTable.Add({ FDelegateProperty::StaticClass()->GetDefaultObject(), &FPC_Public::PC_Delegate });
	MappingTable.Add({ FObjectProperty::StaticClass()->GetDefaultObject(), &FPC_Public::PC_Object });

	MappingTable.Add({ FSoftObjectProperty::StaticClass()->GetDefaultObject(), &FPC_Public::PC_SoftObject });
	MappingTable.Add({ FSoftClassProperty::StaticClass()->GetDefaultObject(), &FPC_Public::PC_SoftClass });

}

const FName* FMappingTable::GetCategory(const FField* InDefaultObject) const
{	
	check(InDefaultObject)
	return MappingTable.Contains(InDefaultObject) ? *MappingTable.Find(InDefaultObject) : nullptr;
}

const FName& FMappingTable::GetRealCategory(const FName& InCategory) const
{
	if (InCategory == FPC_Public::PC_Float || InCategory == FPC_Public::PC_Double)
	{
		return FPC_Public::PC_Real;
	}
	else if (InCategory == FPC_Public::PC_Enum)
	{
		return FPC_Public::PC_Byte;
	}
	
	return InCategory;
}
const FName& FMappingTable::GetSubCategory(const FName& InCategory) const
{
	if (GetRealCategory(InCategory) == FPC_Public::PC_Real)
	{
		return InCategory;
	}

	return FPC_Public::PC_Default;
}

UObject* FMappingTable::GetSubCategoryObject(FProperty* InProperty) const
{
	if (FStructProperty* StructProperty = CastField<FStructProperty>(InProperty))
	{
		return StructProperty->Struct;
	}
	else if (FEnumProperty* EnumProperty = CastField<FEnumProperty>(InProperty))
	{
		return UEnum::StaticClass();
	}

	return nullptr;
}

void GetNodeTitlePrivate(UK3Node* Node)
{
	if (Node->NodeTitle.IsEmpty())
	{
		if (Node->Function)
		{
			Node->NodeTitle = FText::FromString(Node->Function->GetName());
		}
		else if (!Node->Property.IsPathToFieldEmpty())
		{
			Node->NodeTitle = FText::FromString(Node->Property->GetName());
		}
	}
}


void UK3Node::AllocateDefaultPins()
{
	if (Function)
	{
		if (Function->GetMetaData("CodeType") == "Description")
		{
			CreatePin(EGPD_Input, FPC_Public::PC_Exec, FName(), FPC_Public::PC_Exec);
			CreatePin(EGPD_Output, FPC_Public::PC_Exec, FName(), FPC_Public::PC_Exec);
		}
		else if (Function->GetMetaData("CodeType") == "PureDescription")
		{
		}
	
		FProperty* MyProperty = CastField<FProperty>(Function->ChildProperties);
	
		while (MyProperty)
		{
			//const FString& 和 UObject* 只能是CPF_Parm？
			if (MyProperty->PropertyFlags & CPF_ReturnParm)
			{//返回值只有输出
				CreatePinType(MyProperty, EGPD_Output);
			}
			else if (MyProperty->PropertyFlags & CPF_ReferenceParm)
			{//引用具有输入和输出，既是CPF_OutParm又是CPF_Parm
				CreatePinType(MyProperty, EGPD_Input);
				CreatePinType(MyProperty, EGPD_Output);
			}
			else
			{
				if (MyProperty->PropertyFlags & CPF_OutParm)
				{
					CreatePinType(MyProperty, EGPD_Output);
				}

				if (MyProperty->PropertyFlags & CPF_Parm)
				{
					CreatePinType(MyProperty, EGPD_Input);
				}
			}

			MyProperty = CastField<FProperty>(MyProperty->Next);
		}
		
	}
	else if (!Property.IsPathToFieldEmpty())
	{
		CreatePinType(Property.Get(), EGPD_Input);
		CreatePinType(Property.Get(), EGPD_Output);
	}
}

FText UK3Node::GetNodeTitle(ENodeTitleType::Type TitleType) const
{
	GetNodeTitlePrivate(const_cast<UK3Node*>(this));
	return NodeTitle;
}

void UK3Node::CreatePinType(FProperty* InProperty, EEdGraphPinDirection PinDir)
{
	check(InProperty)
	const FMappingTable* MappingTable = FMappingTable::Get();
	const FName* Category = MappingTable->GetCategory(InProperty->GetClass()->GetDefaultObject());

	if(Category)
	{
		CreatePin(PinDir, MappingTable->GetRealCategory(*Category), MappingTable->GetSubCategory(*Category), MappingTable->GetSubCategoryObject(InProperty), 
			InProperty->GetFName(), FCreatePinParams());
	}
	else
	{
		CreatePin(PinDir, FPC_Public::PC_Default, FName(), InProperty->GetFName());
	}

}

bool UK3Node::IsPure()
{
	if (!IsFunction())
	{
		return false;
	}

	for(UEdGraphPin* Pin : Pins)
	{
		if (Pin->PinType.PinCategory == FPC_Public::PC_Exec)
		{
			return false;
		}
	}
	return true;
}


#pragma optimize("", on)