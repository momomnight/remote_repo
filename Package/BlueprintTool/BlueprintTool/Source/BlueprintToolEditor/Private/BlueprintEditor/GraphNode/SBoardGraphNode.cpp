#include "BlueprintEditor/GraphNode/SBoardGraphNode.h"
#include "BlueprintEditor/Core/Architect/K3Node.h"
#include "SNodePanel.h"
#include "Layout\Children.h"
#include "Layout\BasicLayoutWidgetSlot.h"
#include "Styling\SlateBrush.h"
#include "SGraphPin.h"
#include "EdGraph\EdGraphPin.h"
#include "GraphEditorSettings.h"


void SK3Node::Construct(const FArguments& InArgs, UK3Node* MarkerNode)
{
	GraphNode = MarkerNode;
	NodeName = InArgs._NodeName;

	SetCursor(EMouseCursor::GrabHand);

	UpdateGraphNode();
}

void SK3Node::UpdateGraphNode()
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
						.HAlign(HAlign_Left)
						.VAlign(VAlign_Fill)
						[
							SAssignNew(LeftNodeBox, SVerticalBox)
						]
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

void SK3Node::AddPin(const TSharedRef<SGraphPin>& PinToAdd)
{
	PinToAdd->SetOwner(SharedThis(this));

	const UEdGraphPin* PinObj = PinToAdd->GetPinObj();

	if (PinObj && PinObj->bAdvancedView)
	{
		PinToAdd->SetVisibility(TAttribute<EVisibility>(PinToAdd, &SGraphPin::IsPinVisibleAsAdvanced));
	}


	//需要添加进LeftNodeBox和InputPins
	if (PinToAdd->GetDirection() == EEdGraphPinDirection::EGPD_Input)
	{
		LeftNodeBox->AddSlot()
			.HAlign(HAlign_Left)
			.VAlign(VAlign_Top)
			.Padding(Settings->GetOutputPinPadding())
			[
				PinToAdd
			];
		InputPins.Add(PinToAdd);
	}
	else if (PinToAdd->GetDirection() == EEdGraphPinDirection::EGPD_Output)
	{
		RightNodeBox->AddSlot()
			.HAlign(HAlign_Right)
			.VAlign(VAlign_Top)
			.Padding(Settings->GetOutputPinPadding())
			[
				PinToAdd
			];
		OutputPins.Add(PinToAdd);
	}

}

//void SK3Node::OnTextCommitted(const FText& InText, ETextCommit::Type)
//{
//	if (EditableTextBox.IsValid() && !InText.IsEmpty())
//	{
//		NodeName = InText;
//		EditableTextBox->SetText(NodeName);
//		if (UK3Node* K3Node = Cast<UK3Node>(GraphNode))
//		{
//			K3Node->NodeTitle = InText;
//		}
//	}
//}

