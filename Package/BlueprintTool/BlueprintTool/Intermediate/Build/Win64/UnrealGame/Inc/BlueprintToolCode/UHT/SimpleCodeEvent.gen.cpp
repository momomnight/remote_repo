// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "BlueprintToolCode/Public/SimpleCodeEvent.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSimpleCodeEvent() {}
// Cross Module References
	BLUEPRINTTOOLCODE_API UClass* Z_Construct_UClass_USimpleCode();
	BLUEPRINTTOOLCODE_API UClass* Z_Construct_UClass_USimpleCodeEvent();
	BLUEPRINTTOOLCODE_API UClass* Z_Construct_UClass_USimpleCodeEvent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
	UPackage* Z_Construct_UPackage__Script_BlueprintToolCode();
// End Cross Module References
	DEFINE_FUNCTION(USimpleCodeEvent::execBlueprintGameBegins)
	{
		P_GET_OBJECT(UStaticMeshComponent,Z_Param_Mesh);
		P_FINISH;
		P_NATIVE_BEGIN;
		USimpleCodeEvent::BlueprintGameBegins(Z_Param_Mesh);
		P_NATIVE_END;
	}
	void USimpleCodeEvent::StaticRegisterNativesUSimpleCodeEvent()
	{
		UClass* Class = USimpleCodeEvent::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "BlueprintGameBegins", &USimpleCodeEvent::execBlueprintGameBegins },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_USimpleCodeEvent_BlueprintGameBegins_Statics
	{
		struct SimpleCodeEvent_eventBlueprintGameBegins_Parms
		{
			UStaticMeshComponent* Mesh;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Mesh_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Mesh;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USimpleCodeEvent_BlueprintGameBegins_Statics::NewProp_Mesh_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USimpleCodeEvent_BlueprintGameBegins_Statics::NewProp_Mesh = { "Mesh", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SimpleCodeEvent_eventBlueprintGameBegins_Parms, Mesh), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleCodeEvent_BlueprintGameBegins_Statics::NewProp_Mesh_MetaData), Z_Construct_UFunction_USimpleCodeEvent_BlueprintGameBegins_Statics::NewProp_Mesh_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USimpleCodeEvent_BlueprintGameBegins_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimpleCodeEvent_BlueprintGameBegins_Statics::NewProp_Mesh,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USimpleCodeEvent_BlueprintGameBegins_Statics::Function_MetaDataParams[] = {
		{ "CodeType", "Event" },
		{ "Group", "MainEvent" },
		{ "ModuleRelativePath", "Public/SimpleCodeEvent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USimpleCodeEvent_BlueprintGameBegins_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USimpleCodeEvent, nullptr, "BlueprintGameBegins", nullptr, nullptr, Z_Construct_UFunction_USimpleCodeEvent_BlueprintGameBegins_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleCodeEvent_BlueprintGameBegins_Statics::PropPointers), sizeof(Z_Construct_UFunction_USimpleCodeEvent_BlueprintGameBegins_Statics::SimpleCodeEvent_eventBlueprintGameBegins_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleCodeEvent_BlueprintGameBegins_Statics::Function_MetaDataParams), Z_Construct_UFunction_USimpleCodeEvent_BlueprintGameBegins_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleCodeEvent_BlueprintGameBegins_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_USimpleCodeEvent_BlueprintGameBegins_Statics::SimpleCodeEvent_eventBlueprintGameBegins_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_USimpleCodeEvent_BlueprintGameBegins()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USimpleCodeEvent_BlueprintGameBegins_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(USimpleCodeEvent);
	UClass* Z_Construct_UClass_USimpleCodeEvent_NoRegister()
	{
		return USimpleCodeEvent::StaticClass();
	}
	struct Z_Construct_UClass_USimpleCodeEvent_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_USimpleCodeEvent_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_USimpleCode,
		(UObject* (*)())Z_Construct_UPackage__Script_BlueprintToolCode,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_USimpleCodeEvent_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_USimpleCodeEvent_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_USimpleCodeEvent_BlueprintGameBegins, "BlueprintGameBegins" }, // 2863945963
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_USimpleCodeEvent_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USimpleCodeEvent_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "SimpleCodeEvent.h" },
		{ "ModuleRelativePath", "Public/SimpleCodeEvent.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_USimpleCodeEvent_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USimpleCodeEvent>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_USimpleCodeEvent_Statics::ClassParams = {
		&USimpleCodeEvent::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		0,
		0,
		0x001000A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_USimpleCodeEvent_Statics::Class_MetaDataParams), Z_Construct_UClass_USimpleCodeEvent_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_USimpleCodeEvent()
	{
		if (!Z_Registration_Info_UClass_USimpleCodeEvent.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_USimpleCodeEvent.OuterSingleton, Z_Construct_UClass_USimpleCodeEvent_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_USimpleCodeEvent.OuterSingleton;
	}
	template<> BLUEPRINTTOOLCODE_API UClass* StaticClass<USimpleCodeEvent>()
	{
		return USimpleCodeEvent::StaticClass();
	}
	USimpleCodeEvent::USimpleCodeEvent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(USimpleCodeEvent);
	USimpleCodeEvent::~USimpleCodeEvent() {}
	struct Z_CompiledInDeferFile_FID_UEProject_TestOSS_Package_BlueprintTool_BlueprintTool_HostProject_Plugins_BlueprintTool_Source_BlueprintToolCode_Public_SimpleCodeEvent_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UEProject_TestOSS_Package_BlueprintTool_BlueprintTool_HostProject_Plugins_BlueprintTool_Source_BlueprintToolCode_Public_SimpleCodeEvent_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_USimpleCodeEvent, USimpleCodeEvent::StaticClass, TEXT("USimpleCodeEvent"), &Z_Registration_Info_UClass_USimpleCodeEvent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(USimpleCodeEvent), 107952024U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UEProject_TestOSS_Package_BlueprintTool_BlueprintTool_HostProject_Plugins_BlueprintTool_Source_BlueprintToolCode_Public_SimpleCodeEvent_h_1743504531(TEXT("/Script/BlueprintToolCode"),
		Z_CompiledInDeferFile_FID_UEProject_TestOSS_Package_BlueprintTool_BlueprintTool_HostProject_Plugins_BlueprintTool_Source_BlueprintToolCode_Public_SimpleCodeEvent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UEProject_TestOSS_Package_BlueprintTool_BlueprintTool_HostProject_Plugins_BlueprintTool_Source_BlueprintToolCode_Public_SimpleCodeEvent_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
