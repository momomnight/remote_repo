#pragma once

#include "CoreMinimal.h"
#include "ConnectionDrawingPolicy.h"

#include "Layout\SlateRect.h"
#include "Rendering\DrawElements.h"

class FBTConnectionDrawingPolicy : public FConnectionDrawingPolicy
{
public:
	FBTConnectionDrawingPolicy(
		int32 InBackLayerID, //���ߵ�ID
		int32 InFrontLayerID, //��ͷ��ID
		float InZoomFactor,		//�Ŵ��С��ϵ��
		const class FSlateRect& InClippingRect, //�ü�����
		class FSlateWindowElementList& InDrawElements, //��Ҫ�ü���Ԫ��
		class UEdGraph* InGraphObj);

	virtual void DetermineWiringStyle(
		class UEdGraphPin* OutputPin,
		class UEdGraphPin* InputPin, /*inout*/
		struct FConnectionParams& Params) override;

};