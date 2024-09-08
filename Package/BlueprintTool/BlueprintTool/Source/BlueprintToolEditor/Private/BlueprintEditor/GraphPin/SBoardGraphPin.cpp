#include "BlueprintEditor/GraphPin/SBoardGraphPin.h"
#include "EdGraph\EdGraphPin.h"
#include "EdGraph\EdGraphSchema.h"
void SBTGraphPin::Construct(const FArguments& InArgs, UEdGraphPin* InPin)
{
	SetCursor(EMouseCursor::Hand);
	IsEditable = true;

	check(InPin);
	GraphPinObj = InPin;
	const UEdGraphSchema* Schema = GraphPinObj->GetSchema();
	check(Schema);

	PinName = InArgs._PinName;

	auto BorderBackgroundColorLambda = []() {return FSlateColor(FLinearColor(1.f, 1.f, 1.f)); };

	SBorder::Construct
	(
		SBorder::FArguments()
		.BorderBackgroundColor_Lambda(BorderBackgroundColorLambda)
		.OnMouseButtonDown(this, &SGraphPin::OnPinNameMouseDown)
		[
			SNew(STextBlock)
			.Text(PinName)
		]
	);

}
