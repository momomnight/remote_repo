#pragma once


#include "CoreMinimal.h"
#include "Compile/BTBlueprintCompiledStatement.h"
#include "Compile/BTTerminal.h"


class FBTFunctionContext
{

public:
	TArray<class UEdGraphNode*> LinearExecutionList;

	TMap<class UEdGraphNode*, EVMStatementType> ListVMStatement;

	TMap<class UEdGraphNode*, TArray<TSharedPtr<FFunctionTerminal>>> TerminalMap;

public:

	TArray<TSharedPtr<FFunctionTerminal>> Find(class UEdGraphNode* InGraphNode);

	TArray<TSharedPtr<FFunctionTerminal>> FindTerminalByName(class UEdGraphNode* InGraphNode, FName Name);

	//一个属性可以对应两个以上Pin
	TSharedPtr<FFunctionTerminal> FindTerminalByProperty(class UEdGraphNode* InGraphNode, class FProperty* InProperty, EEdGraphPinDirection Direction);

	TArray<TSharedPtr<FFunctionTerminal>> FindTerminalArrayByProperty(class UEdGraphNode* InGraphNode, class FProperty* InProperty);

	TSharedPtr<FFunctionTerminal> FindTerminalByPin(class UEdGraphNode* InGraphNode, UEdGraphPin* Pin,
		EEdGraphPinDirection Direction);

	TArray<TSharedPtr<FFunctionTerminal>> FindTerminalArrayByPin(class UEdGraphNode* InGraphNode,
		UEdGraphPin* Pin);

private:

	TArray<TSharedPtr<FFunctionTerminal>> FindRecursive(TArray<TSharedPtr<FFunctionTerminal>>& InTerminals, 
		UEdGraphNode* InGraphNode);
};