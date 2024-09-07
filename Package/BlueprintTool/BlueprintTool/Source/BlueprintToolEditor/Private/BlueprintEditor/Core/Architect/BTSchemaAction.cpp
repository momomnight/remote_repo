#include "BlueprintEditor/Core/Architect/BTSchemaAction.h"
#include "EdGraph\EdGraph.h"
#include "EdGraph\EdGraphPin.h"
#include "BlueprintEditor/Core/Architect/K3Node.h"

#define LOCTEXT_NAMESPACE "PBToolSchemaAction"

//pragma optimize("", off)

//��UBlueprintToolSchema�Ѽ���ͨ��FGraphSchemaActionDragDropAction����
UEdGraphNode* FBlueprintToolSchemaAction::PerformAction(UEdGraph* ParentGraph, UEdGraphPin* FromPin, 
	const FVector2D Location, bool bSelectNewNode)
{
	check(ParentGraph);
	UK3Node* K3Node = CreateUK3Node<UK3Node>(ParentGraph);

	//Palette���û������
	if (K3Node)
	{
		//Ctrl + Z����
		const FScopedTransaction Transaction(LOCTEXT("FScopedTransaction", "Transaction"));

		ParentGraph->Modify();
		if (FromPin)
		{
			FromPin->Modify();
		}

		//K3Node->Rename(nullptr, ParentGraph);//����ʱ�Զ��������ּ���
		ParentGraph->AddNode(K3Node, true, bSelectNewNode);

		K3Node->CreateNewGuid();
		K3Node->PostPlacedNewNode();
		K3Node->AllocateDefaultPins();
		K3Node->AutowireNewNode(FromPin);

		K3Node->NodePosX = Location.X;
		K3Node->NodePosY = Location.Y;

		K3Node->SetFlags(RF_Transactional);

	}

	return K3Node;
}

//pragma optimize("", on)

#undef LOCTEXT_NAMESPACE