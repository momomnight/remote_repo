#pragma once

#include "CoreMinimal.h"
#include "BTScript.h"


struct BLUEPRINTTOOLSCRIPT_API FBTFunctionId
{
	FName ClassName;
	FName FunctionName;
	FNativeBTFuncPtr NativeFuncPtr;
};

struct BLUEPRINTTOOLSCRIPT_API FFunctionManage
{
	static FNativeBTFuncPtr GetNativeFuncPtr(UFunction* Function);
	static int32 SetNativeFuncPtr(const FBTFunctionId& function);
private:
	static TArray<FBTFunctionId> ReflectionFuncPtrList;

};

//²»ÄÜdelete
class BLUEPRINTTOOLSCRIPT_API FFunctionParameter : public TSharedFromThis<FFunctionParameter>
{

public:
	FFunctionParameter(void const* InAddr) : Addr(InAddr){}

	void const* Addr;
	TSharedPtr<FFunctionParameter> Next;
};

BLUEPRINTTOOLSCRIPT_API void AddParam(void const* ParamAddr, TSharedPtr<FFunctionParameter>& FunctionParameter);
BLUEPRINTTOOLSCRIPT_API void const* GetParam(TSharedPtr<FFunctionParameter>& FunctionParameter);