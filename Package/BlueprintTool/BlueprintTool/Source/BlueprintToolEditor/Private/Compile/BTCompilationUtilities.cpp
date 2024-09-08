
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
	//������Exec���ӵĽڵ���뼯��
	VisitedNodeList.Add(Node);
	for (const UEdGraphPin* TempPin : Node->Pins)
	{
		if ((TempPin->Direction == EGPD_Output) &&
			(TempPin->PinType.PinCategory == FPC_Public::PC_Exec))
		{
			for (const UEdGraphPin* LinkedPin : TempPin->LinkedTo)//����Ƕ��֧�ڵ���?���γɶ����ͬһTArray��
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

//�޼�
void PruneIsolatedNodes(const TArray<UEdGraphNode*>& RootSet, TArray<TArray<UEdGraphNode*>>& GraphNodes)
{
	for (auto& TempRootNode : RootSet)
	{
		GraphNodes.Add(TArray<UEdGraphNode*>());
		TraverseNodes(TempRootNode, GraphNodes.Last());
	}
}

//UEdGraphNode�ڵ㶼��ͨ��SchemaAction����������UFunction��UProperty���˹���
void FBTCompilationUtilities::FlushCompilationQueueImpl(UBlueprintData* Data)
{
	check(Data && Data->EdGraph);

	TArray<UEdGraphNode*> RootSet = GetEventRoot(Data->EdGraph);
	if (RootSet.Num() > 0)
	{
		//�׶�һ, �޼���ͼ, ȥ�����������ӵĽڵ�
		TArray<TArray<UEdGraphNode*>> VisitedNodes;
		PruneIsolatedNodes(RootSet, VisitedNodes);

		FBTCompilationContext CompilationContext;
		for (auto& GraphNodeArray : VisitedNodes)
		{
			//�׶ζ�, ��������ֽ���
			for (auto& GraphNode : GraphNodeArray)
			{
				UK3Node* K3Node = Cast<UK3Node>(GraphNode);
				K3Node->Function->Script.Empty();

				//�׶���, ע��ű�����, �����Զ����UBT���߲�ѯ
				UBTScriptObject::RegisteredFunctionList.Add(K3Node->Function);
			}

			//�׶���, �����������뻷��
			FBTFunctionContext BTFunctionContext;
			BTFunctionContext.LinearExecutionList = GraphNodeArray;
			CompilationContext.CompileFunction(BTFunctionContext);
		}
	}
}


#if PLATFORM_WINDOWS
#pragma optimize("", on)
#endif // PLATFORM_WINDOWS
