// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "BlueprintToolEditor/Public/BlueprintEditor/Core/Architect/BTSchema.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBTSchema() {}
// Cross Module References
	BLUEPRINTTOOLEDITOR_API UClass* Z_Construct_UClass_UBlueprintToolSchema();
	BLUEPRINTTOOLEDITOR_API UClass* Z_Construct_UClass_UBlueprintToolSchema_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UEdGraphSchema();
	UPackage* Z_Construct_UPackage__Script_BlueprintToolEditor();
// End Cross Module References
	void UBlueprintToolSchema::StaticRegisterNativesUBlueprintToolSchema()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UBlueprintToolSchema);
	UClass* Z_Construct_UClass_UBlueprintToolSchema_NoRegister()
	{
		return UBlueprintToolSchema::StaticClass();
	}
	struct Z_Construct_UClass_UBlueprintToolSchema_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UBlueprintToolSchema_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UEdGraphSchema,
		(UObject* (*)())Z_Construct_UPackage__Script_BlueprintToolEditor,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UBlueprintToolSchema_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UBlueprintToolSchema_Statics::Class_MetaDataParams[] = {
		{ "Comment", "// \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xd3\xbb\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\n// \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xe7\xa3\xba\xef\xbf\xbd\xd2\xbc\xef\xbf\xbd\xef\xbf\xbd\xcb\xb5\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd""action\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xda\xb5\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xd3\xb9\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbdPin\xef\xbf\xbd\xc4\xbb\xef\xbf\xbd\xef\xbf\xbd\xc6\xb2\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\n" },
		{ "IncludePath", "BlueprintEditor/Core/Architect/BTSchema.h" },
		{ "ModuleRelativePath", "Public/BlueprintEditor/Core/Architect/BTSchema.h" },
		{ "ToolTip", "\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xd3\xbb\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\n\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xe7\xa3\xba\xef\xbf\xbd\xd2\xbc\xef\xbf\xbd\xef\xbf\xbd\xcb\xb5\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd""action\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xda\xb5\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xd3\xb9\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbdPin\xef\xbf\xbd\xc4\xbb\xef\xbf\xbd\xef\xbf\xbd\xc6\xb2\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UBlueprintToolSchema_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UBlueprintToolSchema>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UBlueprintToolSchema_Statics::ClassParams = {
		&UBlueprintToolSchema::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x000000A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UBlueprintToolSchema_Statics::Class_MetaDataParams), Z_Construct_UClass_UBlueprintToolSchema_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_UBlueprintToolSchema()
	{
		if (!Z_Registration_Info_UClass_UBlueprintToolSchema.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UBlueprintToolSchema.OuterSingleton, Z_Construct_UClass_UBlueprintToolSchema_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UBlueprintToolSchema.OuterSingleton;
	}
	template<> BLUEPRINTTOOLEDITOR_API UClass* StaticClass<UBlueprintToolSchema>()
	{
		return UBlueprintToolSchema::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UBlueprintToolSchema);
	UBlueprintToolSchema::~UBlueprintToolSchema() {}
	struct Z_CompiledInDeferFile_FID_UEProject_TestOSS_Package_BlueprintTool_BlueprintTool_HostProject_Plugins_BlueprintTool_Source_BlueprintToolEditor_Public_BlueprintEditor_Core_Architect_BTSchema_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UEProject_TestOSS_Package_BlueprintTool_BlueprintTool_HostProject_Plugins_BlueprintTool_Source_BlueprintToolEditor_Public_BlueprintEditor_Core_Architect_BTSchema_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UBlueprintToolSchema, UBlueprintToolSchema::StaticClass, TEXT("UBlueprintToolSchema"), &Z_Registration_Info_UClass_UBlueprintToolSchema, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UBlueprintToolSchema), 3972065005U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UEProject_TestOSS_Package_BlueprintTool_BlueprintTool_HostProject_Plugins_BlueprintTool_Source_BlueprintToolEditor_Public_BlueprintEditor_Core_Architect_BTSchema_h_4288044386(TEXT("/Script/BlueprintToolEditor"),
		Z_CompiledInDeferFile_FID_UEProject_TestOSS_Package_BlueprintTool_BlueprintTool_HostProject_Plugins_BlueprintTool_Source_BlueprintToolEditor_Public_BlueprintEditor_Core_Architect_BTSchema_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UEProject_TestOSS_Package_BlueprintTool_BlueprintTool_HostProject_Plugins_BlueprintTool_Source_BlueprintToolEditor_Public_BlueprintEditor_Core_Architect_BTSchema_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
