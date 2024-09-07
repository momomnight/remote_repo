#include "BlueprintEditor/GraphNode/SByteNode.h"

void SByteNode::Construct(const FArguments& InArgs, UK3Node* MarkerNode)
{
	GraphNode = MarkerNode;
	SetCursor(EMouseCursor::GrabHand);
	UpdateGraphNode();
}

void SByteNode::UpdateGraphNode()
{
	InputPins.Empty();
	OutputPins.Empty();

	LeftNodeBox.Reset();
	RightNodeBox.Reset();

	const FSlateBrush* MyNodeIcon = FAppStyle::GetBrush(TEXT("Graph.StateNode.Icon"));

	this->GetOrAddSlot(ENodeZone::Center)
		.HAlign(HAlign_Fill)
		.VAlign(VAlign_Fill)
		[
			SAssignNew(RightNodeBox, SVerticalBox)
		];
	CreatePinWidgets();
}
