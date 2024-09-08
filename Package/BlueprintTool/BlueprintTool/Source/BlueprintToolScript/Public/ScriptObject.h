#pragma once

#include "CoreMinimal.h"
#include "ScriptMacro.h"
#include "ScriptObject.generated.h"

UCLASS()
class BLUEPRINTTOOLSCRIPT_API UBTScriptObject : public UObject
{
	GENERATED_BODY()

	friend struct FBTCompilationUtilities;
public:
	static void ExecuteScript(UFunction* Function, void const* Data);
	static void CallBTFunction(void const* RefData, UFunction* Function);
	static UFunction* FindScriptFunction(FName FuncName);

	BT_VM_Func_Declaration(VMC_Undefined);
	BT_VM_Func_Declaration(VMC_Int32);
	BT_VM_Func_Declaration(VMC_Int64);
	BT_VM_Func_Declaration(VMC_Float);
	BT_VM_Func_Declaration(VMC_Double);
	BT_VM_Func_Declaration(VMC_Object);
	BT_VM_Func_Declaration(VMC_Name);
	BT_VM_Func_Declaration(VMC_Rotation);
	BT_VM_Func_Declaration(VMC_LinearColor);
	BT_VM_Func_Declaration(VMC_Vector);
	BT_VM_Func_Declaration(VMC_Byte);
	BT_VM_Func_Declaration(VMC_True);
	BT_VM_Func_Declaration(VMC_False);
	BT_VM_Func_Declaration(VMC_Text);
	BT_VM_Func_Declaration(VMC_NullObject);
	BT_VM_Func_Declaration(VMC_Transform);
	BT_VM_Func_Declaration(VMC_EndThread);
	BT_VM_Func_Declaration(VMC_String);
	
	BT_VM_Func_Declaration(VMC_ExternalParam);
	BT_VM_Func_Declaration(VMC_Function);

	BT_VM_Func_Declaration(VMC_PureText);
	BT_VM_Func_Declaration(VMC_SaveValue);
	BT_VM_Func_Declaration(VMC_LoadValue);
	BT_VM_Func_Declaration(VMC_LoadAndSaveValue);

	BT_VM_Func_Declaration(VMC_ReturnParam);
	BT_VM_Func_Declaration(VMC_NoReturnParam);
	BT_VM_Func_Declaration(VMC_OneRefSave);
	BT_VM_Func_Declaration(VMC_TwoRefSave);
	
protected:
	static TSet<UFunction*> RegisteredFunctionList;
};
