
#include "ScriptObject.h"
#include "BTScript.h"
#include "FunctionManage.h"

#if PLATFORM_WINDOWS
#pragma optimize("", off)
#endif // PLATFORM_WINDOWS

TSet<UFunction*> UBTScriptObject::RegisteredFunctionList{};

//入口事件，可能传进参数
void UBTScriptObject::ExecuteScript(UFunction* Function, void const* Data)
{
    check(Function);
    if (Function->Script.Num() == 0)
    {
        return;
    }

    FBTFrame Stack(Function);

    Stack.Step(Function, Data);

    FBTFrame::ScriptBufferPos.Empty();
}

UFunction* UBTScriptObject::FindScriptFunction(FName FuncName)
{
    UFunction* NewFunction = nullptr;

    for (auto Func : RegisteredFunctionList)
    {
        if (Func->GetFName() == FuncName)
        {
            NewFunction = Func;
            break;
        }
    }
    return NewFunction;
}

void UBTScriptObject::CallBTFunction(void const* RefData, UFunction* Function)
{
    FBTFrame Stack(Function);
    Stack.LoadCodePos(Function);
    FProperty* ReturnProp = nullptr;
    for (TFieldIterator<FProperty> Iter(Function); Iter; ++Iter)
    {   //拿到参数与返回值
        FProperty* Prop = *Iter;
        if (Prop)
        {
            if (Prop->PropertyFlags & CPF_ReturnParm)
            {
                ReturnProp = Prop;
            }       
            else
            {
                Stack.AddParam(Prop);
            }
        }
    }

    uint8* Data = nullptr;
    if (ReturnProp)
    {
        UPropertyWrapper* Wrapper = NewObject<UPropertyWrapper>();
        Wrapper->SetProperty(ReturnProp);
        Stack.Step(Wrapper, &Data);
    }

    //执行本地C++函数
    FFunctionManage::GetNativeFuncPtr(Function)(nullptr, Stack, Data);

    Stack.SaveCodePos(Function);
}

BT_VM_Func_Definition(UBTScriptObject, VMC_Undefined)           
{

}
Add_VM_Function(VMC_Undefined);


BT_VM_Func_Definition(UBTScriptObject, VMC_Int32)         
{
    *(int32*)RefData = Stack.ReadNumericType<int32>();
}
Add_VM_Function(VMC_Int32);


BT_VM_Func_Definition(UBTScriptObject, VMC_Int64)
{
    *(int64*)RefData = Stack.ReadNumericType<int64>();
}
Add_VM_Function(VMC_Int64);


BT_VM_Func_Definition(UBTScriptObject, VMC_Float)          
{
    *(float*)RefData = Stack.ReadNumericType<float>();
}
Add_VM_Function(VMC_Float);


BT_VM_Func_Definition(UBTScriptObject, VMC_Double)
{
    *(double*)RefData = Stack.ReadNumericType<double>();
}
Add_VM_Function(VMC_Double);


BT_VM_Func_Definition(UBTScriptObject, VMC_String)     
{
    *(FString*)RefData = (ANSICHAR*)Stack.Code;
    while (*Stack.Code)//最后一位\0
    {
        Stack.Code++;
    }
    Stack.Code++;
}
Add_VM_Function(VMC_String);


BT_VM_Func_Definition(UBTScriptObject, VMC_Object)     
{
   *(UObject**)RefData = Stack.ReadPtr<UObject>();
}
Add_VM_Function(VMC_Object);


BT_VM_Func_Definition(UBTScriptObject, VMC_Name)        
{
    *(FName*)RefData = Stack.ReadName();
}
Add_VM_Function(VMC_Name);


BT_VM_Func_Definition(UBTScriptObject, VMC_Rotation)   
{
    FRotator& Rotator = *(FRotator*)RefData;
    Rotator.Roll = Stack.ReadNumericType<double>();
    Rotator.Pitch = Stack.ReadNumericType<double>();
    Rotator.Yaw = Stack.ReadNumericType<double>();
}
Add_VM_Function(VMC_Rotation);

BT_VM_Func_Definition(UBTScriptObject, VMC_LinearColor)
{
    FLinearColor& Color = *(FLinearColor*)RefData;
    Color.R = Stack.ReadNumericType<float>();
    Color.G = Stack.ReadNumericType<float>();
    Color.B = Stack.ReadNumericType<float>();
    Color.A = Stack.ReadNumericType<float>();
}
Add_VM_Function(VMC_LinearColor);

BT_VM_Func_Definition(UBTScriptObject, VMC_Vector)   
{
    FVector& Vector = *(FVector*)RefData;

    Vector.X = Stack.ReadNumericType<double>();
    Vector.Y = Stack.ReadNumericType<double>();
    Vector.Z = Stack.ReadNumericType<double>();
}
Add_VM_Function(VMC_Vector);


