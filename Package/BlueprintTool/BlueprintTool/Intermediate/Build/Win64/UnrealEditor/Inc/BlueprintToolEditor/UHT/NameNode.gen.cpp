// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "BlueprintToolEditor/Public/BlueprintEditor/GraphNode/NameNode.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeNameNode() {}
// Cross Module References
	BLUEPRINTTOOLEDITOR_API UClass* Z_Construct_UClass_UNameNode();
	BLUEPRINTTOOLEDITOR_API UClass* Z_Construct_UClass_UNameNode_NoRegister();
	BLUEPRINTTOOLEDITOR_API UClass* Z_Construct_UClass_UVariableNode();
	UPackage* Z_Construct_UPackage__Script_BlueprintToolEditor();
// End Cross Module References
	void UNameNode::StaticRegisterNativesUNameNode()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UNameNode);
	UClass* Z_Construct_UClass_UNameNode_NoRegister()
	{
		return UNameNode::StaticClass();
	}
	struct Z_Construct_UClass_UNameNode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_VariableName_MetaData[];
#endif
		static const UECodeGen_Private::FNamePropertyParams NewProp_VariableName;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Value_MetaData[];
#endif
		static const UECodeGen_Private::FNamePropertyParams NewProp_Value;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UNameNode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UVariableNode,
		(UObject* (*)())Z_Construct_UPackage__Script_BlueprintToolEditor,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UNameNode_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UNameNode_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "BlueprintEditor/GraphNode/NameNode.h" },
		{ "ModuleRelativePath", "Public/BlueprintEditor/GraphNode/NameNode.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UNameNode_Statics::NewProp_VariableName_MetaData[] = {
		{ "Category", "Variable" },
		{ "ModuleRelativePath", "Public/BlueprintEditor/GraphNode/NameNode.h" },
	};
#endif
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UClass_UNameNode_Statics::NewProp_VariableName = { "VariableName", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UNameNode, VariableName), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UNameNode_Statics::NewProp_VariableName_MetaData), Z_Construct_UClass_UNameNode_Statics::NewProp_VariableName_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UNameNode_Statics::NewProp_Value_MetaData[] = {
		{ "Category", "Instance" },
		{ "ModuleRelativePath", "Public/BlueprintEditor/GraphNode/NameNode.h" },
	};
#endif
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UClass_UNameNode_Statics::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UNameNode, Value), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UNameNode_Statics::NewProp_Value_MetaData), Z_Construct_UClass_UNameNode_Statics::NewProp_Value_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UNameNode_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UNameNode_Statics::NewProp_VariableName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UNameNode_Statics::NewProp_Value,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UNameNode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UNameNode>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UNameNode_Statics::ClassParams = {
		&UNameNode::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UNameNode_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UNameNode_Statics::PropPointers),
		0,
		0x000000A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UNameNode_Statics::Class_MetaDataParams), Z_Construct_UClass_UNameNode_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UNameNode_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UNameNode()
	{
		if (!Z_Registration_Info_UClass_UNameNode.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UNameNode.OuterSingleton, Z_Construct_UClass_UNameNode_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UNameNode.OuterSingleton;
	}
	template<> BLUEPRINTTOOLEDITOR_API UClass* StaticClass<UNameNode>()
	{
		return UNameNode::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UNameNode);
	UNameNode::~UNameNode() {}
	struct Z_CompiledInDeferFile_FID_UEProject_TestOSS_Package_BlueprintTool_BlueprintTool_HostProject_Plugins_BlueprintTool_Source_BlueprintToolEditor_Public_BlueprintEditor_GraphNode_NameNode_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UEProject_TestOSS_Package_BlueprintTool_BlueprintTool_HostProject_Plugins_BlueprintTool_Source_BlueprintToolEditor_Public_BlueprintEditor_GraphNode_NameNode_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UNameNode, UNameNode::StaticClass, TEXT("UNameNode"), &Z_Registration_Info_UClass_UNameNode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UNameNode), 1447991225U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UEProject_TestOSS_Package_BlueprintTool_BlueprintTool_HostProject_Plugins_BlueprintTool_Source_BlueprintToolEditor_Public_BlueprintEditor_GraphNode_NameNode_h_1349127699(TEXT("/Script/BlueprintToolEditor"),
		Z_CompiledInDeferFile_FID_UEProject_TestOSS_Package_BlueprintTool_BlueprintTool_HostProject_Plugins_BlueprintTool_Source_BlueprintToolEditor_Public_BlueprintEditor_GraphNode_NameNode_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UEProject_TestOSS_Package_BlueprintTool_BlueprintTool_HostProject_Plugins_BlueprintTool_Source_BlueprintToolEditor_Public_BlueprintEditor_GraphNode_NameNode_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
