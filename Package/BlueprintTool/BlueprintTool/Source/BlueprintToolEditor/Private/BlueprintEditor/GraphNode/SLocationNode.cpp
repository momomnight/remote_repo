#include "BlueprintEditor/GraphNode/SLocationNode.h"

void SVectorNode::Construct(const FArguments& InArgs, UK3Node* MarkerNode)
{
	GraphNode = MarkerNode;
	SetCursor(EMouseCursor::GrabHand);
	UpdateGraphNode();
}

void SVectorNode::UpdateGraphNode()
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

void SRotatorNode::Construct(const FArguments& InArgs, UK3Node* MarkerNode)
{
	GraphNode = MarkerNode;
	SetCursor(EMouseCursor::GrabHand);
	UpdateGraphNode();
}

void SRotatorNode::UpdateGraphNode()
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


void STransformNode::Construct(const FArguments& InArgs, UK3Node* MarkerNode)
{
	GraphNode = MarkerNode;
	SetCursor(EMouseCursor::GrabHand);
	UpdateGraphNode();
}

void STransformNode::UpdateGraphNode()
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
