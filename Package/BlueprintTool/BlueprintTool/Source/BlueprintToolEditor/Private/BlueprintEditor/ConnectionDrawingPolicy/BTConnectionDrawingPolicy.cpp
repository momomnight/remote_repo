#include "BlueprintEditor\ConnectionDrawingPolicy\BTConnectionDrawingPolicy.h"
#include "EdGraph\EdGraphPin.h"
#include "Layout\SlateRect.h"
#include "Rendering\DrawElements.h"
#include "EdGraph\EdGraph.h"
#include "EdGraph\EdGraphNode.h"

static const FLinearColor DefaultWiringColor(1.f, 0.f, 0.f);

FBTConnectionDrawingPolicy::FBTConnectionDrawingPolicy(int32 InBackLayerID, int32 InFrontLayerID, float InZoomFactor, 
	const FSlateRect& InClippingRect, FSlateWindowElementList& InDrawElements, UEdGraph* InGraphObj)
	:FConnectionDrawingPolicy(InBackLayerID, InFrontLayerID, InZoomFactor, InClippingRect, InDrawElements)
{
}

void FBTConnectionDrawingPolicy::DetermineWiringStyle(UEdGraphPin* OutputPin, UEdGraphPin* InputPin, FConnectionParams& Params)
{
	Params.WireThickness = 5.5f;
	Params.WireColor = DefaultWiringColor;

	if (HoveredPins.Num() > 0)//拖拽时的效果
	{
		ApplyHoverDeemphasis(OutputPin, InputPin, Params.WireThickness, Params.WireColor);
	}
}
