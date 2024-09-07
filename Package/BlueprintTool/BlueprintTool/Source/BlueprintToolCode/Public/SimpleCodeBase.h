#pragma once


#include "CoreMinimal.h"
#include "SimpleCode.h"
#include "ReflectionData/SimpleCodeBase.Reflect.h"
#include "SimpleCodeBase.generated.h"

#if PLATFORM_WINDOWS
#pragma optimize("",off) 
#endif

UCLASS()
class BLUEPRINTTOOLCODE_API USimpleCodeBase : public USimpleCode
{
	GENERATED_BODY()
public:
	GENERATED_BT_BODY()
public:

	//��ӡ
	UFUNCTION(Meta = (CodeType = "Description", Group = "SimpleCode"))
		static void PrintString(FString String);

	UFUNCTION(Meta = (CodeType = "PureDescription", Group = "BasicVariables"))
		static FString SetString(FString Context);

	UFUNCTION(Meta = (CodeType = "PureDescription", Group = "BasicVariables"))
		static bool SetBool(bool Context);

	UFUNCTION(Meta = (CodeType = "PureDescription", Group = "BasicVariables"))
		static float SetFloat(float Context);

	UFUNCTION(Meta = (CodeType = "PureDescription", Group = "BasicVariables"))
		static int32 SetInt32(int32 Context);

	UFUNCTION(Meta = (CodeType = "PureDescription", Group = "BasicVariables"))
		static FText SetText(FText Context);

	UFUNCTION(Meta = (CodeType = "PureDescription", Group = "BasicVariables"))
		static FName SetName(FName Context);

	UFUNCTION(Meta = (CodeType = "PureDescription", Group = "BasicVariables"))
		static FLinearColor SetColor(FLinearColor Context);

	UFUNCTION(Meta = (CodeType = "PureDescription", Group = "BasicVariables"))
		static uint8 SetByte(uint8 Context);

	UFUNCTION(Meta = (CodeType = "PureDescription", Group = "BasicVariables"))
		static UObject* SetObject(UObject *Context);
};

#if PLATFORM_WINDOWS
#pragma optimize("",on) 
#endif