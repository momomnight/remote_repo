// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "SimpleCodeEvent.h"
#include "FunctionManage.h"
#include "UObject/GeneratedCppIncludes.h"

#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static FName Name_BlueprintGameBegins = FName(TEXT("BlueprintGameBegins"));
void USimpleCodeEvent::BlueprintGameBegins(UStaticMeshComponent* Mesh)
{
	TSharedPtr<FFunctionParameter> FunctionParameter = nullptr;
	AddParam(&Mesh, FunctionParameter);
	ExecuteScript(FindScriptFunction(Name_BlueprintGameBegins), &FunctionParameter);
}

/* As an executable function pointer for global registration, we skip the UE
   UFunction local function registration because there is no bytecode in it.*/
uint8 Register_USimpleCodeEvent()
{

	return 0;
}
static uint8 USimpleCodeEvent_Index = Register_USimpleCodeEvent();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning(pop)
#endif
