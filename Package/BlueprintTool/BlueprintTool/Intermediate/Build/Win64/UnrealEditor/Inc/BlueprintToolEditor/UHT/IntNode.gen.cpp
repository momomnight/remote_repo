// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "BlueprintToolEditor/Public/BlueprintEditor/GraphNode/IntNode.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeIntNode() {}
// Cross Module References
	BLUEPRINTTOOLEDITOR_API UClass* Z_Construct_UClass_UInt64Node();
	BLUEPRINTTOOLEDITOR_API UClass* Z_Construct_UClass_UInt64Node_NoRegister();
	BLUEPRINTTOOLEDITOR_API UClass* Z_Construct_UClass_UIntNode();
	BLUEPRINTTOOLEDITOR_API UClass* Z_Construct_UClass_UIntNode_NoRegister();
	BLUEPRINTTOOLEDITOR_API UClass* Z_Construct_UClass_UVariableNode();
	UPackage* Z_Construct_UPackage__Script_BlueprintToolEditor();
// End Cross Module References
	void UIntNode::StaticRegisterNativesUIntNode()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UIntNode);
	UClass* Z_Construct_UClass_UIntNode_NoRegister()
	{
		return UIntNode::StaticClass();
	}
	struct Z_Construct_UClass_UIntNode_Statics
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
		static const UECodeGen_Private::FIntPropertyParams NewProp_Value;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UIntNode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UVariableNode,
		(UObject* (*)())Z_Construct_UPackage__Script_BlueprintToolEditor,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UIntNode_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UIntNode_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "BlueprintEditor/GraphNode/IntNode.h" },
		{ "ModuleRelativePath", "Public/BlueprintEditor/GraphNode/IntNode.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UIntNode_Statics::NewProp_VariableName_MetaData[] = {
		{ "Category", "Variable" },
		{ "ModuleRelativePath", "Public/BlueprintEditor/GraphNode/IntNode.h" },
	};
#endif
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UClass_UIntNode_Statics::NewProp_VariableName = { "VariableName", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UIntNode, VariableName), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UIntNode_Statics::NewProp_VariableName_MetaData), Z_Construct_UClass_UIntNode_Statics::NewProp_VariableName_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UIntNode_Statics::NewProp_Value_MetaData[] = {
		{ "Category", "Instance" },
		{ "ModuleRelativePath", "Public/BlueprintEditor/GraphNode/IntNode.h" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UIntNode_Statics::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UIntNode, Value), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UIntNode_Statics::NewProp_Value_MetaData), Z_Construct_UClass_UIntNode_Statics::NewProp_Value_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UIntNode_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UIntNode_Statics::NewProp_VariableName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UIntNode_Statics::NewProp_Value,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UIntNode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UIntNode>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UIntNode_Statics::ClassParams = {
		&UIntNode::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UIntNode_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UIntNode_Statics::PropPointers),
		0,
		0x000000A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UIntNode_Statics::Class_MetaDataParams), Z_Construct_UClass_UIntNode_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UIntNode_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UIntNode()
	{
		if (!Z_Registration_Info_UClass_UIntNode.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UIntNode.OuterSingleton, Z_Construct_UClass_UIntNode_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UIntNode.OuterSingleton;
	}
	template<> BLUEPRINTTOOLEDITOR_API UClass* StaticClass<UIntNode>()
	{
		return UIntNode::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UIntNode);
	UIntNode::~UIntNode() {}
	void UInt64Node::StaticRegisterNativesUInt64Node()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UInt64Node);
	UClass* Z_Construct_UClass_UInt64Node_NoRegister()
	{
		return UInt64Node::StaticClass();
	}
	struct Z_Construct_UClass_UInt64Node_Statics
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
		static const UECodeGen_Private::FInt64PropertyParams NewProp_Value;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UInt64Node_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UVariableNode,
		(UObject* (*)())Z_Construct_UPackage__Script_BlueprintToolEditor,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UInt64Node_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UInt64Node_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "BlueprintEditor/GraphNode/IntNode.h" },
		{ "ModuleRelativePath", "Public/BlueprintEditor/GraphNode/IntNode.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UInt64Node_Statics::NewProp_VariableName_MetaData[] = {
		{ "Category", "Variable" },
		{ "ModuleRelativePath", "Public/BlueprintEditor/GraphNode/IntNode.h" },
	};
#endif
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UClass_UInt64Node_Statics::NewProp_VariableName = { "VariableName", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UInt64Node, VariableName), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UInt64Node_Statics::NewProp_VariableName_MetaData), Z_Construct_UClass_UInt64Node_Statics::NewProp_VariableName_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UInt64Node_Statics::NewProp_Value_MetaData[] = {
		{ "Category", "Instance" },
		{ "ModuleRelativePath", "Public/BlueprintEditor/GraphNode/IntNode.h" },
	};
#endif
	const UECodeGen_Private::FInt64PropertyParams Z_Construct_UClass_UInt64Node_Statics::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UInt64Node, Value), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UInt64Node_Statics::NewProp_Value_MetaData), Z_Construct_UClass_UInt64Node_Statics::NewProp_Value_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UInt64Node_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInt64Node_Statics::NewProp_VariableName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInt64Node_Statics::NewProp_Value,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UInt64Node_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UInt64Node>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UInt64Node_Statics::ClassParams = {
		&UInt64Node::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UInt64Node_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UInt64Node_Statics::PropPointers),
		0,
		0x000000A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UInt64Node_Statics::Class_MetaDataParams), Z_Construct_UClass_UInt64Node_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UInt64Node_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UInt64Node()
	{
		if (!Z_Registration_Info_UClass_UInt64Node.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UInt64Node.OuterSingleton, Z_Construct_UClass_UInt64Node_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UInt64Node.OuterSingleton;
	}
	template<> BLUEPRINTTOOLEDITOR_API UClass* StaticClass<UInt64Node>()
	{
		return UInt64Node::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UInt64Node);
	UInt64Node::~UInt64Node() {}
	struct Z_CompiledInDeferFile_FID_UEProject_TestOSS_Package_BlueprintTool_BlueprintTool_HostProject_Plugins_BlueprintTool_Source_BlueprintToolEditor_Public_BlueprintEditor_GraphNode_IntNode_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UEProject_TestOSS_Package_BlueprintTool_BlueprintTool_HostProject_Plugins_BlueprintTool_Source_BlueprintToolEditor_Public_BlueprintEditor_GraphNode_IntNode_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UIntNode, UIntNode::StaticClass, TEXT("UIntNode"), &Z_Registration_Info_UClass_UIntNode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UIntNode), 2850721106U) },
		{ Z_Construct_UClass_UInt64Node, UInt64Node::StaticClass, TEXT("UInt64Node"), &Z_Registration_Info_UClass_UInt64Node, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UInt64Node), 1750918545U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UEProject_TestOSS_Package_BlueprintTool_BlueprintTool_HostProject_Plugins_BlueprintTool_Source_BlueprintToolEditor_Public_BlueprintEditor_GraphNode_IntNode_h_296013531(TEXT("/Script/BlueprintToolEditor"),
		Z_CompiledInDeferFile_FID_UEProject_TestOSS_Package_BlueprintTool_BlueprintTool_HostProject_Plugins_BlueprintTool_Source_BlueprintToolEditor_Public_BlueprintEditor_GraphNode_IntNode_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UEProject_TestOSS_Package_BlueprintTool_BlueprintTool_HostProject_Plugins_BlueprintTool_Source_BlueprintToolEditor_Public_BlueprintEditor_GraphNode_IntNode_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
