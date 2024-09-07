#pragma once

#include "CoreMinimal.h"
#include "ConnectionDrawingPolicy.h"

#include "Layout\SlateRect.h"
#include "Rendering\DrawElements.h"

class FBTConnectionDrawingPolicy : public FConnectionDrawingPolicy
{
public:
	FBTConnectionDrawingPolicy(
		int32 InBackLayerID, //白线的ID
		int32 InFrontLayerID, //箭头的ID
		float InZoomFactor,		//放大放小的系数
		const class FSlateRect& InClippingRect, //裁剪矩形
		class FSlateWindowElementList& InDrawElements, //需要裁剪的元素
		class UEdGraph* InGraphObj);

	virtual void DetermineWiringStyle(
		class UEdGraphPin* OutputPin,
		class UEdGraphPin* InputPin, /*inout*/
		struct FConnectionParams& Params) override;

};