BT_VM_Func_Definition(UBTScriptObject, VMC_Byte)   
{
    *(uint8*)RefData = *Stack.Code++;
}
Add_VM_Function(VMC_Byte);


BT_VM_Func_Definition(UBTScriptObject, VMC_True)        
{
    *(bool*)RefData = true;
}
Add_VM_Function(VMC_True);


BT_VM_Func_Definition(UBTScriptObject, VMC_False)      
{
    *(bool*)RefData = false;
}
Add_VM_Function(VMC_False);


BT_VM_Func_Definition(UBTScriptObject, VMC_Text)  
{
    const EBlueprintTextLiteralType TextLiteralType = (EBlueprintTextLiteralType)*Stack.Code++;

    switch (TextLiteralType)
    {
        case EBlueprintTextLiteralType::Empty:
        {
            *(FText*)RefData = FText::GetEmpty();
            break;
        }
        case EBlueprintTextLiteralType::LocalizedText:
        {
            FString NamespaceStr;
            Stack.Step(nullptr, &NamespaceStr);
            FString KeyStr;
            Stack.Step(nullptr, &KeyStr);
            FString SourceStr;
            Stack.Step(nullptr, &SourceStr);
            
            *(FText*)RefData = FInternationalization::ForUseOnlyByLocMacroAndGraphNodeTextLiterals_CreateText(*SourceStr, *NamespaceStr, *KeyStr);
            break;
        }
        case EBlueprintTextLiteralType::InvariantText:
        {
            FString SourceStr;
            Stack.Step(nullptr, &SourceStr);
            *(FText*)RefData = FText::AsCultureInvariant(MoveTempIfPossible(SourceStr));
            break;
        }
        case EBlueprintTextLiteralType::LiteralString:
        {
            FString SourceStr;
            Stack.Step(nullptr, &SourceStr);
            *(FText*)RefData = FText::FromString(MoveTempIfPossible(SourceStr));
            break;
        }
        case EBlueprintTextLiteralType::StringTableEntry:
        {
            FString TableIdStr;
            Stack.Step(nullptr, &TableIdStr);

            FString KeyStr;
            Stack.Step(nullptr, &KeyStr);

            *(FText*)RefData = FText::FromStringTable(FName(TableIdStr), KeyStr);
            break;
        }
    default:
        break;
    }

}
Add_VM_Function(VMC_Text);


BT_VM_Func_Definition(UBTScriptObject, VMC_NullObject)    
{
    *(UObject**)RefData = nullptr;
}
Add_VM_Function(VMC_NullObject);


BT_VM_Func_Definition(UBTScriptObject, VMC_Transform)  
{
    FQuat Rotation;
    Rotation.X = Stack.ReadNumericType<double>();
    Rotation.Y = Stack.ReadNumericType<double>();
    Rotation.Z = Stack.ReadNumericType<double>();
    Rotation.W = Stack.ReadNumericType<double>();

    FVector Translation;
    Translation.X = Stack.ReadNumericType<double>();
    Translation.Y = Stack.ReadNumericType<double>();
    Translation.Z = Stack.ReadNumericType<double>();

    FVector Scale;
    Scale.X = Stack.ReadNumericType<double>();
    Scale.Y = Stack.ReadNumericType<double>();
    Scale.Z = Stack.ReadNumericType<double>();

    ((FTransform*)RefData)->SetComponents(Rotation, Translation, Scale);
}
Add_VM_Function(VMC_Transform);


BT_VM_Func_Definition(UBTScriptObject, VMC_EndThread)  
{
    FTemporaryHeapManage::Destory();
}
Add_VM_Function(VMC_EndThread);

//VMC_ExternalParam

BT_VM_Func_Definition(UBTScriptObject, VMC_ExternalParam)
{
    TSharedPtr<FFunctionParameter>& ExternalParam = *(TSharedPtr<FFunctionParameter>*)RefData;
    UFunction* Function = Cast<UFunction>(Context);

    while (void const* Data = GetParam(ExternalParam))
    {
        FGuid Id = Stack.ReadNumericType<FGuid>();
        FTemporaryHeapManage::Get()->ExternalParam->AddExternalParam(Data, Id);
    }
    Stack.Step(nullptr, nullptr);
}
Add_VM_Function(VMC_ExternalParam);

