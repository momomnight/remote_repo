#pragma once

#include "CoreMinimal.h"
#include "SGraphPin.h"
#include "SGraphNode.h"


class SBTGraphPin : public SGraphPin
{
public:
	SLATE_BEGIN_ARGS(SBTGraphPin) {}

	SLATE_ATTRIBUTE(FText, PinName)

	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs, class UEdGraphPin* InPin);

	TSharedPtr<SGraphNode> GetGraphNode(){return OwnerNodePtr.Pin(); }
private:
	
	TAttribute<FText> PinName;

};