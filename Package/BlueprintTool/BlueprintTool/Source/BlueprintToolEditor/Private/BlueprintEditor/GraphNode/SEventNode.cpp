#include "BlueprintEditor/GraphNode/SEventNode.h"

void SEventNode::Construct(const FArguments& InArgs, UK3Node* MarkerNode)
{
	NodeName = InArgs._NodeName;
	GraphNode = MarkerNode;
	this->SetCursor(EMouseCursor::GrabHand);
	this->UpdateGraphNode();
}

void SEventNode::UpdateGraphNode()
{
	InputPins.Empty();
	OutputPins.Empty();

	LeftNodeBox.Reset();
	RightNodeBox.Reset();

	this->GetOrAddSlot(ENodeZone::Center)
		.HAlign(HAlign_Fill)
		.VAlign(VAlign_Fill)
		[
			SNew(SBox)
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Fill)
			.MinDesiredWidth(150.f)
			[
				SNew(SBorder)
				//.HAlign()
				.BorderBackgroundColor_Lambda([]() {return FSlateColor(FLinearColor(1.f, 1.f, 1.f, 1.f)); })
				[
					SNew(SVerticalBox)

					+ SVerticalBox::Slot()
					.Padding(0.f, 5.f, 0.f, 0.f)
					.HAlign(HAlign_Center)
					.AutoHeight()
					[
						SNew(STextBlock)
							.Text(NodeName)
					]

					+ SVerticalBox::Slot()
					.HAlign(HAlign_Fill)
					.VAlign(VAlign_Center)
					[
						SNew(SHorizontalBox)
						+ SHorizontalBox::Slot()
						.HAlign(HAlign_Right)
						.VAlign(VAlign_Fill)
						[
							SAssignNew(RightNodeBox, SVerticalBox)
						]
					]
				]
			]
		];
	CreatePinWidgets();
}
