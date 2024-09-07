// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "SimpleCodeBase.h"
#include "FunctionManage.h"
#include "UObject/GeneratedCppIncludes.h"

#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif

PRAGMA_DISABLE_DEPRECATION_WARNINGS

/* As an executable function pointer for global registration, we skip the UE
   UFunction local function registration because there is no bytecode in it.*/
uint8 Register_USimpleCodeBase()
{
	FFunctionManage::SetNativeFuncPtr(FBTFunctionId(TEXT("SimpleCodeBase"), TEXT("PrintString"), USimpleCodeBase::VMC_PrintString));
	FFunctionManage::SetNativeFuncPtr(FBTFunctionId(TEXT("SimpleCodeBase"), TEXT("SetString"), USimpleCodeBase::VMC_SetString));
	FFunctionManage::SetNativeFuncPtr(FBTFunctionId(TEXT("SimpleCodeBase"), TEXT("SetBool"), USimpleCodeBase::VMC_SetBool));
	FFunctionManage::SetNativeFuncPtr(FBTFunctionId(TEXT("SimpleCodeBase"), TEXT("SetFloat"), USimpleCodeBase::VMC_SetFloat));
	FFunctionManage::SetNativeFuncPtr(FBTFunctionId(TEXT("SimpleCodeBase"), TEXT("SetInt32"), USimpleCodeBase::VMC_SetInt32));
	FFunctionManage::SetNativeFuncPtr(FBTFunctionId(TEXT("SimpleCodeBase"), TEXT("SetText"), USimpleCodeBase::VMC_SetText));
	FFunctionManage::SetNativeFuncPtr(FBTFunctionId(TEXT("SimpleCodeBase"), TEXT("SetName"), USimpleCodeBase::VMC_SetName));
	FFunctionManage::SetNativeFuncPtr(FBTFunctionId(TEXT("SimpleCodeBase"), TEXT("SetColor"), USimpleCodeBase::VMC_SetColor));
	FFunctionManage::SetNativeFuncPtr(FBTFunctionId(TEXT("SimpleCodeBase"), TEXT("SetByte"), USimpleCodeBase::VMC_SetByte));
	FFunctionManage::SetNativeFuncPtr(FBTFunctionId(TEXT("SimpleCodeBase"), TEXT("SetObject"), USimpleCodeBase::VMC_SetObject));

	return 0;
}
static uint8 USimpleCodeBase_Index = Register_USimpleCodeBase();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning(pop)
#endif
