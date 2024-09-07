// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "BlueprintToolEditor/Public/BlueprintEditor/GraphNode/BooleanNode.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBooleanNode() {}
// Cross Module References
	BLUEPRINTTOOLEDITOR_API UClass* Z_Construct_UClass_UBooleanNode();
	BLUEPRINTTOOLEDITOR_API UClass* Z_Construct_UClass_UBooleanNode_NoRegister();
	BLUEPRINTTOOLEDITOR_API UClass* Z_Construct_UClass_UVariableNode();
	UPackage* Z_Construct_UPackage__Script_BlueprintToolEditor();
// End Cross Module References
	void UBooleanNode::StaticRegisterNativesUBooleanNode()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UBooleanNode);
	UClass* Z_Construct_UClass_UBooleanNode_NoRegister()
	{
		return UBooleanNode::StaticClass();
	}
	struct Z_Construct_UClass_UBooleanNode_Statics
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
		static void NewProp_Value_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_Value;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UBooleanNode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UVariableNode,
		(UObject* (*)())Z_Construct_UPackage__Script_BlueprintToolEditor,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UBooleanNode_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UBooleanNode_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "BlueprintEditor/GraphNode/BooleanNode.h" },
		{ "ModuleRelativePath", "Public/BlueprintEditor/GraphNode/BooleanNode.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UBooleanNode_Statics::NewProp_VariableName_MetaData[] = {
		{ "Category", "Variable" },
		{ "ModuleRelativePath", "Public/BlueprintEditor/GraphNode/BooleanNode.h" },
	};
#endif
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UClass_UBooleanNode_Statics::NewProp_VariableName = { "VariableName", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UBooleanNode, VariableName), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UBooleanNode_Statics::NewProp_VariableName_MetaData), Z_Construct_UClass_UBooleanNode_Statics::NewProp_VariableName_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UBooleanNode_Statics::NewProp_Value_MetaData[] = {
		{ "Category", "Instance" },
		{ "ModuleRelativePath", "Public/BlueprintEditor/GraphNode/BooleanNode.h" },
	};
#endif
	void Z_Construct_UClass_UBooleanNode_Statics::NewProp_Value_SetBit(void* Obj)
	{
		((UBooleanNode*)Obj)->Value = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UBooleanNode_Statics::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UBooleanNode), &Z_Construct_UClass_UBooleanNode_Statics::NewProp_Value_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UBooleanNode_Statics::NewProp_Value_MetaData), Z_Construct_UClass_UBooleanNode_Statics::NewProp_Value_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UBooleanNode_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UBooleanNode_Statics::NewProp_VariableName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UBooleanNode_Statics::NewProp_Value,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UBooleanNode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UBooleanNode>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UBooleanNode_Statics::ClassParams = {
		&UBooleanNode::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UBooleanNode_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UBooleanNode_Statics::PropPointers),
		0,
		0x000000A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UBooleanNode_Statics::Class_MetaDataParams), Z_Construct_UClass_UBooleanNode_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UBooleanNode_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UBooleanNode()
	{
		if (!Z_Registration_Info_UClass_UBooleanNode.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UBooleanNode.OuterSingleton, Z_Construct_UClass_UBooleanNode_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UBooleanNode.OuterSingleton;
	}
	template<> BLUEPRINTTOOLEDITOR_API UClass* StaticClass<UBooleanNode>()
	{
		return UBooleanNode::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UBooleanNode);
	UBooleanNode::~UBooleanNode() {}
	struct Z_CompiledInDeferFile_FID_UEProject_TestOSS_Package_BlueprintTool_BlueprintTool_HostProject_Plugins_BlueprintTool_Source_BlueprintToolEditor_Public_BlueprintEditor_GraphNode_BooleanNode_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UEProject_TestOSS_Package_BlueprintTool_BlueprintTool_HostProject_Plugins_BlueprintTool_Source_BlueprintToolEditor_Public_BlueprintEditor_GraphNode_BooleanNode_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UBooleanNode, UBooleanNode::StaticClass, TEXT("UBooleanNode"), &Z_Registration_Info_UClass_UBooleanNode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UBooleanNode), 1371591932U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UEProject_TestOSS_Package_BlueprintTool_BlueprintTool_HostProject_Plugins_BlueprintTool_Source_BlueprintToolEditor_Public_BlueprintEditor_GraphNode_BooleanNode_h_2461976908(TEXT("/Script/BlueprintToolEditor"),
		Z_CompiledInDeferFile_FID_UEProject_TestOSS_Package_BlueprintTool_BlueprintTool_HostProject_Plugins_BlueprintTool_Source_BlueprintToolEditor_Public_BlueprintEditor_GraphNode_BooleanNode_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UEProject_TestOSS_Package_BlueprintTool_BlueprintTool_HostProject_Plugins_BlueprintTool_Source_BlueprintToolEditor_Public_BlueprintEditor_GraphNode_BooleanNode_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
