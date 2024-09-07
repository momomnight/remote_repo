// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "BlueprintToolEditor/Public/BlueprintEditor/GraphNode/FloatNode.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeFloatNode() {}
// Cross Module References
	BLUEPRINTTOOLEDITOR_API UClass* Z_Construct_UClass_UDoubleNode();
	BLUEPRINTTOOLEDITOR_API UClass* Z_Construct_UClass_UDoubleNode_NoRegister();
	BLUEPRINTTOOLEDITOR_API UClass* Z_Construct_UClass_UFloatNode();
	BLUEPRINTTOOLEDITOR_API UClass* Z_Construct_UClass_UFloatNode_NoRegister();
	BLUEPRINTTOOLEDITOR_API UClass* Z_Construct_UClass_UVariableNode();
	UPackage* Z_Construct_UPackage__Script_BlueprintToolEditor();
// End Cross Module References
	void UFloatNode::StaticRegisterNativesUFloatNode()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UFloatNode);
	UClass* Z_Construct_UClass_UFloatNode_NoRegister()
	{
		return UFloatNode::StaticClass();
	}
	struct Z_Construct_UClass_UFloatNode_Statics
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
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Value;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UFloatNode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UVariableNode,
		(UObject* (*)())Z_Construct_UPackage__Script_BlueprintToolEditor,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UFloatNode_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UFloatNode_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "BlueprintEditor/GraphNode/FloatNode.h" },
		{ "ModuleRelativePath", "Public/BlueprintEditor/GraphNode/FloatNode.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UFloatNode_Statics::NewProp_VariableName_MetaData[] = {
		{ "Category", "Variable" },
		{ "ModuleRelativePath", "Public/BlueprintEditor/GraphNode/FloatNode.h" },
	};
#endif
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UClass_UFloatNode_Statics::NewProp_VariableName = { "VariableName", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UFloatNode, VariableName), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UFloatNode_Statics::NewProp_VariableName_MetaData), Z_Construct_UClass_UFloatNode_Statics::NewProp_VariableName_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UFloatNode_Statics::NewProp_Value_MetaData[] = {
		{ "Category", "Instance" },
		{ "ModuleRelativePath", "Public/BlueprintEditor/GraphNode/FloatNode.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UFloatNode_Statics::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UFloatNode, Value), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UFloatNode_Statics::NewProp_Value_MetaData), Z_Construct_UClass_UFloatNode_Statics::NewProp_Value_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UFloatNode_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UFloatNode_Statics::NewProp_VariableName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UFloatNode_Statics::NewProp_Value,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UFloatNode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UFloatNode>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UFloatNode_Statics::ClassParams = {
		&UFloatNode::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UFloatNode_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UFloatNode_Statics::PropPointers),
		0,
		0x000000A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UFloatNode_Statics::Class_MetaDataParams), Z_Construct_UClass_UFloatNode_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UFloatNode_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UFloatNode()
	{
		if (!Z_Registration_Info_UClass_UFloatNode.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UFloatNode.OuterSingleton, Z_Construct_UClass_UFloatNode_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UFloatNode.OuterSingleton;
	}
	template<> BLUEPRINTTOOLEDITOR_API UClass* StaticClass<UFloatNode>()
	{
		return UFloatNode::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UFloatNode);
	UFloatNode::~UFloatNode() {}
	void UDoubleNode::StaticRegisterNativesUDoubleNode()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UDoubleNode);
	UClass* Z_Construct_UClass_UDoubleNode_NoRegister()
	{
		return UDoubleNode::StaticClass();
	}
	struct Z_Construct_UClass_UDoubleNode_Statics
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
		static const UECodeGen_Private::FDoublePropertyParams NewProp_Value;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UDoubleNode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UVariableNode,
		(UObject* (*)())Z_Construct_UPackage__Script_BlueprintToolEditor,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDoubleNode_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDoubleNode_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "BlueprintEditor/GraphNode/FloatNode.h" },
		{ "ModuleRelativePath", "Public/BlueprintEditor/GraphNode/FloatNode.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDoubleNode_Statics::NewProp_VariableName_MetaData[] = {
		{ "Category", "Variable" },
		{ "ModuleRelativePath", "Public/BlueprintEditor/GraphNode/FloatNode.h" },
	};
#endif
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UClass_UDoubleNode_Statics::NewProp_VariableName = { "VariableName", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDoubleNode, VariableName), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDoubleNode_Statics::NewProp_VariableName_MetaData), Z_Construct_UClass_UDoubleNode_Statics::NewProp_VariableName_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDoubleNode_Statics::NewProp_Value_MetaData[] = {
		{ "Category", "Instance" },
		{ "ModuleRelativePath", "Public/BlueprintEditor/GraphNode/FloatNode.h" },
	};
#endif
	const UECodeGen_Private::FDoublePropertyParams Z_Construct_UClass_UDoubleNode_Statics::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Double, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDoubleNode, Value), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDoubleNode_Statics::NewProp_Value_MetaData), Z_Construct_UClass_UDoubleNode_Statics::NewProp_Value_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UDoubleNode_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDoubleNode_Statics::NewProp_VariableName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDoubleNode_Statics::NewProp_Value,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UDoubleNode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDoubleNode>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UDoubleNode_Statics::ClassParams = {
		&UDoubleNode::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UDoubleNode_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UDoubleNode_Statics::PropPointers),
		0,
		0x000000A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDoubleNode_Statics::Class_MetaDataParams), Z_Construct_UClass_UDoubleNode_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDoubleNode_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UDoubleNode()
	{
		if (!Z_Registration_Info_UClass_UDoubleNode.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDoubleNode.OuterSingleton, Z_Construct_UClass_UDoubleNode_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UDoubleNode.OuterSingleton;
	}
	template<> BLUEPRINTTOOLEDITOR_API UClass* StaticClass<UDoubleNode>()
	{
		return UDoubleNode::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UDoubleNode);
	UDoubleNode::~UDoubleNode() {}
	struct Z_CompiledInDeferFile_FID_UEProject_TestOSS_Package_BlueprintTool_BlueprintTool_HostProject_Plugins_BlueprintTool_Source_BlueprintToolEditor_Public_BlueprintEditor_GraphNode_FloatNode_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UEProject_TestOSS_Package_BlueprintTool_BlueprintTool_HostProject_Plugins_BlueprintTool_Source_BlueprintToolEditor_Public_BlueprintEditor_GraphNode_FloatNode_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UFloatNode, UFloatNode::StaticClass, TEXT("UFloatNode"), &Z_Registration_Info_UClass_UFloatNode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UFloatNode), 2441505396U) },
		{ Z_Construct_UClass_UDoubleNode, UDoubleNode::StaticClass, TEXT("UDoubleNode"), &Z_Registration_Info_UClass_UDoubleNode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDoubleNode), 2672167777U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UEProject_TestOSS_Package_BlueprintTool_BlueprintTool_HostProject_Plugins_BlueprintTool_Source_BlueprintToolEditor_Public_BlueprintEditor_GraphNode_FloatNode_h_4002741163(TEXT("/Script/BlueprintToolEditor"),
		Z_CompiledInDeferFile_FID_UEProject_TestOSS_Package_BlueprintTool_BlueprintTool_HostProject_Plugins_BlueprintTool_Source_BlueprintToolEditor_Public_BlueprintEditor_GraphNode_FloatNode_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UEProject_TestOSS_Package_BlueprintTool_BlueprintTool_HostProject_Plugins_BlueprintTool_Source_BlueprintToolEditor_Public_BlueprintEditor_GraphNode_FloatNode_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
