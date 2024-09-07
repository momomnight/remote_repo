// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "BlueprintToolCode/Public/SimpleCodeBase.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSimpleCodeBase() {}
// Cross Module References
	BLUEPRINTTOOLCODE_API UClass* Z_Construct_UClass_USimpleCode();
	BLUEPRINTTOOLCODE_API UClass* Z_Construct_UClass_USimpleCodeBase();
	BLUEPRINTTOOLCODE_API UClass* Z_Construct_UClass_USimpleCodeBase_NoRegister();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FLinearColor();
	UPackage* Z_Construct_UPackage__Script_BlueprintToolCode();
// End Cross Module References
	DEFINE_FUNCTION(USimpleCodeBase::execSetObject)
	{
		P_GET_OBJECT(UObject,Z_Param_Context);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UObject**)Z_Param__Result=USimpleCodeBase::SetObject(Z_Param_Context);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USimpleCodeBase::execSetByte)
	{
		P_GET_PROPERTY(FByteProperty,Z_Param_Context);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(uint8*)Z_Param__Result=USimpleCodeBase::SetByte(Z_Param_Context);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USimpleCodeBase::execSetColor)
	{
		P_GET_STRUCT(FLinearColor,Z_Param_Context);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FLinearColor*)Z_Param__Result=USimpleCodeBase::SetColor(Z_Param_Context);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USimpleCodeBase::execSetName)
	{
		P_GET_PROPERTY(FNameProperty,Z_Param_Context);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FName*)Z_Param__Result=USimpleCodeBase::SetName(Z_Param_Context);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USimpleCodeBase::execSetText)
	{
		P_GET_PROPERTY(FTextProperty,Z_Param_Context);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FText*)Z_Param__Result=USimpleCodeBase::SetText(Z_Param_Context);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USimpleCodeBase::execSetInt32)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_Context);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int32*)Z_Param__Result=USimpleCodeBase::SetInt32(Z_Param_Context);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USimpleCodeBase::execSetFloat)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_Context);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(float*)Z_Param__Result=USimpleCodeBase::SetFloat(Z_Param_Context);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USimpleCodeBase::execSetBool)
	{
		P_GET_UBOOL(Z_Param_Context);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=USimpleCodeBase::SetBool(Z_Param_Context);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USimpleCodeBase::execSetString)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_Context);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=USimpleCodeBase::SetString(Z_Param_Context);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USimpleCodeBase::execPrintString)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_String);
		P_FINISH;
		P_NATIVE_BEGIN;
		USimpleCodeBase::PrintString(Z_Param_String);
		P_NATIVE_END;
	}
	void USimpleCodeBase::StaticRegisterNativesUSimpleCodeBase()
	{
		UClass* Class = USimpleCodeBase::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "PrintString", &USimpleCodeBase::execPrintString },
			{ "SetBool", &USimpleCodeBase::execSetBool },
			{ "SetByte", &USimpleCodeBase::execSetByte },
			{ "SetColor", &USimpleCodeBase::execSetColor },
			{ "SetFloat", &USimpleCodeBase::execSetFloat },
			{ "SetInt32", &USimpleCodeBase::execSetInt32 },
			{ "SetName", &USimpleCodeBase::execSetName },
			{ "SetObject", &USimpleCodeBase::execSetObject },
			{ "SetString", &USimpleCodeBase::execSetString },
			{ "SetText", &USimpleCodeBase::execSetText },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_USimpleCodeBase_PrintString_Statics
	{
		struct SimpleCodeBase_eventPrintString_Parms
		{
			FString String;
		};
		static const UECodeGen_Private::FStrPropertyParams NewProp_String;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_USimpleCodeBase_PrintString_Statics::NewProp_String = { "String", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SimpleCodeBase_eventPrintString_Parms, String), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USimpleCodeBase_PrintString_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimpleCodeBase_PrintString_Statics::NewProp_String,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USimpleCodeBase_PrintString_Statics::Function_MetaDataParams[] = {
		{ "CodeType", "Description" },
		{ "Comment", "//\xef\xbf\xbd\xef\xbf\xbd\xd3\xa1\n" },
		{ "Group", "SimpleCode" },
		{ "ModuleRelativePath", "Public/SimpleCodeBase.h" },
		{ "ToolTip", "\xef\xbf\xbd\xef\xbf\xbd\xd3\xa1" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USimpleCodeBase_PrintString_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USimpleCodeBase, nullptr, "PrintString", nullptr, nullptr, Z_Construct_UFunction_USimpleCodeBase_PrintString_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleCodeBase_PrintString_Statics::PropPointers), sizeof(Z_Construct_UFunction_USimpleCodeBase_PrintString_Statics::SimpleCodeBase_eventPrintString_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleCodeBase_PrintString_Statics::Function_MetaDataParams), Z_Construct_UFunction_USimpleCodeBase_PrintString_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleCodeBase_PrintString_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_USimpleCodeBase_PrintString_Statics::SimpleCodeBase_eventPrintString_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_USimpleCodeBase_PrintString()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USimpleCodeBase_PrintString_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USimpleCodeBase_SetBool_Statics
	{
		struct SimpleCodeBase_eventSetBool_Parms
		{
			bool Context;
			bool ReturnValue;
		};
		static void NewProp_Context_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_Context;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_USimpleCodeBase_SetBool_Statics::NewProp_Context_SetBit(void* Obj)
	{
		((SimpleCodeBase_eventSetBool_Parms*)Obj)->Context = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USimpleCodeBase_SetBool_Statics::NewProp_Context = { "Context", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(SimpleCodeBase_eventSetBool_Parms), &Z_Construct_UFunction_USimpleCodeBase_SetBool_Statics::NewProp_Context_SetBit, METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_USimpleCodeBase_SetBool_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((SimpleCodeBase_eventSetBool_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USimpleCodeBase_SetBool_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(SimpleCodeBase_eventSetBool_Parms), &Z_Construct_UFunction_USimpleCodeBase_SetBool_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USimpleCodeBase_SetBool_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimpleCodeBase_SetBool_Statics::NewProp_Context,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimpleCodeBase_SetBool_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USimpleCodeBase_SetBool_Statics::Function_MetaDataParams[] = {
		{ "CodeType", "PureDescription" },
		{ "Group", "BasicVariables" },
		{ "ModuleRelativePath", "Public/SimpleCodeBase.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USimpleCodeBase_SetBool_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USimpleCodeBase, nullptr, "SetBool", nullptr, nullptr, Z_Construct_UFunction_USimpleCodeBase_SetBool_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleCodeBase_SetBool_Statics::PropPointers), sizeof(Z_Construct_UFunction_USimpleCodeBase_SetBool_Statics::SimpleCodeBase_eventSetBool_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleCodeBase_SetBool_Statics::Function_MetaDataParams), Z_Construct_UFunction_USimpleCodeBase_SetBool_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleCodeBase_SetBool_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_USimpleCodeBase_SetBool_Statics::SimpleCodeBase_eventSetBool_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_USimpleCodeBase_SetBool()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USimpleCodeBase_SetBool_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USimpleCodeBase_SetByte_Statics
	{
		struct SimpleCodeBase_eventSetByte_Parms
		{
			uint8 Context;
			uint8 ReturnValue;
		};
		static const UECodeGen_Private::FBytePropertyParams NewProp_Context;
		static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_USimpleCodeBase_SetByte_Statics::NewProp_Context = { "Context", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SimpleCodeBase_eventSetByte_Parms, Context), nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_USimpleCodeBase_SetByte_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SimpleCodeBase_eventSetByte_Parms, ReturnValue), nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USimpleCodeBase_SetByte_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimpleCodeBase_SetByte_Statics::NewProp_Context,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimpleCodeBase_SetByte_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USimpleCodeBase_SetByte_Statics::Function_MetaDataParams[] = {
		{ "CodeType", "PureDescription" },
		{ "Group", "BasicVariables" },
		{ "ModuleRelativePath", "Public/SimpleCodeBase.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USimpleCodeBase_SetByte_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USimpleCodeBase, nullptr, "SetByte", nullptr, nullptr, Z_Construct_UFunction_USimpleCodeBase_SetByte_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleCodeBase_SetByte_Statics::PropPointers), sizeof(Z_Construct_UFunction_USimpleCodeBase_SetByte_Statics::SimpleCodeBase_eventSetByte_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleCodeBase_SetByte_Statics::Function_MetaDataParams), Z_Construct_UFunction_USimpleCodeBase_SetByte_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleCodeBase_SetByte_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_USimpleCodeBase_SetByte_Statics::SimpleCodeBase_eventSetByte_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_USimpleCodeBase_SetByte()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USimpleCodeBase_SetByte_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USimpleCodeBase_SetColor_Statics
	{
		struct SimpleCodeBase_eventSetColor_Parms
		{
			FLinearColor Context;
			FLinearColor ReturnValue;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_Context;
		static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USimpleCodeBase_SetColor_Statics::NewProp_Context = { "Context", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SimpleCodeBase_eventSetColor_Parms, Context), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USimpleCodeBase_SetColor_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SimpleCodeBase_eventSetColor_Parms, ReturnValue), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USimpleCodeBase_SetColor_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimpleCodeBase_SetColor_Statics::NewProp_Context,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimpleCodeBase_SetColor_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USimpleCodeBase_SetColor_Statics::Function_MetaDataParams[] = {
		{ "CodeType", "PureDescription" },
		{ "Group", "BasicVariables" },
		{ "ModuleRelativePath", "Public/SimpleCodeBase.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USimpleCodeBase_SetColor_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USimpleCodeBase, nullptr, "SetColor", nullptr, nullptr, Z_Construct_UFunction_USimpleCodeBase_SetColor_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleCodeBase_SetColor_Statics::PropPointers), sizeof(Z_Construct_UFunction_USimpleCodeBase_SetColor_Statics::SimpleCodeBase_eventSetColor_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00822401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleCodeBase_SetColor_Statics::Function_MetaDataParams), Z_Construct_UFunction_USimpleCodeBase_SetColor_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleCodeBase_SetColor_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_USimpleCodeBase_SetColor_Statics::SimpleCodeBase_eventSetColor_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_USimpleCodeBase_SetColor()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USimpleCodeBase_SetColor_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USimpleCodeBase_SetFloat_Statics
	{
		struct SimpleCodeBase_eventSetFloat_Parms
		{
			float Context;
			float ReturnValue;
		};
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Context;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_USimpleCodeBase_SetFloat_Statics::NewProp_Context = { "Context", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SimpleCodeBase_eventSetFloat_Parms, Context), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_USimpleCodeBase_SetFloat_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SimpleCodeBase_eventSetFloat_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USimpleCodeBase_SetFloat_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimpleCodeBase_SetFloat_Statics::NewProp_Context,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimpleCodeBase_SetFloat_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USimpleCodeBase_SetFloat_Statics::Function_MetaDataParams[] = {
		{ "CodeType", "PureDescription" },
		{ "Group", "BasicVariables" },
		{ "ModuleRelativePath", "Public/SimpleCodeBase.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USimpleCodeBase_SetFloat_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USimpleCodeBase, nullptr, "SetFloat", nullptr, nullptr, Z_Construct_UFunction_USimpleCodeBase_SetFloat_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleCodeBase_SetFloat_Statics::PropPointers), sizeof(Z_Construct_UFunction_USimpleCodeBase_SetFloat_Statics::SimpleCodeBase_eventSetFloat_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleCodeBase_SetFloat_Statics::Function_MetaDataParams), Z_Construct_UFunction_USimpleCodeBase_SetFloat_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleCodeBase_SetFloat_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_USimpleCodeBase_SetFloat_Statics::SimpleCodeBase_eventSetFloat_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_USimpleCodeBase_SetFloat()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USimpleCodeBase_SetFloat_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USimpleCodeBase_SetInt32_Statics
	{
		struct SimpleCodeBase_eventSetInt32_Parms
		{
			int32 Context;
			int32 ReturnValue;
		};
		static const UECodeGen_Private::FIntPropertyParams NewProp_Context;
		static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_USimpleCodeBase_SetInt32_Statics::NewProp_Context = { "Context", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SimpleCodeBase_eventSetInt32_Parms, Context), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_USimpleCodeBase_SetInt32_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SimpleCodeBase_eventSetInt32_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USimpleCodeBase_SetInt32_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimpleCodeBase_SetInt32_Statics::NewProp_Context,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimpleCodeBase_SetInt32_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USimpleCodeBase_SetInt32_Statics::Function_MetaDataParams[] = {
		{ "CodeType", "PureDescription" },
		{ "Group", "BasicVariables" },
		{ "ModuleRelativePath", "Public/SimpleCodeBase.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USimpleCodeBase_SetInt32_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USimpleCodeBase, nullptr, "SetInt32", nullptr, nullptr, Z_Construct_UFunction_USimpleCodeBase_SetInt32_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleCodeBase_SetInt32_Statics::PropPointers), sizeof(Z_Construct_UFunction_USimpleCodeBase_SetInt32_Statics::SimpleCodeBase_eventSetInt32_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleCodeBase_SetInt32_Statics::Function_MetaDataParams), Z_Construct_UFunction_USimpleCodeBase_SetInt32_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleCodeBase_SetInt32_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_USimpleCodeBase_SetInt32_Statics::SimpleCodeBase_eventSetInt32_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_USimpleCodeBase_SetInt32()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USimpleCodeBase_SetInt32_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USimpleCodeBase_SetName_Statics
	{
		struct SimpleCodeBase_eventSetName_Parms
		{
			FName Context;
			FName ReturnValue;
		};
		static const UECodeGen_Private::FNamePropertyParams NewProp_Context;
		static const UECodeGen_Private::FNamePropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_USimpleCodeBase_SetName_Statics::NewProp_Context = { "Context", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SimpleCodeBase_eventSetName_Parms, Context), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_USimpleCodeBase_SetName_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SimpleCodeBase_eventSetName_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USimpleCodeBase_SetName_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimpleCodeBase_SetName_Statics::NewProp_Context,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimpleCodeBase_SetName_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USimpleCodeBase_SetName_Statics::Function_MetaDataParams[] = {
		{ "CodeType", "PureDescription" },
		{ "Group", "BasicVariables" },
		{ "ModuleRelativePath", "Public/SimpleCodeBase.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USimpleCodeBase_SetName_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USimpleCodeBase, nullptr, "SetName", nullptr, nullptr, Z_Construct_UFunction_USimpleCodeBase_SetName_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleCodeBase_SetName_Statics::PropPointers), sizeof(Z_Construct_UFunction_USimpleCodeBase_SetName_Statics::SimpleCodeBase_eventSetName_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleCodeBase_SetName_Statics::Function_MetaDataParams), Z_Construct_UFunction_USimpleCodeBase_SetName_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleCodeBase_SetName_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_USimpleCodeBase_SetName_Statics::SimpleCodeBase_eventSetName_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_USimpleCodeBase_SetName()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USimpleCodeBase_SetName_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USimpleCodeBase_SetObject_Statics
	{
		struct SimpleCodeBase_eventSetObject_Parms
		{
			UObject* Context;
			UObject* ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Context;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USimpleCodeBase_SetObject_Statics::NewProp_Context = { "Context", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SimpleCodeBase_eventSetObject_Parms, Context), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USimpleCodeBase_SetObject_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SimpleCodeBase_eventSetObject_Parms, ReturnValue), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USimpleCodeBase_SetObject_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimpleCodeBase_SetObject_Statics::NewProp_Context,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimpleCodeBase_SetObject_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USimpleCodeBase_SetObject_Statics::Function_MetaDataParams[] = {
		{ "CodeType", "PureDescription" },
		{ "Group", "BasicVariables" },
		{ "ModuleRelativePath", "Public/SimpleCodeBase.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USimpleCodeBase_SetObject_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USimpleCodeBase, nullptr, "SetObject", nullptr, nullptr, Z_Construct_UFunction_USimpleCodeBase_SetObject_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleCodeBase_SetObject_Statics::PropPointers), sizeof(Z_Construct_UFunction_USimpleCodeBase_SetObject_Statics::SimpleCodeBase_eventSetObject_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleCodeBase_SetObject_Statics::Function_MetaDataParams), Z_Construct_UFunction_USimpleCodeBase_SetObject_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleCodeBase_SetObject_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_USimpleCodeBase_SetObject_Statics::SimpleCodeBase_eventSetObject_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_USimpleCodeBase_SetObject()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USimpleCodeBase_SetObject_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USimpleCodeBase_SetString_Statics
	{
		struct SimpleCodeBase_eventSetString_Parms
		{
			FString Context;
			FString ReturnValue;
		};
		static const UECodeGen_Private::FStrPropertyParams NewProp_Context;
		static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_USimpleCodeBase_SetString_Statics::NewProp_Context = { "Context", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SimpleCodeBase_eventSetString_Parms, Context), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_USimpleCodeBase_SetString_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SimpleCodeBase_eventSetString_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USimpleCodeBase_SetString_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimpleCodeBase_SetString_Statics::NewProp_Context,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimpleCodeBase_SetString_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USimpleCodeBase_SetString_Statics::Function_MetaDataParams[] = {
		{ "CodeType", "PureDescription" },
		{ "Group", "BasicVariables" },
		{ "ModuleRelativePath", "Public/SimpleCodeBase.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USimpleCodeBase_SetString_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USimpleCodeBase, nullptr, "SetString", nullptr, nullptr, Z_Construct_UFunction_USimpleCodeBase_SetString_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleCodeBase_SetString_Statics::PropPointers), sizeof(Z_Construct_UFunction_USimpleCodeBase_SetString_Statics::SimpleCodeBase_eventSetString_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleCodeBase_SetString_Statics::Function_MetaDataParams), Z_Construct_UFunction_USimpleCodeBase_SetString_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleCodeBase_SetString_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_USimpleCodeBase_SetString_Statics::SimpleCodeBase_eventSetString_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_USimpleCodeBase_SetString()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USimpleCodeBase_SetString_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USimpleCodeBase_SetText_Statics
	{
		struct SimpleCodeBase_eventSetText_Parms
		{
			FText Context;
			FText ReturnValue;
		};
		static const UECodeGen_Private::FTextPropertyParams NewProp_Context;
		static const UECodeGen_Private::FTextPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FTextPropertyParams Z_Construct_UFunction_USimpleCodeBase_SetText_Statics::NewProp_Context = { "Context", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SimpleCodeBase_eventSetText_Parms, Context), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FTextPropertyParams Z_Construct_UFunction_USimpleCodeBase_SetText_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SimpleCodeBase_eventSetText_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USimpleCodeBase_SetText_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimpleCodeBase_SetText_Statics::NewProp_Context,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimpleCodeBase_SetText_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USimpleCodeBase_SetText_Statics::Function_MetaDataParams[] = {
		{ "CodeType", "PureDescription" },
		{ "Group", "BasicVariables" },
		{ "ModuleRelativePath", "Public/SimpleCodeBase.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USimpleCodeBase_SetText_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USimpleCodeBase, nullptr, "SetText", nullptr, nullptr, Z_Construct_UFunction_USimpleCodeBase_SetText_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleCodeBase_SetText_Statics::PropPointers), sizeof(Z_Construct_UFunction_USimpleCodeBase_SetText_Statics::SimpleCodeBase_eventSetText_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleCodeBase_SetText_Statics::Function_MetaDataParams), Z_Construct_UFunction_USimpleCodeBase_SetText_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleCodeBase_SetText_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_USimpleCodeBase_SetText_Statics::SimpleCodeBase_eventSetText_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_USimpleCodeBase_SetText()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USimpleCodeBase_SetText_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(USimpleCodeBase);
	UClass* Z_Construct_UClass_USimpleCodeBase_NoRegister()
	{
		return USimpleCodeBase::StaticClass();
	}
	struct Z_Construct_UClass_USimpleCodeBase_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_USimpleCodeBase_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_USimpleCode,
		(UObject* (*)())Z_Construct_UPackage__Script_BlueprintToolCode,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_USimpleCodeBase_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_USimpleCodeBase_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_USimpleCodeBase_PrintString, "PrintString" }, // 321433033
		{ &Z_Construct_UFunction_USimpleCodeBase_SetBool, "SetBool" }, // 3485315972
		{ &Z_Construct_UFunction_USimpleCodeBase_SetByte, "SetByte" }, // 3641297996
		{ &Z_Construct_UFunction_USimpleCodeBase_SetColor, "SetColor" }, // 891116029
		{ &Z_Construct_UFunction_USimpleCodeBase_SetFloat, "SetFloat" }, // 639262919
		{ &Z_Construct_UFunction_USimpleCodeBase_SetInt32, "SetInt32" }, // 1345157580
		{ &Z_Construct_UFunction_USimpleCodeBase_SetName, "SetName" }, // 442444717
		{ &Z_Construct_UFunction_USimpleCodeBase_SetObject, "SetObject" }, // 3105731205
		{ &Z_Construct_UFunction_USimpleCodeBase_SetString, "SetString" }, // 4254110669
		{ &Z_Construct_UFunction_USimpleCodeBase_SetText, "SetText" }, // 1470109515
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_USimpleCodeBase_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USimpleCodeBase_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "SimpleCodeBase.h" },
		{ "ModuleRelativePath", "Public/SimpleCodeBase.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_USimpleCodeBase_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USimpleCodeBase>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_USimpleCodeBase_Statics::ClassParams = {
		&USimpleCodeBase::StaticClass,
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
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_USimpleCodeBase_Statics::Class_MetaDataParams), Z_Construct_UClass_USimpleCodeBase_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_USimpleCodeBase()
	{
		if (!Z_Registration_Info_UClass_USimpleCodeBase.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_USimpleCodeBase.OuterSingleton, Z_Construct_UClass_USimpleCodeBase_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_USimpleCodeBase.OuterSingleton;
	}
	template<> BLUEPRINTTOOLCODE_API UClass* StaticClass<USimpleCodeBase>()
	{
		return USimpleCodeBase::StaticClass();
	}
	USimpleCodeBase::USimpleCodeBase(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(USimpleCodeBase);
	USimpleCodeBase::~USimpleCodeBase() {}
	struct Z_CompiledInDeferFile_FID_UEProject_TestOSS_Package_BlueprintTool_BlueprintTool_HostProject_Plugins_BlueprintTool_Source_BlueprintToolCode_Public_SimpleCodeBase_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UEProject_TestOSS_Package_BlueprintTool_BlueprintTool_HostProject_Plugins_BlueprintTool_Source_BlueprintToolCode_Public_SimpleCodeBase_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_USimpleCodeBase, USimpleCodeBase::StaticClass, TEXT("USimpleCodeBase"), &Z_Registration_Info_UClass_USimpleCodeBase, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(USimpleCodeBase), 3890172515U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UEProject_TestOSS_Package_BlueprintTool_BlueprintTool_HostProject_Plugins_BlueprintTool_Source_BlueprintToolCode_Public_SimpleCodeBase_h_1487901490(TEXT("/Script/BlueprintToolCode"),
		Z_CompiledInDeferFile_FID_UEProject_TestOSS_Package_BlueprintTool_BlueprintTool_HostProject_Plugins_BlueprintTool_Source_BlueprintToolCode_Public_SimpleCodeBase_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UEProject_TestOSS_Package_BlueprintTool_BlueprintTool_HostProject_Plugins_BlueprintTool_Source_BlueprintToolCode_Public_SimpleCodeBase_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
