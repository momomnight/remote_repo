// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "BlueprintToolEditor/Public/BlueprintEditor/GraphNode/ByteNode.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeByteNode() {}
// Cross Module References
	BLUEPRINTTOOLEDITOR_API UClass* Z_Construct_UClass_UByteNode();
	BLUEPRINTTOOLEDITOR_API UClass* Z_Construct_UClass_UByteNode_NoRegister();
	BLUEPRINTTOOLEDITOR_API UClass* Z_Construct_UClass_UVariableNode();
	UPackage* Z_Construct_UPackage__Script_BlueprintToolEditor();
// End Cross Module References
	void UByteNode::StaticRegisterNativesUByteNode()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UByteNode);
	UClass* Z_Construct_UClass_UByteNode_NoRegister()
	{
		return UByteNode::StaticClass();
	}
	struct Z_Construct_UClass_UByteNode_Statics
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
		static const UECodeGen_Private::FBytePropertyParams NewProp_Value;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UByteNode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UVariableNode,
		(UObject* (*)())Z_Construct_UPackage__Script_BlueprintToolEditor,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UByteNode_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UByteNode_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "BlueprintEditor/GraphNode/ByteNode.h" },
		{ "ModuleRelativePath", "Public/BlueprintEditor/GraphNode/ByteNode.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UByteNode_Statics::NewProp_VariableName_MetaData[] = {
		{ "Category", "Variable" },
		{ "ModuleRelativePath", "Public/BlueprintEditor/GraphNode/ByteNode.h" },
	};
#endif
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UClass_UByteNode_Statics::NewProp_VariableName = { "VariableName", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UByteNode, VariableName), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UByteNode_Statics::NewProp_VariableName_MetaData), Z_Construct_UClass_UByteNode_Statics::NewProp_VariableName_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UByteNode_Statics::NewProp_Value_MetaData[] = {
		{ "Category", "Instance" },
		{ "ModuleRelativePath", "Public/BlueprintEditor/GraphNode/ByteNode.h" },
	};
#endif
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UByteNode_Statics::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UByteNode, Value), nullptr, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UByteNode_Statics::NewProp_Value_MetaData), Z_Construct_UClass_UByteNode_Statics::NewProp_Value_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UByteNode_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UByteNode_Statics::NewProp_VariableName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UByteNode_Statics::NewProp_Value,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UByteNode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UByteNode>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UByteNode_Statics::ClassParams = {
		&UByteNode::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UByteNode_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UByteNode_Statics::PropPointers),
		0,
		0x000000A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UByteNode_Statics::Class_MetaDataParams), Z_Construct_UClass_UByteNode_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UByteNode_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UByteNode()
	{
		if (!Z_Registration_Info_UClass_UByteNode.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UByteNode.OuterSingleton, Z_Construct_UClass_UByteNode_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UByteNode.OuterSingleton;
	}
	template<> BLUEPRINTTOOLEDITOR_API UClass* StaticClass<UByteNode>()
	{
		return UByteNode::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UByteNode);
	UByteNode::~UByteNode() {}
	struct Z_CompiledInDeferFile_FID_UEProject_TestOSS_Package_BlueprintTool_BlueprintTool_HostProject_Plugins_BlueprintTool_Source_BlueprintToolEditor_Public_BlueprintEditor_GraphNode_ByteNode_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UEProject_TestOSS_Package_BlueprintTool_BlueprintTool_HostProject_Plugins_BlueprintTool_Source_BlueprintToolEditor_Public_BlueprintEditor_GraphNode_ByteNode_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UByteNode, UByteNode::StaticClass, TEXT("UByteNode"), &Z_Registration_Info_UClass_UByteNode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UByteNode), 3375166952U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UEProject_TestOSS_Package_BlueprintTool_BlueprintTool_HostProject_Plugins_BlueprintTool_Source_BlueprintToolEditor_Public_BlueprintEditor_GraphNode_ByteNode_h_2908294575(TEXT("/Script/BlueprintToolEditor"),
		Z_CompiledInDeferFile_FID_UEProject_TestOSS_Package_BlueprintTool_BlueprintTool_HostProject_Plugins_BlueprintTool_Source_BlueprintToolEditor_Public_BlueprintEditor_GraphNode_ByteNode_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UEProject_TestOSS_Package_BlueprintTool_BlueprintTool_HostProject_Plugins_BlueprintTool_Source_BlueprintToolEditor_Public_BlueprintEditor_GraphNode_ByteNode_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
