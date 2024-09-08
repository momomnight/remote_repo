// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "BlueprintToolEditor/Public/BlueprintEditor/Core/Architect/VariableNode.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVariableNode() {}
// Cross Module References
	BLUEPRINTTOOLEDITOR_API UClass* Z_Construct_UClass_UK3Node();
	BLUEPRINTTOOLEDITOR_API UClass* Z_Construct_UClass_UVariableNode();
	BLUEPRINTTOOLEDITOR_API UClass* Z_Construct_UClass_UVariableNode_NoRegister();
	UPackage* Z_Construct_UPackage__Script_BlueprintToolEditor();
// End Cross Module References
	void UVariableNode::StaticRegisterNativesUVariableNode()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UVariableNode);
	UClass* Z_Construct_UClass_UVariableNode_NoRegister()
	{
		return UVariableNode::StaticClass();
	}
	struct Z_Construct_UClass_UVariableNode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UVariableNode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UK3Node,
		(UObject* (*)())Z_Construct_UPackage__Script_BlueprintToolEditor,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UVariableNode_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVariableNode_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "BlueprintEditor/Core/Architect/VariableNode.h" },
		{ "ModuleRelativePath", "Public/BlueprintEditor/Core/Architect/VariableNode.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UVariableNode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UVariableNode>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UVariableNode_Statics::ClassParams = {
		&UVariableNode::StaticClass,
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
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVariableNode_Statics::Class_MetaDataParams), Z_Construct_UClass_UVariableNode_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_UVariableNode()
	{
		if (!Z_Registration_Info_UClass_UVariableNode.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UVariableNode.OuterSingleton, Z_Construct_UClass_UVariableNode_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UVariableNode.OuterSingleton;
	}
	template<> BLUEPRINTTOOLEDITOR_API UClass* StaticClass<UVariableNode>()
	{
		return UVariableNode::StaticClass();
	}
	UVariableNode::UVariableNode() {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UVariableNode);
	UVariableNode::~UVariableNode() {}
	struct Z_CompiledInDeferFile_FID_UEProject_TestOSS_Package_BlueprintTool_BlueprintTool_HostProject_Plugins_BlueprintTool_Source_BlueprintToolEditor_Public_BlueprintEditor_Core_Architect_VariableNode_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UEProject_TestOSS_Package_BlueprintTool_BlueprintTool_HostProject_Plugins_BlueprintTool_Source_BlueprintToolEditor_Public_BlueprintEditor_Core_Architect_VariableNode_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UVariableNode, UVariableNode::StaticClass, TEXT("UVariableNode"), &Z_Registration_Info_UClass_UVariableNode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UVariableNode), 2329724385U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UEProject_TestOSS_Package_BlueprintTool_BlueprintTool_HostProject_Plugins_BlueprintTool_Source_BlueprintToolEditor_Public_BlueprintEditor_Core_Architect_VariableNode_h_3554330404(TEXT("/Script/BlueprintToolEditor"),
		Z_CompiledInDeferFile_FID_UEProject_TestOSS_Package_BlueprintTool_BlueprintTool_HostProject_Plugins_BlueprintTool_Source_BlueprintToolEditor_Public_BlueprintEditor_Core_Architect_VariableNode_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UEProject_TestOSS_Package_BlueprintTool_BlueprintTool_HostProject_Plugins_BlueprintTool_Source_BlueprintToolEditor_Public_BlueprintEditor_Core_Architect_VariableNode_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
