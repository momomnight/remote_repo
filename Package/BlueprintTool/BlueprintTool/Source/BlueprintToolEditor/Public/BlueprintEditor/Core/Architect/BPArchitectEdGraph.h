#pragma once


#include "EdGraph\EdGraph.h"
#include "BPArchitectEdGraph.generated.h"

//À¶Í¼µÄÊµÌå
UCLASS()
class UBPArchitectEdGraph : public UEdGraph
{
	GENERATED_UCLASS_BODY()

public:
	
	void InitializeGraph();

	UEdGraphNode* CreateNewNode(UObject* AssetObject, const FVector2D& Location);

	template<class TNodeClass>
	TNodeClass* CreateNewNode(const FVector2D& Location)
	{
		TNodeClass* Node = NewObject<TNodeClass>(this);
		Node->Rename(nullptr, this, REN_NonTransactional);
		this->AddNode(Node, true, false);

		Node->CreateNewGuid();
		Node->PostPlacedNewNode();
		Node->AllocateDefaultPins();

		Node->NodePosX = Location.X;
		Node->NodePosX = Location.Y;

		Node->SnapToGrid(16);

		return Node;
	}


};