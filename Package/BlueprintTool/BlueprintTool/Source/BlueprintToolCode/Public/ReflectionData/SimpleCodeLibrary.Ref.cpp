// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "SimpleCodeLibrary.h"
#include "FunctionManage.h"
#include "UObject/GeneratedCppIncludes.h"

#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif

PRAGMA_DISABLE_DEPRECATION_WARNINGS

/* As an executable function pointer for global registration, we skip the UE
   UFunction local function registration because there is no bytecode in it.*/
uint8 Register_USimpleCodeLibrary()
{
	FFunctionManage::SetNativeFuncPtr(FBTFunctionId(TEXT("SimpleCodeLibrary"), TEXT("SetLocation"), USimpleCodeLibrary::VMC_SetLocation));
	FFunctionManage::SetNativeFuncPtr(FBTFunctionId(TEXT("SimpleCodeLibrary"), TEXT("SetRotation"), USimpleCodeLibrary::VMC_SetRotation));
	FFunctionManage::SetNativeFuncPtr(FBTFunctionId(TEXT("SimpleCodeLibrary"), TEXT("SetMesh"), USimpleCodeLibrary::VMC_SetMesh));
	FFunctionManage::SetNativeFuncPtr(FBTFunctionId(TEXT("SimpleCodeLibrary"), TEXT("SetMaterial"), USimpleCodeLibrary::VMC_SetMaterial));
	FFunctionManage::SetNativeFuncPtr(FBTFunctionId(TEXT("SimpleCodeLibrary"), TEXT("SetMaterialColor"), USimpleCodeLibrary::VMC_SetMaterialColor));

	return 0;
}
static uint8 USimpleCodeLibrary_Index = Register_USimpleCodeLibrary();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning(pop)
#endif
