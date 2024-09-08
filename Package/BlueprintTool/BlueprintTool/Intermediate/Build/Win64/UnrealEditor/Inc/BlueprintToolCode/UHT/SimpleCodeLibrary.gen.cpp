// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "BlueprintToolCode/Public/SimpleCodeLibrary.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSimpleCodeLibrary() {}
// Cross Module References
	BLUEPRINTTOOLCODE_API UClass* Z_Construct_UClass_USimpleCode();
	BLUEPRINTTOOLCODE_API UClass* Z_Construct_UClass_USimpleCodeLibrary();
	BLUEPRINTTOOLCODE_API UClass* Z_Construct_UClass_USimpleCodeLibrary_NoRegister();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FLinearColor();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FRotator();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	ENGINE_API UClass* Z_Construct_UClass_UMaterialInterface_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMesh_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
	UPackage* Z_Construct_UPackage__Script_BlueprintToolCode();
// End Cross Module References
	DEFINE_FUNCTION(USimpleCodeLibrary::execSetMaterialColor)
	{
		P_GET_OBJECT(UStaticMeshComponent,Z_Param_MeshComponent);
		P_GET_PROPERTY(FNameProperty,Z_Param_ColorName);
		P_GET_STRUCT(FLinearColor,Z_Param_Color);
		P_GET_PROPERTY(FIntProperty,Z_Param_MaterialIndex);
		P_FINISH;
		P_NATIVE_BEGIN;
		USimpleCodeLibrary::SetMaterialColor(Z_Param_MeshComponent,Z_Param_ColorName,Z_Param_Color,Z_Param_MaterialIndex);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USimpleCodeLibrary::execSetMaterial)
	{
		P_GET_OBJECT(UStaticMeshComponent,Z_Param_MeshComponent);
		P_GET_PROPERTY(FIntProperty,Z_Param_Index);
		P_GET_OBJECT(UMaterialInterface,Z_Param_InMaterial);
		P_FINISH;
		P_NATIVE_BEGIN;
		USimpleCodeLibrary::SetMaterial(Z_Param_MeshComponent,Z_Param_Index,Z_Param_InMaterial);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USimpleCodeLibrary::execSetMesh)
	{
		P_GET_OBJECT(UStaticMeshComponent,Z_Param_MeshComponent);
		P_GET_OBJECT(UStaticMesh,Z_Param_InMesh);
		P_FINISH;
		P_NATIVE_BEGIN;
		USimpleCodeLibrary::SetMesh(Z_Param_MeshComponent,Z_Param_InMesh);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USimpleCodeLibrary::execSetRotation)
	{
		P_GET_OBJECT(UStaticMeshComponent,Z_Param_MeshComponent);
		P_GET_STRUCT(FRotator,Z_Param_InRotation);
		P_FINISH;
		P_NATIVE_BEGIN;
		USimpleCodeLibrary::SetRotation(Z_Param_MeshComponent,Z_Param_InRotation);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USimpleCodeLibrary::execSetLocation)
	{
		P_GET_OBJECT(UStaticMeshComponent,Z_Param_MeshComponent);
		P_GET_STRUCT(FVector,Z_Param_InLocation);
		P_FINISH;
		P_NATIVE_BEGIN;
		USimpleCodeLibrary::SetLocation(Z_Param_MeshComponent,Z_Param_InLocation);
		P_NATIVE_END;
	}
	void USimpleCodeLibrary::StaticRegisterNativesUSimpleCodeLibrary()
	{
		UClass* Class = USimpleCodeLibrary::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "SetLocation", &USimpleCodeLibrary::execSetLocation },
			{ "SetMaterial", &USimpleCodeLibrary::execSetMaterial },
			{ "SetMaterialColor", &USimpleCodeLibrary::execSetMaterialColor },
			{ "SetMesh", &USimpleCodeLibrary::execSetMesh },
			{ "SetRotation", &USimpleCodeLibrary::execSetRotation },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_USimpleCodeLibrary_SetLocation_Statics
	{
		struct SimpleCodeLibrary_eventSetLocation_Parms
		{
			UStaticMeshComponent* MeshComponent;
			FVector InLocation;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MeshComponent_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_MeshComponent;
		static const UECodeGen_Private::FStructPropertyParams NewProp_InLocation;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USimpleCodeLibrary_SetLocation_Statics::NewProp_MeshComponent_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USimpleCodeLibrary_SetLocation_Statics::NewProp_MeshComponent = { "MeshComponent", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SimpleCodeLibrary_eventSetLocation_Parms, MeshComponent), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleCodeLibrary_SetLocation_Statics::NewProp_MeshComponent_MetaData), Z_Construct_UFunction_USimpleCodeLibrary_SetLocation_Statics::NewProp_MeshComponent_MetaData) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USimpleCodeLibrary_SetLocation_Statics::NewProp_InLocation = { "InLocation", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SimpleCodeLibrary_eventSetLocation_Parms, InLocation), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USimpleCodeLibrary_SetLocation_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimpleCodeLibrary_SetLocation_Statics::NewProp_MeshComponent,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimpleCodeLibrary_SetLocation_Statics::NewProp_InLocation,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USimpleCodeLibrary_SetLocation_Statics::Function_MetaDataParams[] = {
		{ "CodeType", "Description" },
		{ "Group", "SimpleCodeLibrary" },
		{ "ModuleRelativePath", "Public/SimpleCodeLibrary.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USimpleCodeLibrary_SetLocation_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USimpleCodeLibrary, nullptr, "SetLocation", nullptr, nullptr, Z_Construct_UFunction_USimpleCodeLibrary_SetLocation_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleCodeLibrary_SetLocation_Statics::PropPointers), sizeof(Z_Construct_UFunction_USimpleCodeLibrary_SetLocation_Statics::SimpleCodeLibrary_eventSetLocation_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00822401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleCodeLibrary_SetLocation_Statics::Function_MetaDataParams), Z_Construct_UFunction_USimpleCodeLibrary_SetLocation_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleCodeLibrary_SetLocation_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_USimpleCodeLibrary_SetLocation_Statics::SimpleCodeLibrary_eventSetLocation_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_USimpleCodeLibrary_SetLocation()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USimpleCodeLibrary_SetLocation_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USimpleCodeLibrary_SetMaterial_Statics
	{
		struct SimpleCodeLibrary_eventSetMaterial_Parms
		{
			UStaticMeshComponent* MeshComponent;
			int32 Index;
			UMaterialInterface* InMaterial;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MeshComponent_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_MeshComponent;
		static const UECodeGen_Private::FIntPropertyParams NewProp_Index;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_InMaterial;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USimpleCodeLibrary_SetMaterial_Statics::NewProp_MeshComponent_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USimpleCodeLibrary_SetMaterial_Statics::NewProp_MeshComponent = { "MeshComponent", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SimpleCodeLibrary_eventSetMaterial_Parms, MeshComponent), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleCodeLibrary_SetMaterial_Statics::NewProp_MeshComponent_MetaData), Z_Construct_UFunction_USimpleCodeLibrary_SetMaterial_Statics::NewProp_MeshComponent_MetaData) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_USimpleCodeLibrary_SetMaterial_Statics::NewProp_Index = { "Index", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SimpleCodeLibrary_eventSetMaterial_Parms, Index), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USimpleCodeLibrary_SetMaterial_Statics::NewProp_InMaterial = { "InMaterial", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SimpleCodeLibrary_eventSetMaterial_Parms, InMaterial), Z_Construct_UClass_UMaterialInterface_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USimpleCodeLibrary_SetMaterial_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimpleCodeLibrary_SetMaterial_Statics::NewProp_MeshComponent,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimpleCodeLibrary_SetMaterial_Statics::NewProp_Index,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimpleCodeLibrary_SetMaterial_Statics::NewProp_InMaterial,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USimpleCodeLibrary_SetMaterial_Statics::Function_MetaDataParams[] = {
		{ "CodeType", "Description" },
		{ "Group", "SimpleCodeLibrary" },
		{ "ModuleRelativePath", "Public/SimpleCodeLibrary.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USimpleCodeLibrary_SetMaterial_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USimpleCodeLibrary, nullptr, "SetMaterial", nullptr, nullptr, Z_Construct_UFunction_USimpleCodeLibrary_SetMaterial_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleCodeLibrary_SetMaterial_Statics::PropPointers), sizeof(Z_Construct_UFunction_USimpleCodeLibrary_SetMaterial_Statics::SimpleCodeLibrary_eventSetMaterial_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleCodeLibrary_SetMaterial_Statics::Function_MetaDataParams), Z_Construct_UFunction_USimpleCodeLibrary_SetMaterial_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleCodeLibrary_SetMaterial_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_USimpleCodeLibrary_SetMaterial_Statics::SimpleCodeLibrary_eventSetMaterial_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_USimpleCodeLibrary_SetMaterial()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USimpleCodeLibrary_SetMaterial_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USimpleCodeLibrary_SetMaterialColor_Statics
	{
		struct SimpleCodeLibrary_eventSetMaterialColor_Parms
		{
			UStaticMeshComponent* MeshComponent;
			FName ColorName;
			FLinearColor Color;
			int32 MaterialIndex;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MeshComponent_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_MeshComponent;
		static const UECodeGen_Private::FNamePropertyParams NewProp_ColorName;
		static const UECodeGen_Private::FStructPropertyParams NewProp_Color;
		static const UECodeGen_Private::FIntPropertyParams NewProp_MaterialIndex;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USimpleCodeLibrary_SetMaterialColor_Statics::NewProp_MeshComponent_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USimpleCodeLibrary_SetMaterialColor_Statics::NewProp_MeshComponent = { "MeshComponent", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SimpleCodeLibrary_eventSetMaterialColor_Parms, MeshComponent), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleCodeLibrary_SetMaterialColor_Statics::NewProp_MeshComponent_MetaData), Z_Construct_UFunction_USimpleCodeLibrary_SetMaterialColor_Statics::NewProp_MeshComponent_MetaData) };
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_USimpleCodeLibrary_SetMaterialColor_Statics::NewProp_ColorName = { "ColorName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SimpleCodeLibrary_eventSetMaterialColor_Parms, ColorName), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USimpleCodeLibrary_SetMaterialColor_Statics::NewProp_Color = { "Color", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SimpleCodeLibrary_eventSetMaterialColor_Parms, Color), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_USimpleCodeLibrary_SetMaterialColor_Statics::NewProp_MaterialIndex = { "MaterialIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SimpleCodeLibrary_eventSetMaterialColor_Parms, MaterialIndex), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USimpleCodeLibrary_SetMaterialColor_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimpleCodeLibrary_SetMaterialColor_Statics::NewProp_MeshComponent,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimpleCodeLibrary_SetMaterialColor_Statics::NewProp_ColorName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimpleCodeLibrary_SetMaterialColor_Statics::NewProp_Color,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimpleCodeLibrary_SetMaterialColor_Statics::NewProp_MaterialIndex,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USimpleCodeLibrary_SetMaterialColor_Statics::Function_MetaDataParams[] = {
		{ "CodeType", "Description" },
		{ "Group", "SimpleCodeLibrary" },
		{ "ModuleRelativePath", "Public/SimpleCodeLibrary.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USimpleCodeLibrary_SetMaterialColor_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USimpleCodeLibrary, nullptr, "SetMaterialColor", nullptr, nullptr, Z_Construct_UFunction_USimpleCodeLibrary_SetMaterialColor_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleCodeLibrary_SetMaterialColor_Statics::PropPointers), sizeof(Z_Construct_UFunction_USimpleCodeLibrary_SetMaterialColor_Statics::SimpleCodeLibrary_eventSetMaterialColor_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00822401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleCodeLibrary_SetMaterialColor_Statics::Function_MetaDataParams), Z_Construct_UFunction_USimpleCodeLibrary_SetMaterialColor_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleCodeLibrary_SetMaterialColor_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_USimpleCodeLibrary_SetMaterialColor_Statics::SimpleCodeLibrary_eventSetMaterialColor_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_USimpleCodeLibrary_SetMaterialColor()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USimpleCodeLibrary_SetMaterialColor_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USimpleCodeLibrary_SetMesh_Statics
	{
		struct SimpleCodeLibrary_eventSetMesh_Parms
		{
			UStaticMeshComponent* MeshComponent;
			UStaticMesh* InMesh;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MeshComponent_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_MeshComponent;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_InMesh;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USimpleCodeLibrary_SetMesh_Statics::NewProp_MeshComponent_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USimpleCodeLibrary_SetMesh_Statics::NewProp_MeshComponent = { "MeshComponent", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SimpleCodeLibrary_eventSetMesh_Parms, MeshComponent), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleCodeLibrary_SetMesh_Statics::NewProp_MeshComponent_MetaData), Z_Construct_UFunction_USimpleCodeLibrary_SetMesh_Statics::NewProp_MeshComponent_MetaData) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USimpleCodeLibrary_SetMesh_Statics::NewProp_InMesh = { "InMesh", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SimpleCodeLibrary_eventSetMesh_Parms, InMesh), Z_Construct_UClass_UStaticMesh_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USimpleCodeLibrary_SetMesh_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimpleCodeLibrary_SetMesh_Statics::NewProp_MeshComponent,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimpleCodeLibrary_SetMesh_Statics::NewProp_InMesh,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USimpleCodeLibrary_SetMesh_Statics::Function_MetaDataParams[] = {
		{ "CodeType", "Description" },
		{ "Group", "SimpleCodeLibrary" },
		{ "ModuleRelativePath", "Public/SimpleCodeLibrary.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USimpleCodeLibrary_SetMesh_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USimpleCodeLibrary, nullptr, "SetMesh", nullptr, nullptr, Z_Construct_UFunction_USimpleCodeLibrary_SetMesh_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleCodeLibrary_SetMesh_Statics::PropPointers), sizeof(Z_Construct_UFunction_USimpleCodeLibrary_SetMesh_Statics::SimpleCodeLibrary_eventSetMesh_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleCodeLibrary_SetMesh_Statics::Function_MetaDataParams), Z_Construct_UFunction_USimpleCodeLibrary_SetMesh_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleCodeLibrary_SetMesh_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_USimpleCodeLibrary_SetMesh_Statics::SimpleCodeLibrary_eventSetMesh_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_USimpleCodeLibrary_SetMesh()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USimpleCodeLibrary_SetMesh_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USimpleCodeLibrary_SetRotation_Statics
	{
		struct SimpleCodeLibrary_eventSetRotation_Parms
		{
			UStaticMeshComponent* MeshComponent;
			FRotator InRotation;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MeshComponent_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_MeshComponent;
		static const UECodeGen_Private::FStructPropertyParams NewProp_InRotation;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USimpleCodeLibrary_SetRotation_Statics::NewProp_MeshComponent_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USimpleCodeLibrary_SetRotation_Statics::NewProp_MeshComponent = { "MeshComponent", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SimpleCodeLibrary_eventSetRotation_Parms, MeshComponent), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleCodeLibrary_SetRotation_Statics::NewProp_MeshComponent_MetaData), Z_Construct_UFunction_USimpleCodeLibrary_SetRotation_Statics::NewProp_MeshComponent_MetaData) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USimpleCodeLibrary_SetRotation_Statics::NewProp_InRotation = { "InRotation", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SimpleCodeLibrary_eventSetRotation_Parms, InRotation), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USimpleCodeLibrary_SetRotation_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimpleCodeLibrary_SetRotation_Statics::NewProp_MeshComponent,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimpleCodeLibrary_SetRotation_Statics::NewProp_InRotation,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USimpleCodeLibrary_SetRotation_Statics::Function_MetaDataParams[] = {
		{ "CodeType", "Description" },
		{ "Group", "SimpleCodeLibrary" },
		{ "ModuleRelativePath", "Public/SimpleCodeLibrary.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USimpleCodeLibrary_SetRotation_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USimpleCodeLibrary, nullptr, "SetRotation", nullptr, nullptr, Z_Construct_UFunction_USimpleCodeLibrary_SetRotation_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleCodeLibrary_SetRotation_Statics::PropPointers), sizeof(Z_Construct_UFunction_USimpleCodeLibrary_SetRotation_Statics::SimpleCodeLibrary_eventSetRotation_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00822401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleCodeLibrary_SetRotation_Statics::Function_MetaDataParams), Z_Construct_UFunction_USimpleCodeLibrary_SetRotation_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleCodeLibrary_SetRotation_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_USimpleCodeLibrary_SetRotation_Statics::SimpleCodeLibrary_eventSetRotation_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_USimpleCodeLibrary_SetRotation()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USimpleCodeLibrary_SetRotation_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(USimpleCodeLibrary);
	UClass* Z_Construct_UClass_USimpleCodeLibrary_NoRegister()
	{
		return USimpleCodeLibrary::StaticClass();
	}
	struct Z_Construct_UClass_USimpleCodeLibrary_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_USimpleCodeLibrary_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_USimpleCode,
		(UObject* (*)())Z_Construct_UPackage__Script_BlueprintToolCode,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_USimpleCodeLibrary_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_USimpleCodeLibrary_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_USimpleCodeLibrary_SetLocation, "SetLocation" }, // 4086409370
		{ &Z_Construct_UFunction_USimpleCodeLibrary_SetMaterial, "SetMaterial" }, // 203465292
		{ &Z_Construct_UFunction_USimpleCodeLibrary_SetMaterialColor, "SetMaterialColor" }, // 3106236574
		{ &Z_Construct_UFunction_USimpleCodeLibrary_SetMesh, "SetMesh" }, // 1150338432
		{ &Z_Construct_UFunction_USimpleCodeLibrary_SetRotation, "SetRotation" }, // 2709215826
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_USimpleCodeLibrary_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USimpleCodeLibrary_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "SimpleCodeLibrary.h" },
		{ "ModuleRelativePath", "Public/SimpleCodeLibrary.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_USimpleCodeLibrary_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USimpleCodeLibrary>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_USimpleCodeLibrary_Statics::ClassParams = {
		&USimpleCodeLibrary::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		0,
		0,
		0x001000A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_USimpleCodeLibrary_Statics::Class_MetaDataParams), Z_Construct_UClass_USimpleCodeLibrary_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_USimpleCodeLibrary()
	{
		if (!Z_Registration_Info_UClass_USimpleCodeLibrary.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_USimpleCodeLibrary.OuterSingleton, Z_Construct_UClass_USimpleCodeLibrary_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_USimpleCodeLibrary.OuterSingleton;
	}
	template<> BLUEPRINTTOOLCODE_API UClass* StaticClass<USimpleCodeLibrary>()
	{
		return USimpleCodeLibrary::StaticClass();
	}
	USimpleCodeLibrary::USimpleCodeLibrary(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(USimpleCodeLibrary);
	USimpleCodeLibrary::~USimpleCodeLibrary() {}
	struct Z_CompiledInDeferFile_FID_UEProject_TestOSS_Package_BlueprintTool_BlueprintTool_HostProject_Plugins_BlueprintTool_Source_BlueprintToolCode_Public_SimpleCodeLibrary_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UEProject_TestOSS_Package_BlueprintTool_BlueprintTool_HostProject_Plugins_BlueprintTool_Source_BlueprintToolCode_Public_SimpleCodeLibrary_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_USimpleCodeLibrary, USimpleCodeLibrary::StaticClass, TEXT("USimpleCodeLibrary"), &Z_Registration_Info_UClass_USimpleCodeLibrary, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(USimpleCodeLibrary), 968850346U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UEProject_TestOSS_Package_BlueprintTool_BlueprintTool_HostProject_Plugins_BlueprintTool_Source_BlueprintToolCode_Public_SimpleCodeLibrary_h_2520719025(TEXT("/Script/BlueprintToolCode"),
		Z_CompiledInDeferFile_FID_UEProject_TestOSS_Package_BlueprintTool_BlueprintTool_HostProject_Plugins_BlueprintTool_Source_BlueprintToolCode_Public_SimpleCodeLibrary_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UEProject_TestOSS_Package_BlueprintTool_BlueprintTool_HostProject_Plugins_BlueprintTool_Source_BlueprintToolCode_Public_SimpleCodeLibrary_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
