
#include "Compile/BTCompilationUtilities.h"
#include "Compile/BTCompilationContext.h"
#include "Compile/BTFunctionContext.h"
#include "Type/BlueprintTypeEType.h"
#include "EdGraph\EdGraphNode.h"
#include "EdGraph\EdGraph.h"
#include "BlueprintData.h"


#include "BlueprintEditor/Core/Architect/K3Node.h"
#include "SimpleCodeLibrary.h"

#if PLATFORM_WINDOWS
#pragma optimize("", off)
#endif // PLATFORM_WINDOWS


TArray<UEdGraphNode*> GetEventRoot(UEdGraph* EdGraph)
{
	TArray<UEdGraphNode*> EventRoot;
	for (auto& TempNode : EdGraph->Nodes)
	{
		if (UK3Node* RootNode = Cast<UK3Node>(TempNode))
		{
			if (UFunction* Function = RootNode->Function)
			{
				if (Function->GetMetaData("CodeType") == "Event")
				{
					EventRoot.Add(RootNode);
				}
			}
		}
	}
	return EventRoot;
}

void TraverseNodes(UEdGraphNode* Node, TArray<UEdGraphNode*>& VisitedNodeList)
{
	//将所有Exec连接的节点加入集合
	VisitedNodeList.Add(Node);
	for (const UEdGraphPin* TempPin : Node->Pins)
	{
		if ((TempPin->Direction == EGPD_Output) &&
			(TempPin->PinType.PinCategory == FPC_Public::PC_Exec))
		{
			for (const UEdGraphPin* LinkedPin : TempPin->LinkedTo)//如果是多分支节点呢?会形成多段在同一TArray中
			{
				if (LinkedPin)
				{
					UEdGraphNode* OtherNode = LinkedPin->GetOwningNode();
					if (!VisitedNodeList.Contains(OtherNode))
					{
						TraverseNodes(OtherNode, VisitedNodeList);
					}
				}
			}
		}
	}
}

//修剪
void PruneIsolatedNodes(const TArray<UEdGraphNode*>& RootSet, TArray<TArray<UEdGraphNode*>>& GraphNodes)
{
	for (auto& TempRootNode : RootSet)
	{
		GraphNodes.Add(TArray<UEdGraphNode*>());
		TraverseNodes(TempRootNode, GraphNodes.Last());
	}
}

//UEdGraphNode节点都是通过SchemaAction创建，并与UFunction和UProperty做了关联
void FBTCompilationUtilities::FlushCompilationQueueImpl(UBlueprintData* Data)
{
	check(Data && Data->EdGraph);

	TArray<UEdGraphNode*> RootSet = GetEventRoot(Data->EdGraph);
	if (RootSet.Num() > 0)
	{
		//阶段一, 修剪蓝图, 去掉独立无连接的节点
		TArray<TArray<UEdGraphNode*>> VisitedNodes;
		PruneIsolatedNodes(RootSet, VisitedNodes);

		FBTCompilationContext CompilationContext;
		for (auto& GraphNodeArray : VisitedNodes)
		{
			//阶段二, 清空所有字节码
			for (auto& GraphNode : GraphNodeArray)
			{
				UK3Node* K3Node = Cast<UK3Node>(GraphNode);
				K3Node->Function->Script.Empty();

				//阶段三, 注册脚本函数, 方便自定义的UBT工具查询
				UBTScriptObject::RegisteredFunctionList.Add(K3Node->Function);
			}

			//阶段四, 构建函数编译环境
			FBTFunctionContext BTFunctionContext;
			BTFunctionContext.LinearExecutionList = GraphNodeArray;
			CompilationContext.CompileFunction(BTFunctionContext);
		}
	}
}


#if PLATFORM_WINDOWS
#pragma optimize("", on)
#endif // PLATFORM_WINDOWS
