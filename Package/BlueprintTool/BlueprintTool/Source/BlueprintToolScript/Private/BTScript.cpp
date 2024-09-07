#include "BTScript.h"
#include "ScriptObject.h"
#include "UObject\UnrealType.h"

#if PLATFORM_WINDOWS
#pragma optimize("", off)
#endif // PLATFORM_WINDOWS

TSharedPtr<FTemporaryHeapManage> FTemporaryHeapManage::HeapManage = nullptr;

TSharedPtr<FTemporaryHeapManage> FTemporaryHeapManage::Get()
{
	if (!HeapManage.IsValid())
	{
		HeapManage = MakeShareable(new FTemporaryHeapManage);
		HeapManage->ExternalParam = MakeShareable(new FExternalParamManage);
	}
	return HeapManage;
}

void FTemporaryHeapManage::AddHeap(FGuid Id, TSharedPtr<uint8> Addr)
{
	if (Id.IsValid())
	{
		TSharedPtr<FSharedPtrMemory> Temp = SharedPtrMemory;
		if (Temp.IsValid())
		{
			while (Temp->Next.IsValid())
			{
				Temp = StaticCastSharedPtr<FSharedPtrMemory>(Temp->Next);
			}
			Temp->Next = MakeShareable(new FSharedPtrMemory(Addr, Id));
		}
		else
		{
			SharedPtrMemory = MakeShareable(new FSharedPtrMemory(Addr, Id));
		}
	}
}

void FTemporaryHeapManage::AddHeapPtr(FGuid Id, uint8* Addr)
{
	if (Id.IsValid())
	{
		TSharedPtr<FNoDeleteMemory> Temp = NoDeleteMemory;
		if (Temp.IsValid())
		{
			while (Temp->Next.IsValid())
			{
				Temp = StaticCastSharedPtr<FNoDeleteMemory>(Temp->Next);
			}
			Temp->Next = MakeShareable(new FNoDeleteMemory(Addr, Id));
		}
		else
		{
			NoDeleteMemory = MakeShareable(new FNoDeleteMemory(Addr, Id));
		}
	}
}

void FTemporaryHeapManage::FindHeap(FGuid Id, TSharedPtr<uint8>& Addr)
{
	TSharedPtr<FSharedPtrMemory> TargetNode = SharedPtrMemory;
	while (TargetNode.IsValid())
	{
		if (TargetNode->Id == Id)
		{
			Addr = TargetNode->Addr;
			return;
		}
		TargetNode = StaticCastSharedPtr<FSharedPtrMemory>(TargetNode->Next);
	}
}

void FTemporaryHeapManage::FindHeapPtr(FGuid Id, uint8* & Addr)
{
	TSharedPtr<FNoDeleteMemory> TargetNode = NoDeleteMemory;
	while (TargetNode.IsValid())
	{
		if (TargetNode->Id == Id)
		{
			Addr = TargetNode->Addr;
			return;
		}
		TargetNode = StaticCastSharedPtr<FNoDeleteMemory>(TargetNode->Next);
	}
}

void FTemporaryHeapManage::Destory()
{
	if(HeapManage.IsValid())
	{
		HeapManage.Reset();
	}
}

void FTemporaryStackManage::AddStack(TSharedPtr<uint8> Addr)
{
	TSharedPtr<FSharedPtrData> Temp = SharedPtrData;
	if (Temp.IsValid())
	{
		while (Temp->Next.IsValid())
		{
			Temp = StaticCastSharedPtr<FSharedPtrData>(Temp->Next);
		}
		Temp->Next = MakeShareable(new FSharedPtrData(Addr));
	}
	else
	{
		SharedPtrData = MakeShareable(new FSharedPtrData(Addr));
	}
}

void FTemporaryStackManage::AddStackPtr(uint8* Addr)
{
	TSharedPtr<FNoDeleteData> Temp = NoDeleteData;
	if (Temp.IsValid())
	{
		while (Temp->Next.IsValid())
		{
			Temp = StaticCastSharedPtr<FNoDeleteData>(Temp->Next);
		}
		Temp->Next = MakeShareable(new FNoDeleteData(Addr));
	}
	else
	{
		NoDeleteData = MakeShareable(new FNoDeleteData(Addr));
	}
}

FNativeBTFuncPtr GBTNatives[VMC_Max];

