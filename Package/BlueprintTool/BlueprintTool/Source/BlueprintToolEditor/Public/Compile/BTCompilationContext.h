#pragma once


#include "CoreMinimal.h"
#include "Compile\BTFunctionContext.h"


class FBTCompilationContext
{
public:

	TIndirectArray<FBTFunctionContext> FunctionList;

	void GetCurrentParamTerminal(TArray<TSharedPtr<struct FFunctionTerminal>>& Terminals, class UEdGraphPin* InPin);

	void CompileFunction(FBTFunctionContext& FunctionContext);

};