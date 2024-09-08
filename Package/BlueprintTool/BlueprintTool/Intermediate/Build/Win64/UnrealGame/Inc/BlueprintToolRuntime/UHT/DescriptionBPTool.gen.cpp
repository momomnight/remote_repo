// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "BlueprintToolRuntime/Public/Details/DescriptionBPTool.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeDescriptionBPTool() {}
// Cross Module References
	BLUEPRINTTOOLRUNTIME_API UScriptStruct* Z_Construct_UScriptStruct_FDescriptionBPTool();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FTransform();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	UPackage* Z_Construct_UPackage__Script_BlueprintToolRuntime();
// End Cross Module References
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_DescriptionBPTool;
class UScriptStruct* FDescriptionBPTool::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_DescriptionBPTool.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_DescriptionBPTool.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FDescriptionBPTool, (UObject*)Z_Construct_UPackage__Script_BlueprintToolRuntime(), TEXT("DescriptionBPTool"));
	}
	return Z_Registration_Info_UScriptStruct_DescriptionBPTool.OuterSingleton;
}
template<> BLUEPRINTTOOLRUNTIME_API UScriptStruct* StaticStruct<FDescriptionBPTool>()
{
	return FDescriptionBPTool::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FDescriptionBPTool_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MeshTansform_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_MeshTansform;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MyActor_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_MyActor;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_A_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_A;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_B_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_B;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_C_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_C;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FDescriptionBPTool_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/Details/DescriptionBPTool.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FDescriptionBPTool_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FDescriptionBPTool>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FDescriptionBPTool_Statics::NewProp_MeshTansform_MetaData[] = {
		{ "Category", "Transform" },
		{ "ModuleRelativePath", "Public/Details/DescriptionBPTool.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FDescriptionBPTool_Statics::NewProp_MeshTansform = { "MeshTansform", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDescriptionBPTool, MeshTansform), Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDescriptionBPTool_Statics::NewProp_MeshTansform_MetaData), Z_Construct_UScriptStruct_FDescriptionBPTool_Statics::NewProp_MeshTansform_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FDescriptionBPTool_Statics::NewProp_MyActor_MetaData[] = {
		{ "Category", "Actor" },
		{ "ModuleRelativePath", "Public/Details/DescriptionBPTool.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FDescriptionBPTool_Statics::NewProp_MyActor = { "MyActor", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDescriptionBPTool, MyActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDescriptionBPTool_Statics::NewProp_MyActor_MetaData), Z_Construct_UScriptStruct_FDescriptionBPTool_Statics::NewProp_MyActor_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FDescriptionBPTool_Statics::NewProp_A_MetaData[] = {
		{ "Category", "hello" },
		{ "ModuleRelativePath", "Public/Details/DescriptionBPTool.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FDescriptionBPTool_Statics::NewProp_A = { "A", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDescriptionBPTool, A), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDescriptionBPTool_Statics::NewProp_A_MetaData), Z_Construct_UScriptStruct_FDescriptionBPTool_Statics::NewProp_A_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FDescriptionBPTool_Statics::NewProp_B_MetaData[] = {
		{ "Category", "hello" },
		{ "ModuleRelativePath", "Public/Details/DescriptionBPTool.h" },
		{ "Test", "Hide" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FDescriptionBPTool_Statics::NewProp_B = { "B", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDescriptionBPTool, B), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDescriptionBPTool_Statics::NewProp_B_MetaData), Z_Construct_UScriptStruct_FDescriptionBPTool_Statics::NewProp_B_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FDescriptionBPTool_Statics::NewProp_C_MetaData[] = {
		{ "Category", "hello" },
		{ "ModuleRelativePath", "Public/Details/DescriptionBPTool.h" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FDescriptionBPTool_Statics::NewProp_C = { "C", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDescriptionBPTool, C), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDescriptionBPTool_Statics::NewProp_C_MetaData), Z_Construct_UScriptStruct_FDescriptionBPTool_Statics::NewProp_C_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FDescriptionBPTool_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDescriptionBPTool_Statics::NewProp_MeshTansform,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDescriptionBPTool_Statics::NewProp_MyActor,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDescriptionBPTool_Statics::NewProp_A,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDescriptionBPTool_Statics::NewProp_B,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDescriptionBPTool_Statics::NewProp_C,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FDescriptionBPTool_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_BlueprintToolRuntime,
		nullptr,
		&NewStructOps,
		"DescriptionBPTool",
		Z_Construct_UScriptStruct_FDescriptionBPTool_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDescriptionBPTool_Statics::PropPointers),
		sizeof(FDescriptionBPTool),
		alignof(FDescriptionBPTool),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDescriptionBPTool_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FDescriptionBPTool_Statics::Struct_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDescriptionBPTool_Statics::PropPointers) < 2048);
	UScriptStruct* Z_Construct_UScriptStruct_FDescriptionBPTool()
	{
		if (!Z_Registration_Info_UScriptStruct_DescriptionBPTool.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_DescriptionBPTool.InnerSingleton, Z_Construct_UScriptStruct_FDescriptionBPTool_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_DescriptionBPTool.InnerSingleton;
	}
	struct Z_CompiledInDeferFile_FID_UEProject_TestOSS_Package_BlueprintTool_BlueprintTool_HostProject_Plugins_BlueprintTool_Source_BlueprintToolRuntime_Public_Details_DescriptionBPTool_h_Statics
	{
		static const FStructRegisterCompiledInInfo ScriptStructInfo[];
	};
	const FStructRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UEProject_TestOSS_Package_BlueprintTool_BlueprintTool_HostProject_Plugins_BlueprintTool_Source_BlueprintToolRuntime_Public_Details_DescriptionBPTool_h_Statics::ScriptStructInfo[] = {
		{ FDescriptionBPTool::StaticStruct, Z_Construct_UScriptStruct_FDescriptionBPTool_Statics::NewStructOps, TEXT("DescriptionBPTool"), &Z_Registration_Info_UScriptStruct_DescriptionBPTool, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FDescriptionBPTool), 2188413625U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UEProject_TestOSS_Package_BlueprintTool_BlueprintTool_HostProject_Plugins_BlueprintTool_Source_BlueprintToolRuntime_Public_Details_DescriptionBPTool_h_2525044998(TEXT("/Script/BlueprintToolRuntime"),
		nullptr, 0,
		Z_CompiledInDeferFile_FID_UEProject_TestOSS_Package_BlueprintTool_BlueprintTool_HostProject_Plugins_BlueprintTool_Source_BlueprintToolRuntime_Public_Details_DescriptionBPTool_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UEProject_TestOSS_Package_BlueprintTool_BlueprintTool_HostProject_Plugins_BlueprintTool_Source_BlueprintToolRuntime_Public_Details_DescriptionBPTool_h_Statics::ScriptStructInfo),
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