//将命令注册
uint8 BTRegisterNative(int32 NativeByteCodeIndex, const FNativeBTFuncPtr FuncPtr)
{
	static bool bInitialized = false;
	if (!bInitialized)
	{
		//将数组全初始化为VMC_Undefined
		for (int32 I = 0; I < UE_ARRAY_COUNT(GBTNatives); I++)
		{
			GBTNatives[I] = &UBTScriptObject::VMC_Undefined;
		}
		bInitialized = true;
	}

	if (NativeByteCodeIndex != INDEX_NONE)
	{
		//初始化VM命令函数
		if (!(NativeByteCodeIndex < 0 || (uint32)NativeByteCodeIndex > UE_ARRAY_COUNT(GBTNatives)
			|| GBTNatives[NativeByteCodeIndex] != &UBTScriptObject::VMC_Undefined))
		{
			CA_SUPPRESS(6386);
			GBTNatives[NativeByteCodeIndex] = FuncPtr;
		}
	}

	GBTNatives[NativeByteCodeIndex] = FuncPtr;
	return NativeByteCodeIndex;
}

TMap<UFunction*, uint8*> FBTFrame::ScriptBufferPos{};

FBTFrame::FBTFrame(UFunction* NewFunction)
	: Code(NewFunction->Script.GetData())
	, StackManage(MakeShareable(new FTemporaryStackManage))
	, Param(nullptr)	
{

}

void FBTFrame::LoadCodePos(UFunction* InFunction)
{
	if (ScriptBufferPos.Contains(InFunction))
	{
		Code = ScriptBufferPos[InFunction];
	}
}

void FBTFrame::SaveCodePos(UFunction* InFunction)
{
	if (ScriptBufferPos.Contains(InFunction))
	{
		ScriptBufferPos[InFunction] = Code;
	}
	else
	{
		ScriptBufferPos.Add(InFunction, Code);
	}
}

void FBTFrame::AddParam(FProperty* Addr)
{
	TSharedPtr<FBTParam> ListParam = Param;
	if (!ListParam.IsValid())
	{
		Param = MakeShareable(new FBTParam);
		Param->PropAddr = Addr;
	}
	else
	{
		while (ListParam->Next.IsValid())
		{
			ListParam = ListParam->Next;
		}
		ListParam->Next = MakeShareable(new FBTParam);
		ListParam->Next->PropAddr = Addr;
	}
}

void FBTFrame::Step(UObject* Context, void const* RefData)
{
	int32 Byte = *Code++;
	//执行脚本函数
	(GBTNatives[Byte])(Context, *this, RefData);
}

uint8* FBTFrame::GetParamAddr()
{ 
	FProperty* Prop = (FProperty*)Param->PropAddr;
	Param = Param->Next;

	UPropertyWrapper* Wrapper  = NewObject<UPropertyWrapper>();

	Wrapper->SetProperty(Prop);

	uint8* LocalResult = nullptr;
	
	Step(Wrapper, &LocalResult);//由脚本决定是堆内存还是栈内存

	return LocalResult;
}

FName FBTFrame::ReadName()
{	
	uint32 DisplayIndex = ReadNumericType<uint32>();
	uint32 ComparisonIndex = ReadNumericType<uint32>();
	int32 Number = ReadNumericType<int32>();
	
	FName Result = FName(FNameEntryId::FromUnstableInt(ComparisonIndex), FNameEntryId::FromUnstableInt(DisplayIndex), Number);;
	return Result;
}

void FExternalParamManage::AddExternalParam(void const* Addr, FGuid Id)
{
	TSharedPtr<FExternalParamStore> ListParam = Head;

	if (ListParam.IsValid())
	{
		while (ListParam->Next.IsValid())
		{
			ListParam = ListParam->Next;
		}
		ListParam->Next = MakeShareable(new FExternalParamStore);
		ListParam->Next->Addr = Addr;
		ListParam->Next->Id = Id;
	}
	else
	{
		Head = MakeShareable(new FExternalParamStore);
		Head->Addr = Addr;
		Head->Id = Id;
	}
}

void const* FExternalParamManage::FindExternalParam(FGuid Id)
{
	TSharedPtr<FExternalParamStore> ListParam = Head;

	while (ListParam.IsValid())
	{
		if (ListParam->Id == Id)
		{
			return ListParam->Addr;
		}
		ListParam = ListParam->Next;
	}

	return nullptr;
}

#if PLATFORM_WINDOWS
#pragma optimize("", on)
#endif // PLATFORM_WINDOWS

