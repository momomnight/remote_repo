// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "BlueprintToolEditor/Public/BlueprintEditor/GraphNode/BoardGraphNode.h"
#include "BlueprintToolRuntime/Public/Details/DescriptionBPTool.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBoardGraphNode() {}
// Cross Module References
	BLUEPRINTTOOLEDITOR_API UClass* Z_Construct_UClass_UBoardGraphNode();
	BLUEPRINTTOOLEDITOR_API UClass* Z_Construct_UClass_UBoardGraphNode_NoRegister();
	BLUEPRINTTOOLEDITOR_API UClass* Z_Construct_UClass_UK3Node();
	BLUEPRINTTOOLRUNTIME_API UScriptStruct* Z_Construct_UScriptStruct_FDescriptionBPTool();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FTransform();
	UPackage* Z_Construct_UPackage__Script_BlueprintToolEditor();
// End Cross Module References
	void UBoardGraphNode::StaticRegisterNativesUBoardGraphNode()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UBoardGraphNode);
	UClass* Z_Construct_UClass_UBoardGraphNode_NoRegister()
	{
		return UBoardGraphNode::StaticClass();
	}
	struct Z_Construct_UClass_UBoardGraphNode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Transform_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Transform;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DescriptionBPTool_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_DescriptionBPTool;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_A_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_A;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UBoardGraphNode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UK3Node,
		(UObject* (*)())Z_Construct_UPackage__Script_BlueprintToolEditor,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UBoardGraphNode_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UBoardGraphNode_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "BlueprintEditor/GraphNode/BoardGraphNode.h" },
		{ "ModuleRelativePath", "Public/BlueprintEditor/GraphNode/BoardGraphNode.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UBoardGraphNode_Statics::NewProp_Transform_MetaData[] = {
		{ "Category", "K3Node" },
		{ "ModuleRelativePath", "Public/BlueprintEditor/GraphNode/BoardGraphNode.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UBoardGraphNode_Statics::NewProp_Transform = { "Transform", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UBoardGraphNode, Transform), Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UBoardGraphNode_Statics::NewProp_Transform_MetaData), Z_Construct_UClass_UBoardGraphNode_Statics::NewProp_Transform_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UBoardGraphNode_Statics::NewProp_DescriptionBPTool_MetaData[] = {
		{ "Category", "K3Node" },
		{ "ModuleRelativePath", "Public/BlueprintEditor/GraphNode/BoardGraphNode.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UBoardGraphNode_Statics::NewProp_DescriptionBPTool = { "DescriptionBPTool", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UBoardGraphNode, DescriptionBPTool), Z_Construct_UScriptStruct_FDescriptionBPTool, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UBoardGraphNode_Statics::NewProp_DescriptionBPTool_MetaData), Z_Construct_UClass_UBoardGraphNode_Statics::NewProp_DescriptionBPTool_MetaData) }; // 2188413625
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UBoardGraphNode_Statics::NewProp_A_MetaData[] = {
		{ "Category", "hello" },
		{ "ModuleRelativePath", "Public/BlueprintEditor/GraphNode/BoardGraphNode.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UBoardGraphNode_Statics::NewProp_A = { "A", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UBoardGraphNode, A), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UBoardGraphNode_Statics::NewProp_A_MetaData), Z_Construct_UClass_UBoardGraphNode_Statics::NewProp_A_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UBoardGraphNode_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UBoardGraphNode_Statics::NewProp_Transform,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UBoardGraphNode_Statics::NewProp_DescriptionBPTool,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UBoardGraphNode_Statics::NewProp_A,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UBoardGraphNode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UBoardGraphNode>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UBoardGraphNode_Statics::ClassParams = {
		&UBoardGraphNode::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UBoardGraphNode_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UBoardGraphNode_Statics::PropPointers),
		0,
		0x000000A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UBoardGraphNode_Statics::Class_MetaDataParams), Z_Construct_UClass_UBoardGraphNode_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UBoardGraphNode_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UBoardGraphNode()
	{
		if (!Z_Registration_Info_UClass_UBoardGraphNode.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UBoardGraphNode.OuterSingleton, Z_Construct_UClass_UBoardGraphNode_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UBoardGraphNode.OuterSingleton;
	}
	template<> BLUEPRINTTOOLEDITOR_API UClass* StaticClass<UBoardGraphNode>()
	{
		return UBoardGraphNode::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UBoardGraphNode);
	UBoardGraphNode::~UBoardGraphNode() {}
	struct Z_CompiledInDeferFile_FID_UEProject_TestOSS_Package_BlueprintTool_BlueprintTool_HostProject_Plugins_BlueprintTool_Source_BlueprintToolEditor_Public_BlueprintEditor_GraphNode_BoardGraphNode_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UEProject_TestOSS_Package_BlueprintTool_BlueprintTool_HostProject_Plugins_BlueprintTool_Source_BlueprintToolEditor_Public_BlueprintEditor_GraphNode_BoardGraphNode_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UBoardGraphNode, UBoardGraphNode::StaticClass, TEXT("UBoardGraphNode"), &Z_Registration_Info_UClass_UBoardGraphNode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UBoardGraphNode), 1573951136U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UEProject_TestOSS_Package_BlueprintTool_BlueprintTool_HostProject_Plugins_BlueprintTool_Source_BlueprintToolEditor_Public_BlueprintEditor_GraphNode_BoardGraphNode_h_1002388823(TEXT("/Script/BlueprintToolEditor"),
		Z_CompiledInDeferFile_FID_UEProject_TestOSS_Package_BlueprintTool_BlueprintTool_HostProject_Plugins_BlueprintTool_Source_BlueprintToolEditor_Public_BlueprintEditor_GraphNode_BoardGraphNode_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UEProject_TestOSS_Package_BlueprintTool_BlueprintTool_HostProject_Plugins_BlueprintTool_Source_BlueprintToolEditor_Public_BlueprintEditor_GraphNode_BoardGraphNode_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
