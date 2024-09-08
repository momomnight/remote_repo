// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "BlueprintToolEditor/Public/BlueprintEditor/Core/Architect/K3Node.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeK3Node() {}
// Cross Module References
	BLUEPRINTTOOLEDITOR_API UClass* Z_Construct_UClass_UK3Node();
	BLUEPRINTTOOLEDITOR_API UClass* Z_Construct_UClass_UK3Node_NoRegister();
	COREUOBJECT_API UClass* Z_Construct_UClass_UFunction();
	ENGINE_API UClass* Z_Construct_UClass_UEdGraphNode();
	UPackage* Z_Construct_UPackage__Script_BlueprintToolEditor();
// End Cross Module References
	void UK3Node::StaticRegisterNativesUK3Node()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UK3Node);
	UClass* Z_Construct_UClass_UK3Node_NoRegister()
	{
		return UK3Node::StaticClass();
	}
	struct Z_Construct_UClass_UK3Node_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Function_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Function;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Property_MetaData[];
#endif
		static const UECodeGen_Private::FFieldPathPropertyParams NewProp_Property;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_NodeTitle_MetaData[];
#endif
		static const UECodeGen_Private::FTextPropertyParams NewProp_NodeTitle;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UK3Node_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UEdGraphNode,
		(UObject* (*)())Z_Construct_UPackage__Script_BlueprintToolEditor,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UK3Node_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UK3Node_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "BlueprintEditor/Core/Architect/K3Node.h" },
		{ "ModuleRelativePath", "Public/BlueprintEditor/Core/Architect/K3Node.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UK3Node_Statics::NewProp_Function_MetaData[] = {
		{ "ModuleRelativePath", "Public/BlueprintEditor/Core/Architect/K3Node.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UK3Node_Statics::NewProp_Function = { "Function", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UK3Node, Function), Z_Construct_UClass_UFunction, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UK3Node_Statics::NewProp_Function_MetaData), Z_Construct_UClass_UK3Node_Statics::NewProp_Function_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UK3Node_Statics::NewProp_Property_MetaData[] = {
		{ "ModuleRelativePath", "Public/BlueprintEditor/Core/Architect/K3Node.h" },
	};
#endif
	const UECodeGen_Private::FFieldPathPropertyParams Z_Construct_UClass_UK3Node_Statics::NewProp_Property = { "Property", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::FieldPath, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UK3Node, Property), &FProperty::StaticClass, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UK3Node_Statics::NewProp_Property_MetaData), Z_Construct_UClass_UK3Node_Statics::NewProp_Property_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UK3Node_Statics::NewProp_NodeTitle_MetaData[] = {
		{ "ModuleRelativePath", "Public/BlueprintEditor/Core/Architect/K3Node.h" },
	};
#endif
	const UECodeGen_Private::FTextPropertyParams Z_Construct_UClass_UK3Node_Statics::NewProp_NodeTitle = { "NodeTitle", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UK3Node, NodeTitle), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UK3Node_Statics::NewProp_NodeTitle_MetaData), Z_Construct_UClass_UK3Node_Statics::NewProp_NodeTitle_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UK3Node_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UK3Node_Statics::NewProp_Function,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UK3Node_Statics::NewProp_Property,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UK3Node_Statics::NewProp_NodeTitle,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UK3Node_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UK3Node>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UK3Node_Statics::ClassParams = {
		&UK3Node::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UK3Node_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UK3Node_Statics::PropPointers),
		0,
		0x000800A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UK3Node_Statics::Class_MetaDataParams), Z_Construct_UClass_UK3Node_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UK3Node_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UK3Node()
	{
		if (!Z_Registration_Info_UClass_UK3Node.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UK3Node.OuterSingleton, Z_Construct_UClass_UK3Node_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UK3Node.OuterSingleton;
	}
	template<> BLUEPRINTTOOLEDITOR_API UClass* StaticClass<UK3Node>()
	{
		return UK3Node::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UK3Node);
	UK3Node::~UK3Node() {}
	struct Z_CompiledInDeferFile_FID_UEProject_TestOSS_Package_BlueprintTool_BlueprintTool_HostProject_Plugins_BlueprintTool_Source_BlueprintToolEditor_Public_BlueprintEditor_Core_Architect_K3Node_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UEProject_TestOSS_Package_BlueprintTool_BlueprintTool_HostProject_Plugins_BlueprintTool_Source_BlueprintToolEditor_Public_BlueprintEditor_Core_Architect_K3Node_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UK3Node, UK3Node::StaticClass, TEXT("UK3Node"), &Z_Registration_Info_UClass_UK3Node, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UK3Node), 436192259U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UEProject_TestOSS_Package_BlueprintTool_BlueprintTool_HostProject_Plugins_BlueprintTool_Source_BlueprintToolEditor_Public_BlueprintEditor_Core_Architect_K3Node_h_3953128617(TEXT("/Script/BlueprintToolEditor"),
		Z_CompiledInDeferFile_FID_UEProject_TestOSS_Package_BlueprintTool_BlueprintTool_HostProject_Plugins_BlueprintTool_Source_BlueprintToolEditor_Public_BlueprintEditor_Core_Architect_K3Node_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UEProject_TestOSS_Package_BlueprintTool_BlueprintTool_HostProject_Plugins_BlueprintTool_Source_BlueprintToolEditor_Public_BlueprintEditor_Core_Architect_K3Node_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