// VMC_Function
//  UFunction
// VMC_ReturnParam
//     Size
//返回值在CallBTFunction中处理
BT_VM_Func_Definition(UBTScriptObject, VMC_Function)
{

    UFunction* FuncPtr = Stack.ReadPtr<UFunction>();   

    UBTScriptObject::CallBTFunction(nullptr, FuncPtr);

    //执行下一步, 是函数，则Context无用，是属性，则用于参数操作
    Stack.Step(Context, RefData);
}
Add_VM_Function(VMC_Function);

// VMC_SaveValue
//  FGuid
// VMC_Int32
//    1
BT_VM_Func_Definition(UBTScriptObject,VMC_SaveValue)
{
    FProperty* Prop = Cast<UPropertyWrapper>(Context)->GetProperty();
    uint8*& Data = *(uint8**)RefData;
    Data = new uint8[Prop->GetSize()];
    Prop->InitializeValue(Data);

    //取值
    FGuid Id = Stack.ReadNumericType<FGuid>();
    Stack.Step(nullptr, Data);
    FTemporaryHeapManage::Get()->AddHeap(Id, MakeShareable(Data));
}
Add_VM_Function(VMC_SaveValue);

// VMC_LoadValue
//  FGuid
BT_VM_Func_Definition(UBTScriptObject, VMC_LoadValue)
{
    uint8* & Data = *(uint8**)RefData;  
    FGuid Id = Stack.ReadNumericType<FGuid>();

    //先在外部参数中找
    Data = (uint8*)FTemporaryHeapManage::Get()->ExternalParam->FindExternalParam(Id);

    if (!Data)
    {
        FTemporaryHeapManage::Get()->FindHeapPtr(Id, Data);
        if (!Data)
        {
            TSharedPtr<uint8> Temp = nullptr;
            FTemporaryHeapManage::Get()->FindHeap(Id, Temp);
            Data = Temp.Get();
        }
    }
}
Add_VM_Function(VMC_LoadValue);

// VMC_PureText
//  VMC_String
//    Hello
BT_VM_Func_Definition(UBTScriptObject,VMC_PureText)
{
    FProperty* Prop = Cast<UPropertyWrapper>(Context)->GetProperty();
    uint8*& Data = *(uint8**)RefData;
    Data = new uint8[Prop->GetSize()];
    Prop->InitializeValue(Data);

    Stack.Step(nullptr, Data);
    Stack.StackManage->AddStack(MakeShareable(Data));
}
Add_VM_Function(VMC_PureText);

// VMC_LoadAndSaveValue
//      FGuid
//      FGuid
BT_VM_Func_Definition(UBTScriptObject, VMC_LoadAndSaveValue)
{
    uint8*& Data = *(uint8**)RefData;
    FGuid InputId = Stack.ReadNumericType<FGuid>();
    FGuid OutputId = Stack.ReadNumericType<FGuid>();
    Data = (uint8*)FTemporaryHeapManage::Get()->ExternalParam->FindExternalParam(InputId);
    if (Data)
    {
        FTemporaryHeapManage::Get()->AddHeapPtr(OutputId, Data);  
    }
    else
    {
        FTemporaryHeapManage::Get()->FindHeapPtr(InputId, Data);
        if (Data)
        {
            FTemporaryHeapManage::Get()->AddHeapPtr(OutputId, Data);
        }
        else
        {
            TSharedPtr<uint8> Temp = nullptr;
            FTemporaryHeapManage::Get()->FindHeap(InputId, Temp);
            Data = Temp.Get();
            FTemporaryHeapManage::Get()->AddHeap(OutputId, Temp);
        }
       
    }
    //两个Id共用数据

}
Add_VM_Function(VMC_LoadAndSaveValue);

// VMC_ReturnParam
//      FGuid
// 由VMC_Function执行
BT_VM_Func_Definition(UBTScriptObject, VMC_ReturnParam)    
{
    FProperty* Property = Cast<UPropertyWrapper>(Context)->GetProperty();
    uint8*& Data = *(uint8**)RefData;
    FGuid Id = Stack.ReadNumericType<FGuid>();
    Data = new uint8[Property->GetSize()];
    Property->InitializeValue(Data);
    FTemporaryHeapManage::Get()->AddHeap(Id, MakeShareable(Data));
}
Add_VM_Function(VMC_ReturnParam);

// 由VMC_Function执行
BT_VM_Func_Definition(UBTScriptObject, VMC_NoReturnParam)
{
    FProperty* Property = Cast<UPropertyWrapper>(Context)->GetProperty();
    uint8*& Data = *(uint8**)RefData;
    Data = new uint8[Property->GetSize()];
    Property->InitializeValue(Data);
    //防止越界
    Stack.StackManage->AddStack(MakeShareable(Data));
}
Add_VM_Function(VMC_NoReturnParam);


#if PLATFORM_WINDOWS
#pragma optimize("", on)
#endif // PLATFORM_WINDOWS
