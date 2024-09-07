// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "BlueprintToolRuntime/Public/BlueprintData.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBlueprintData() {}
// Cross Module References
	BLUEPRINTTOOLRUNTIME_API UClass* Z_Construct_UClass_UBlueprintData();
	BLUEPRINTTOOLRUNTIME_API UClass* Z_Construct_UClass_UBlueprintData_NoRegister();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	ENGINE_API UClass* Z_Construct_UClass_UEdGraph_NoRegister();
	UPackage* Z_Construct_UPackage__Script_BlueprintToolRuntime();
// End Cross Module References
	void UBlueprintData::StaticRegisterNativesUBlueprintData()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UBlueprintData);
	UClass* Z_Construct_UClass_UBlueprintData_NoRegister()
	{
		return UBlueprintData::StaticClass();
	}
	struct Z_Construct_UClass_UBlueprintData_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_EDITORONLY_DATA
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_EdGraph_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_EdGraph;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#endif // WITH_EDITORONLY_DATA
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UBlueprintData_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_BlueprintToolRuntime,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UBlueprintData_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UBlueprintData_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/*\n*  UBlueprintData\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xda\xb1\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xcd\xbc\xca\xb5\xef\xbf\xbd\xef\xbf\xbdUEdGraph\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xd0\xbb\xef\xbf\xbd\xef\xbf\xbd\xeb\xb7\xb4\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xd0\xbb\xef\xbf\xbd\n*/" },
		{ "IncludePath", "BlueprintData.h" },
		{ "ModuleRelativePath", "Public/BlueprintData.h" },
		{ "ToolTip", "*  UBlueprintData\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xda\xb1\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xcd\xbc\xca\xb5\xef\xbf\xbd\xef\xbf\xbdUEdGraph\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xd0\xbb\xef\xbf\xbd\xef\xbf\xbd\xeb\xb7\xb4\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xd0\xbb\xef\xbf\xbd" },
	};
#endif
#if WITH_EDITORONLY_DATA
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UBlueprintData_Statics::NewProp_EdGraph_MetaData[] = {
		{ "ModuleRelativePath", "Public/BlueprintData.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UBlueprintData_Statics::NewProp_EdGraph = { "EdGraph", nullptr, (EPropertyFlags)0x0010000800000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UBlueprintData, EdGraph), Z_Construct_UClass_UEdGraph_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UBlueprintData_Statics::NewProp_EdGraph_MetaData), Z_Construct_UClass_UBlueprintData_Statics::NewProp_EdGraph_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UBlueprintData_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UBlueprintData_Statics::NewProp_EdGraph,
	};
#endif // WITH_EDITORONLY_DATA
	const FCppClassTypeInfoStatic Z_Construct_UClass_UBlueprintData_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UBlueprintData>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UBlueprintData_Statics::ClassParams = {
		&UBlueprintData::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		IF_WITH_EDITORONLY_DATA(Z_Construct_UClass_UBlueprintData_Statics::PropPointers, nullptr),
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		IF_WITH_EDITORONLY_DATA(UE_ARRAY_COUNT(Z_Construct_UClass_UBlueprintData_Statics::PropPointers), 0),
		0,
		0x001000A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UBlueprintData_Statics::Class_MetaDataParams), Z_Construct_UClass_UBlueprintData_Statics::Class_MetaDataParams)
	};
#if WITH_EDITORONLY_DATA
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UBlueprintData_Statics::PropPointers) < 2048);
#endif
	UClass* Z_Construct_UClass_UBlueprintData()
	{
		if (!Z_Registration_Info_UClass_UBlueprintData.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UBlueprintData.OuterSingleton, Z_Construct_UClass_UBlueprintData_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UBlueprintData.OuterSingleton;
	}
	template<> BLUEPRINTTOOLRUNTIME_API UClass* StaticClass<UBlueprintData>()
	{
		return UBlueprintData::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UBlueprintData);
	UBlueprintData::~UBlueprintData() {}
	struct Z_CompiledInDeferFile_FID_UEProject_TestOSS_Package_BlueprintTool_BlueprintTool_HostProject_Plugins_BlueprintTool_Source_BlueprintToolRuntime_Public_BlueprintData_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UEProject_TestOSS_Package_BlueprintTool_BlueprintTool_HostProject_Plugins_BlueprintTool_Source_BlueprintToolRuntime_Public_BlueprintData_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UBlueprintData, UBlueprintData::StaticClass, TEXT("UBlueprintData"), &Z_Registration_Info_UClass_UBlueprintData, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UBlueprintData), 1603411300U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UEProject_TestOSS_Package_BlueprintTool_BlueprintTool_HostProject_Plugins_BlueprintTool_Source_BlueprintToolRuntime_Public_BlueprintData_h_226112928(TEXT("/Script/BlueprintToolRuntime"),
		Z_CompiledInDeferFile_FID_UEProject_TestOSS_Package_BlueprintTool_BlueprintTool_HostProject_Plugins_BlueprintTool_Source_BlueprintToolRuntime_Public_BlueprintData_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UEProject_TestOSS_Package_BlueprintTool_BlueprintTool_HostProject_Plugins_BlueprintTool_Source_BlueprintToolRuntime_Public_BlueprintData_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
