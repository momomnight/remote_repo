#include "BlueprintEditor/GraphNode/STextNode.h"

void STextNode::Construct(const FArguments& InArgs, UK3Node* MarkerNode)
{
	GraphNode = MarkerNode;
	SetCursor(EMouseCursor::GrabHand);
	UpdateGraphNode();
}

void STextNode::UpdateGraphNode()
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
