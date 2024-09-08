#include "Compile/BTFunctionContext.h"
#include "UObject\UnrealType.h"
#include "UObject\Class.h"
#include "EdGraph\EdGraphNode.h"
#include <type_traits>

#if PLATFORM_WINDOWS
#pragma optimize("", off)
#endif // PLATFORM_WINDOWS


struct Helper
{
	static	bool IsSpecifiedTerminal(TSharedPtr<FFunctionTerminal> Terminal, FProperty* InProperty, EEdGraphPinDirection Direction)
	{
		if (Terminal->Name == InProperty->GetFName() && Direction == Terminal->Direction)
		{
			return true;
		}
		return false;
	}

};

TArray<TSharedPtr<FFunctionTerminal>> FBTFunctionContext::FindRecursive(TArray<TSharedPtr<FFunctionTerminal>>& InTerminals, UEdGraphNode* InGraphNode)
{
	for (auto& FinishedTerminal : InTerminals)
	{
		if (FinishedTerminal->IsLink())
		{
			//连接的纯节点与查询的节点相同
			if (FinishedTerminal->PureNode == InGraphNode)
			{
				return FinishedTerminal->NodeTerminal;
			}
			else
			{
				//连接的纯节点与查询的节点不同，则继续递归查找
				TArray<TSharedPtr<FFunctionTerminal>> Result = FindRecursive(FinishedTerminal->NodeTerminal, InGraphNode);
				if (!Result.IsEmpty())
				{
					return Result;
				}
			}
		}
	}
	return TArray<TSharedPtr<FFunctionTerminal>>();
}

TArray<TSharedPtr<FFunctionTerminal>> FBTFunctionContext::Find(UEdGraphNode* InGraphNode)
{
	check(InGraphNode);
	for (auto& TempTerminals : TerminalMap)
	{
		if (TempTerminals.Key == InGraphNode)
		{
			return TempTerminals.Value;
		}
		else
		{
			//如果节点不同，则递归查找
			// InGraphNode 需要查找的节点
			// TempTerminals.Value 当前节点对应的端子
			// InProperty 需要查找的属性
			TArray<TSharedPtr<FFunctionTerminal>> Result = FindRecursive(TempTerminals.Value, InGraphNode);
			if (!Result.IsEmpty())
			{
				return Result;
			}
		}
	}
	return TArray<TSharedPtr<FFunctionTerminal>>();
}

TArray<TSharedPtr<FFunctionTerminal>> FBTFunctionContext::FindTerminalByName(UEdGraphNode* InGraphNode, FName Name)
{
	check(InGraphNode);

	TArray<TSharedPtr<FFunctionTerminal>> TerminalArray = Find(InGraphNode);
	TArray<TSharedPtr<FFunctionTerminal>> Result;
	for (auto& Temp : TerminalArray)
	{
		if (Temp->Name == Name)
		{
			Result.Add(Temp);
		}
	}
	return Result;
}

TSharedPtr<FFunctionTerminal> FBTFunctionContext::FindTerminalByProperty(UEdGraphNode* InGraphNode, FProperty* InProperty,
	EEdGraphPinDirection Direction)
{
	check(InGraphNode && InProperty);
	TArray<TSharedPtr<FFunctionTerminal>> Result = FindTerminalByName(InGraphNode, InProperty->GetFName());

	for (auto& Temp : Result)
	{
		if (Temp->Direction == Direction)
		{
			return Temp;
		}
	}

	return nullptr;
}

TArray<TSharedPtr<FFunctionTerminal>> FBTFunctionContext::FindTerminalArrayByProperty(UEdGraphNode* InGraphNode, 
	FProperty* InProperty)
{
	check(InGraphNode && InProperty);
	return FindTerminalByName(InGraphNode, InProperty->GetFName());
}

TSharedPtr<FFunctionTerminal> FBTFunctionContext::FindTerminalByPin(UEdGraphNode* InGraphNode, UEdGraphPin* Pin,
	EEdGraphPinDirection Direction)
{
	check(InGraphNode && Pin);
	TArray<TSharedPtr<FFunctionTerminal>> Result = Find(InGraphNode);

	for (auto& Temp : Result)
	{
		if (Pin->GetFName() == Temp->Name && Temp->Direction == Direction)
		{
			return Temp;
		}
	}

	return nullptr;
}

TArray<TSharedPtr<FFunctionTerminal>> FBTFunctionContext::FindTerminalArrayByPin(class UEdGraphNode* InGraphNode,
	UEdGraphPin* Pin)
{
	check(InGraphNode && Pin);
	return FindTerminalByName(InGraphNode, Pin->GetFName());
}


#if PLATFORM_WINDOWS
#pragma optimize("", on)
#endif // PLATFORM_WINDOWS