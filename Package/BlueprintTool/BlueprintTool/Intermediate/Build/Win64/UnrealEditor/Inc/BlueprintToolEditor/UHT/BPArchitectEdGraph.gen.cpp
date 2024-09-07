// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "BlueprintToolEditor/Public/BlueprintEditor/Core/Architect/BPArchitectEdGraph.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBPArchitectEdGraph() {}
// Cross Module References
	BLUEPRINTTOOLEDITOR_API UClass* Z_Construct_UClass_UBPArchitectEdGraph();
	BLUEPRINTTOOLEDITOR_API UClass* Z_Construct_UClass_UBPArchitectEdGraph_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UEdGraph();
	UPackage* Z_Construct_UPackage__Script_BlueprintToolEditor();
// End Cross Module References
	void UBPArchitectEdGraph::StaticRegisterNativesUBPArchitectEdGraph()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UBPArchitectEdGraph);
	UClass* Z_Construct_UClass_UBPArchitectEdGraph_NoRegister()
	{
		return UBPArchitectEdGraph::StaticClass();
	}
	struct Z_Construct_UClass_UBPArchitectEdGraph_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UBPArchitectEdGraph_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UEdGraph,
		(UObject* (*)())Z_Construct_UPackage__Script_BlueprintToolEditor,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UBPArchitectEdGraph_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UBPArchitectEdGraph_Statics::Class_MetaDataParams[] = {
		{ "Comment", "//\xef\xbf\xbd\xef\xbf\xbd\xcd\xbc\xef\xbf\xbd\xef\xbf\xbd\xca\xb5\xef\xbf\xbd\xef\xbf\xbd\n" },
		{ "IncludePath", "BlueprintEditor/Core/Architect/BPArchitectEdGraph.h" },
		{ "ModuleRelativePath", "Public/BlueprintEditor/Core/Architect/BPArchitectEdGraph.h" },
		{ "ToolTip", "\xef\xbf\xbd\xef\xbf\xbd\xcd\xbc\xef\xbf\xbd\xef\xbf\xbd\xca\xb5\xef\xbf\xbd\xef\xbf\xbd" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UBPArchitectEdGraph_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UBPArchitectEdGraph>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UBPArchitectEdGraph_Statics::ClassParams = {
		&UBPArchitectEdGraph::StaticClass,
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
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UBPArchitectEdGraph_Statics::Class_MetaDataParams), Z_Construct_UClass_UBPArchitectEdGraph_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_UBPArchitectEdGraph()
	{
		if (!Z_Registration_Info_UClass_UBPArchitectEdGraph.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UBPArchitectEdGraph.OuterSingleton, Z_Construct_UClass_UBPArchitectEdGraph_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UBPArchitectEdGraph.OuterSingleton;
	}
	template<> BLUEPRINTTOOLEDITOR_API UClass* StaticClass<UBPArchitectEdGraph>()
	{
		return UBPArchitectEdGraph::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UBPArchitectEdGraph);
	UBPArchitectEdGraph::~UBPArchitectEdGraph() {}
	struct Z_CompiledInDeferFile_FID_UEProject_TestOSS_Package_BlueprintTool_BlueprintTool_HostProject_Plugins_BlueprintTool_Source_BlueprintToolEditor_Public_BlueprintEditor_Core_Architect_BPArchitectEdGraph_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UEProject_TestOSS_Package_BlueprintTool_BlueprintTool_HostProject_Plugins_BlueprintTool_Source_BlueprintToolEditor_Public_BlueprintEditor_Core_Architect_BPArchitectEdGraph_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UBPArchitectEdGraph, UBPArchitectEdGraph::StaticClass, TEXT("UBPArchitectEdGraph"), &Z_Registration_Info_UClass_UBPArchitectEdGraph, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UBPArchitectEdGraph), 467254211U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UEProject_TestOSS_Package_BlueprintTool_BlueprintTool_HostProject_Plugins_BlueprintTool_Source_BlueprintToolEditor_Public_BlueprintEditor_Core_Architect_BPArchitectEdGraph_h_2829358344(TEXT("/Script/BlueprintToolEditor"),
		Z_CompiledInDeferFile_FID_UEProject_TestOSS_Package_BlueprintTool_BlueprintTool_HostProject_Plugins_BlueprintTool_Source_BlueprintToolEditor_Public_BlueprintEditor_Core_Architect_BPArchitectEdGraph_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UEProject_TestOSS_Package_BlueprintTool_BlueprintTool_HostProject_Plugins_BlueprintTool_Source_BlueprintToolEditor_Public_BlueprintEditor_Core_Architect_BPArchitectEdGraph_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
