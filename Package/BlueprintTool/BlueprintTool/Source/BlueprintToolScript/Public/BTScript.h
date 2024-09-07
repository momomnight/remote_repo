#pragma once


#include "CoreMinimal.h"

enum EVMCommand
{
	VMC_Undefined			= 0x0B,

	VMC_Int32				= 0x1D,
	VMC_Int64				= 0x1E,
	VMC_Float				= 0x1F,
	VMC_Double				= 0x20,

	VMC_String				= 0x21,
	VMC_Object				= 0x22,
	VMC_Name				= 0x23,
	VMC_Rotation			= 0x24,
	VMC_LinearColor			= 0x25,

	VMC_Vector				= 0x27,
	VMC_Byte				= 0x28,
	VMC_True				= 0x29,
	VMC_False				= 0x2A,

	VMC_Text				= 0x2B,
	VMC_NullObject			= 0x2C,
	VMC_Transform			= 0x2D,

	VMC_EndThread			= 0x53,
	VMC_ExternalParam		= 0x72,
	VMC_Function			= 0x74,

	VMC_PureText			= 0x75,
	VMC_SaveValue			= 0x76,
	VMC_LoadValue			= 0x77,	
	VMC_LoadAndSaveValue	= 0x78,

	VMC_ReturnParam			= 0x82, 
	VMC_NoReturnParam		= 0x83,

	VMC_Max					= 0x100
};

//存储入口事件的所传入的参数
class FExternalParamStore : public TSharedFromThis<FExternalParamStore>
{
public:
	FExternalParamStore() : Addr(nullptr), Next(nullptr) {}
	void const* Addr;
	FGuid Id;
	TSharedPtr<FExternalParamStore> Next;
};

class FExternalParamManage
{
public:
	FExternalParamManage() : Head(nullptr) {}

	void AddExternalParam(void const* Addr, FGuid Id);
	void const* FindExternalParam(FGuid Id);
private:
	TSharedPtr<FExternalParamStore> Head;
};


struct FList : public TSharedFromThis<FList>
{
	FList() : Next(nullptr){};
	TSharedPtr<FList> Next;
};

struct FSharedPtrData : public FList
{
	FSharedPtrData(TSharedPtr<uint8> InAddr) : FList(), Addr(InAddr){}
	TSharedPtr<uint8> Addr = nullptr;
};

struct FNoDeleteData : public FList
{
	FNoDeleteData(uint8* InAddr) : FList(), Addr(InAddr) {}
	uint8* Addr = nullptr;
};


struct FSharedPtrMemory : public FSharedPtrData
{
	FSharedPtrMemory(TSharedPtr<uint8> InAddr, FGuid InId) : FSharedPtrData(InAddr), Id(InId){}
	FGuid Id;
};

struct FNoDeleteMemory : public FNoDeleteData
{
	
	FNoDeleteMemory(uint8* InAddr, FGuid Guid) : FNoDeleteData(InAddr), Id(Guid){}
	FGuid Id;
};

class FTemporaryHeapManage
{
public:
	static TSharedPtr<FTemporaryHeapManage> Get();

	static void Destory();

	FTemporaryHeapManage() :ExternalParam(nullptr), SharedPtrMemory(nullptr), NoDeleteMemory(nullptr){ }

	void AddHeap(FGuid Id, TSharedPtr<uint8> Addr);
	void AddHeapPtr(FGuid Id, uint8* Addr);
	void FindHeap(FGuid Id, TSharedPtr<uint8>& Addr);
	void FindHeapPtr(FGuid Id, uint8* & Addr);

	static TSharedPtr<FTemporaryHeapManage> HeapManage;
	TSharedPtr<FExternalParamManage> ExternalParam;
private:
	TSharedPtr<FSharedPtrMemory> SharedPtrMemory;
	TSharedPtr<FNoDeleteMemory> NoDeleteMemory;
};

class FTemporaryStackManage
{
public:
	FTemporaryStackManage() : SharedPtrData(nullptr), NoDeleteData(nullptr) {}

	void AddStack(TSharedPtr<uint8> Addr);
	void AddStackPtr(uint8* Addr);
private:
	TSharedPtr<FSharedPtrData> SharedPtrData;
	TSharedPtr<FNoDeleteData> NoDeleteData;
};


//按顺序加入参数的属性
class FBTParam : public TSharedFromThis<FBTParam>
{
public:
	void* PropAddr;
	TSharedPtr<FBTParam> Next;
};

//虚拟机执行框架
struct FBTFrame
{
	FBTFrame(UFunction* NewFunction);
	~FBTFrame(){if(StackManage.IsValid()){ StackManage.Reset();}}

	//存储每个UFunction对应的执行位置
	//可能是多个节点对应一个UFunction,但参数不同
	void LoadCodePos(UFunction* Function);
	void SaveCodePos(UFunction* Function);

	void AddParam(FProperty* Addr);
	BLUEPRINTTOOLSCRIPT_API uint8* GetParamAddr();

	BLUEPRINTTOOLSCRIPT_API void Step(UObject* Context, void const* RefData);
	
	template<typename NumbericType>
	NumbericType ReadNumericType()
	{
		NumbericType Result = *(NumbericType*)Code;
		Code += sizeof(NumbericType);
		return Result;
	}
	template<typename PtrType>
	PtrType* ReadPtr()
	{
		int64 TempCode = *(int64*)Code;
		PtrType* Result = (PtrType*)TempCode;	
		Code += sizeof(int64);
		return Result;
	}
	FName ReadName();

public:
	uint8* Code;

	//Code所指向的区域可能是同一个Function
	static TMap<UFunction*, uint8*> ScriptBufferPos;

public:
	//随着FBTFrame创建而创建，随着FBTFrame消失而消失
	TSharedPtr<FTemporaryStackManage> StackManage;
private:
	TSharedPtr<FBTParam> Param;
};

typedef void(*FNativeBTFuncPtr)(UObject* Context, FBTFrame& Stack, void const* RefData);
uint8 BTRegisterNative(int32 NativeByteCodeIndex, const FNativeBTFuncPtr FuncPtr);
extern FNativeBTFuncPtr GBTNatives[VMC_Max];