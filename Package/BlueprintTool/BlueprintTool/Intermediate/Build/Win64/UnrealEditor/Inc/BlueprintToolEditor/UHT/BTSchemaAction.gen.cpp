// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "BlueprintToolEditor/Public/BlueprintEditor/Core/Architect/BTSchemaAction.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBTSchemaAction() {}
// Cross Module References
	BLUEPRINTTOOLEDITOR_API UScriptStruct* Z_Construct_UScriptStruct_FBlueprintToolSchemaAction();
	ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FEdGraphSchemaAction();
	UPackage* Z_Construct_UPackage__Script_BlueprintToolEditor();
// End Cross Module References

static_assert(std::is_polymorphic<FBlueprintToolSchemaAction>() == std::is_polymorphic<FEdGraphSchemaAction>(), "USTRUCT FBlueprintToolSchemaAction cannot be polymorphic unless super FEdGraphSchemaAction is polymorphic");

	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_BlueprintToolSchemaAction;
class UScriptStruct* FBlueprintToolSchemaAction::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_BlueprintToolSchemaAction.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_BlueprintToolSchemaAction.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FBlueprintToolSchemaAction, (UObject*)Z_Construct_UPackage__Script_BlueprintToolEditor(), TEXT("BlueprintToolSchemaAction"));
	}
	return Z_Registration_Info_UScriptStruct_BlueprintToolSchemaAction.OuterSingleton;
}
template<> BLUEPRINTTOOLEDITOR_API UScriptStruct* StaticStruct<FBlueprintToolSchemaAction>()
{
	return FBlueprintToolSchemaAction::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FBlueprintToolSchemaAction_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FBlueprintToolSchemaAction_Statics::Struct_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/BlueprintEditor/Core/Architect/BTSchemaAction.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FBlueprintToolSchemaAction_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FBlueprintToolSchemaAction>();
	}
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FBlueprintToolSchemaAction_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_BlueprintToolEditor,
		Z_Construct_UScriptStruct_FEdGraphSchemaAction,
		&NewStructOps,
		"BlueprintToolSchemaAction",
		nullptr,
		0,
		sizeof(FBlueprintToolSchemaAction),
		alignof(FBlueprintToolSchemaAction),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FBlueprintToolSchemaAction_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FBlueprintToolSchemaAction_Statics::Struct_MetaDataParams)
	};
	UScriptStruct* Z_Construct_UScriptStruct_FBlueprintToolSchemaAction()
	{
		if (!Z_Registration_Info_UScriptStruct_BlueprintToolSchemaAction.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_BlueprintToolSchemaAction.InnerSingleton, Z_Construct_UScriptStruct_FBlueprintToolSchemaAction_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_BlueprintToolSchemaAction.InnerSingleton;
	}
	struct Z_CompiledInDeferFile_FID_UEProject_TestOSS_Package_BlueprintTool_BlueprintTool_HostProject_Plugins_BlueprintTool_Source_BlueprintToolEditor_Public_BlueprintEditor_Core_Architect_BTSchemaAction_h_Statics
	{
		static const FStructRegisterCompiledInInfo ScriptStructInfo[];
	};
	const FStructRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UEProject_TestOSS_Package_BlueprintTool_BlueprintTool_HostProject_Plugins_BlueprintTool_Source_BlueprintToolEditor_Public_BlueprintEditor_Core_Architect_BTSchemaAction_h_Statics::ScriptStructInfo[] = {
		{ FBlueprintToolSchemaAction::StaticStruct, Z_Construct_UScriptStruct_FBlueprintToolSchemaAction_Statics::NewStructOps, TEXT("BlueprintToolSchemaAction"), &Z_Registration_Info_UScriptStruct_BlueprintToolSchemaAction, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FBlueprintToolSchemaAction), 512030101U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UEProject_TestOSS_Package_BlueprintTool_BlueprintTool_HostProject_Plugins_BlueprintTool_Source_BlueprintToolEditor_Public_BlueprintEditor_Core_Architect_BTSchemaAction_h_58536424(TEXT("/Script/BlueprintToolEditor"),
		nullptr, 0,
		Z_CompiledInDeferFile_FID_UEProject_TestOSS_Package_BlueprintTool_BlueprintTool_HostProject_Plugins_BlueprintTool_Source_BlueprintToolEditor_Public_BlueprintEditor_Core_Architect_BTSchemaAction_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UEProject_TestOSS_Package_BlueprintTool_BlueprintTool_HostProject_Plugins_BlueprintTool_Source_BlueprintToolEditor_Public_BlueprintEditor_Core_Architect_BTSchemaAction_h_Statics::ScriptStructInfo),
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
