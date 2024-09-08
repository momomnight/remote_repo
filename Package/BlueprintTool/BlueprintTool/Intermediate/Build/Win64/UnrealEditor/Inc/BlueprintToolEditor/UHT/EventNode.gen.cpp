// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "BlueprintToolEditor/Public/BlueprintEditor/GraphNode/EventNode.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeEventNode() {}
// Cross Module References
	BLUEPRINTTOOLEDITOR_API UClass* Z_Construct_UClass_UEventNode();
	BLUEPRINTTOOLEDITOR_API UClass* Z_Construct_UClass_UEventNode_NoRegister();
	BLUEPRINTTOOLEDITOR_API UClass* Z_Construct_UClass_UK3Node();
	UPackage* Z_Construct_UPackage__Script_BlueprintToolEditor();
// End Cross Module References
	void UEventNode::StaticRegisterNativesUEventNode()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UEventNode);
	UClass* Z_Construct_UClass_UEventNode_NoRegister()
	{
		return UEventNode::StaticClass();
	}
	struct Z_Construct_UClass_UEventNode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UEventNode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UK3Node,
		(UObject* (*)())Z_Construct_UPackage__Script_BlueprintToolEditor,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UEventNode_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UEventNode_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "BlueprintEditor/GraphNode/EventNode.h" },
		{ "ModuleRelativePath", "Public/BlueprintEditor/GraphNode/EventNode.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UEventNode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UEventNode>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UEventNode_Statics::ClassParams = {
		&UEventNode::StaticClass,
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
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UEventNode_Statics::Class_MetaDataParams), Z_Construct_UClass_UEventNode_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_UEventNode()
	{
		if (!Z_Registration_Info_UClass_UEventNode.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UEventNode.OuterSingleton, Z_Construct_UClass_UEventNode_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UEventNode.OuterSingleton;
	}
	template<> BLUEPRINTTOOLEDITOR_API UClass* StaticClass<UEventNode>()
	{
		return UEventNode::StaticClass();
	}
	UEventNode::UEventNode() {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UEventNode);
	UEventNode::~UEventNode() {}
	struct Z_CompiledInDeferFile_FID_UEProject_TestOSS_Package_BlueprintTool_BlueprintTool_HostProject_Plugins_BlueprintTool_Source_BlueprintToolEditor_Public_BlueprintEditor_GraphNode_EventNode_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UEProject_TestOSS_Package_BlueprintTool_BlueprintTool_HostProject_Plugins_BlueprintTool_Source_BlueprintToolEditor_Public_BlueprintEditor_GraphNode_EventNode_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UEventNode, UEventNode::StaticClass, TEXT("UEventNode"), &Z_Registration_Info_UClass_UEventNode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UEventNode), 2315959525U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UEProject_TestOSS_Package_BlueprintTool_BlueprintTool_HostProject_Plugins_BlueprintTool_Source_BlueprintToolEditor_Public_BlueprintEditor_GraphNode_EventNode_h_3858247359(TEXT("/Script/BlueprintToolEditor"),
		Z_CompiledInDeferFile_FID_UEProject_TestOSS_Package_BlueprintTool_BlueprintTool_HostProject_Plugins_BlueprintTool_Source_BlueprintToolEditor_Public_BlueprintEditor_GraphNode_EventNode_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UEProject_TestOSS_Package_BlueprintTool_BlueprintTool_HostProject_Plugins_BlueprintTool_Source_BlueprintToolEditor_Public_BlueprintEditor_GraphNode_EventNode_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
