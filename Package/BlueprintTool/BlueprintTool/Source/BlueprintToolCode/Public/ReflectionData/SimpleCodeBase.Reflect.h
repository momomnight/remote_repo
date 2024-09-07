#pragma once
 
#include "ScriptMacro.h"
#include "BTScript.h"
 
#define Z_BT_USimpleCodeBase \
BT_VM_Func_Declaration(VMC_PrintString) \
{ \
	FString Z_String_Name = *(FString*) Stack.GetParamAddr(); \
	USimpleCodeBase::PrintString(Z_String_Name); \
} \
BT_VM_Func_Declaration(VMC_SetString) \
{ \
	FString Z_Context_Name = *(FString*) Stack.GetParamAddr(); \
	*(FString*) RefData = USimpleCodeBase::SetString(Z_Context_Name); \
} \
BT_VM_Func_Declaration(VMC_SetBool) \
{ \
	bool Z_Context_Name = *(bool*) Stack.GetParamAddr(); \
	*(bool*) RefData = USimpleCodeBase::SetBool(Z_Context_Name); \
} \
BT_VM_Func_Declaration(VMC_SetFloat) \
{ \
	float Z_Context_Name = *(float*) Stack.GetParamAddr(); \
	*(float*) RefData = USimpleCodeBase::SetFloat(Z_Context_Name); \
} \
BT_VM_Func_Declaration(VMC_SetInt32) \
{ \
	int32 Z_Context_Name = *(int32*) Stack.GetParamAddr(); \
	*(int32*) RefData = USimpleCodeBase::SetInt32(Z_Context_Name); \
} \
BT_VM_Func_Declaration(VMC_SetText) \
{ \
	FText Z_Context_Name = *(FText*) Stack.GetParamAddr(); \
	*(FText*) RefData = USimpleCodeBase::SetText(Z_Context_Name); \
} \
BT_VM_Func_Declaration(VMC_SetName) \
{ \
	FName Z_Context_Name = *(FName*) Stack.GetParamAddr(); \
	*(FName*) RefData = USimpleCodeBase::SetName(Z_Context_Name); \
} \
BT_VM_Func_Declaration(VMC_SetColor) \
{ \
	FLinearColor Z_Context_Name = *(FLinearColor*) Stack.GetParamAddr(); \
	*(FLinearColor*) RefData = USimpleCodeBase::SetColor(Z_Context_Name); \
} \
BT_VM_Func_Declaration(VMC_SetByte) \
{ \
	uint8 Z_Context_Name = *(uint8*) Stack.GetParamAddr(); \
	*(uint8*) RefData = USimpleCodeBase::SetByte(Z_Context_Name); \
} \
BT_VM_Func_Declaration(VMC_SetObject) \
{ \
	UObject* Z_Context_Name = *(UObject**) Stack.GetParamAddr(); \
	*(UObject**) RefData = USimpleCodeBase::SetObject(Z_Context_Name); \
} 

#define BT_FileID_UEProject_TestSlate_EditorExtension_Plugins_BlueprintTool_Source_BlueprintToolCode_Public_SimpleCodeBase_h_14_GENERATED_BODY_BT \
Z_BT_USimpleCodeBase

#undef CURRENT_FILE_ID_BT
#define CURRENT_FILE_ID_BT BT_FileID_UEProject_TestSlate_EditorExtension_Plugins_BlueprintTool_Source_BlueprintToolCode_Public_SimpleCodeBase_h
#undef NEWLINE
#define NEWLINE 14
