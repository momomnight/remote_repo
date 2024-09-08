#pragma once
 
#include "ScriptMacro.h"
#include "BTScript.h"
 
#define Z_BT_USimpleCodeLibrary \
BT_VM_Func_Declaration(VMC_SetLocation) \
{ \
	UStaticMeshComponent* Z_MeshComponent_Name = *(UStaticMeshComponent**) Stack.GetParamAddr(); \
	FVector Z_InLocation_Name = *(FVector*) Stack.GetParamAddr(); \
	USimpleCodeLibrary::SetLocation(Z_MeshComponent_Name, Z_InLocation_Name); \
} \
BT_VM_Func_Declaration(VMC_SetRotation) \
{ \
	UStaticMeshComponent* Z_MeshComponent_Name = *(UStaticMeshComponent**) Stack.GetParamAddr(); \
	FRotator Z_InRotation_Name = *(FRotator*) Stack.GetParamAddr(); \
	USimpleCodeLibrary::SetRotation(Z_MeshComponent_Name, Z_InRotation_Name); \
} \
BT_VM_Func_Declaration(VMC_SetMesh) \
{ \
	UStaticMeshComponent* Z_MeshComponent_Name = *(UStaticMeshComponent**) Stack.GetParamAddr(); \
	UStaticMesh* Z_InMesh_Name = *(UStaticMesh**) Stack.GetParamAddr(); \
	USimpleCodeLibrary::SetMesh(Z_MeshComponent_Name, Z_InMesh_Name); \
} \
BT_VM_Func_Declaration(VMC_SetMaterial) \
{ \
	UStaticMeshComponent* Z_MeshComponent_Name = *(UStaticMeshComponent**) Stack.GetParamAddr(); \
	int32 Z_Index_Name = *(int32*) Stack.GetParamAddr(); \
	UMaterialInterface* Z_InMaterial_Name = *(UMaterialInterface**) Stack.GetParamAddr(); \
	USimpleCodeLibrary::SetMaterial(Z_MeshComponent_Name, Z_Index_Name, Z_InMaterial_Name); \
} \
BT_VM_Func_Declaration(VMC_SetMaterialColor) \
{ \
	UStaticMeshComponent* Z_MeshComponent_Name = *(UStaticMeshComponent**) Stack.GetParamAddr(); \
	FName Z_ColorName_Name = *(FName*) Stack.GetParamAddr(); \
	FLinearColor Z_Color_Name = *(FLinearColor*) Stack.GetParamAddr(); \
	int32 Z_MaterialIndex_Name = *(int32*) Stack.GetParamAddr(); \
	USimpleCodeLibrary::SetMaterialColor(Z_MeshComponent_Name, Z_ColorName_Name, Z_Color_Name, Z_MaterialIndex_Name); \
} 

#define BT_FileID_UEProject_TestSlate_EditorExtension_Plugins_BlueprintTool_Source_BlueprintToolCode_Public_SimpleCodeLibrary_h_12_GENERATED_BODY_BT \
Z_BT_USimpleCodeLibrary

#undef CURRENT_FILE_ID_BT
#define CURRENT_FILE_ID_BT BT_FileID_UEProject_TestSlate_EditorExtension_Plugins_BlueprintTool_Source_BlueprintToolCode_Public_SimpleCodeLibrary_h
#undef NEWLINE
#define NEWLINE 12
