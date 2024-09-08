#include "BlueprintEditor/Core/Architect/BTSchemaAction.h"
#include "EdGraph\EdGraph.h"
#include "EdGraph\EdGraphPin.h"
#include "BlueprintEditor/Core/Architect/K3Node.h"

#define LOCTEXT_NAMESPACE "PBToolSchemaAction"

//pragma optimize("", off)

//由UBlueprintToolSchema搜集，通过FGraphSchemaActionDragDropAction调用
UEdGraphNode* FBlueprintToolSchemaAction::PerformAction(UEdGraph* ParentGraph, UEdGraphPin* FromPin, 
	const FVector2D Location, bool bSelectNewNode)
{
	check(ParentGraph);
	UK3Node* K3Node = CreateUK3Node<UK3Node>(ParentGraph);

	//Palette调用会出问题
	if (K3Node)
	{
		//Ctrl + Z功能
		const FScopedTransaction Transaction(LOCTEXT("FScopedTransaction", "Transaction"));

		ParentGraph->Modify();
		if (FromPin)
		{
			FromPin->Modify();
		}

		//K3Node->Rename(nullptr, ParentGraph);//创建时自动增加名字计算
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