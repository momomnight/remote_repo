#include "FunctionManage.h"

#if PLATFORM_WINDOWS
#pragma optimize("", off)
#endif

namespace BTMsg
{
    void Error(UObject* Context, FBTFrame& Stack, void const* RefData)
    {
        check(0);
    }
    void Nop(UObject* Context, FBTFrame& Stack, void const* RefData)
    {
    }
}

FNativeBTFuncPtr ErrorFunction = &BTMsg::Error;
FNativeBTFuncPtr NopFunction = &BTMsg::Nop;

TArray<FBTFunctionId> FFunctionManage::ReflectionFuncPtrList;

FNativeBTFuncPtr FFunctionManage::GetNativeFuncPtr(UFunction* Function)
{
    if (Function)
    {
        for (auto& FuncId : ReflectionFuncPtrList)
        {
            if ((Function->GetFName() == FuncId.FunctionName) &&
                (Function->GetOuter()->GetFName() == FuncId.ClassName))
            {
                return FuncId.NativeFuncPtr;
            }
        }
    }
    return NopFunction;
}

int32 FFunctionManage::SetNativeFuncPtr(const FBTFunctionId& Function)
{
    ReflectionFuncPtrList.Add(Function);
    return 0;
}

void AddParam(void const* ParamAddr, TSharedPtr<FFunctionParameter>& FunctionParameter)
{
    TSharedPtr<FFunctionParameter> Temp = FunctionParameter;
    if (Temp.IsValid())
    {
        while (Temp->Next.IsValid())
        {
            Temp = Temp->Next;
        }
        Temp->Next = MakeShareable(new FFunctionParameter(ParamAddr));
    }
    else
    {
        FunctionParameter = MakeShareable(new FFunctionParameter(ParamAddr));
    }
}

void const* GetParam(TSharedPtr<FFunctionParameter>& FunctionParameter)
{
    if (FunctionParameter.IsValid())
    {
        void const* Return = FunctionParameter->Addr;
        FunctionParameter = FunctionParameter->Next;
        return Return;
    }
    return nullptr;
}

#if PLATFORM_WINDOWS
#pragma optimize("", on)
#endif