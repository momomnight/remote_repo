#include "BlueprintEditor/GraphNode/TextNode.h"
#include "BlueprintToolEditor\Public\Type\BlueprintTypeEType.h"

StaticIndex(Text);

UTextNode::UTextNode()
{
	VariableName = *FString::Printf(TEXT("NewText_%i"), Increase(Text));
}

void UTextNode::AllocateDefaultPins()
{
	CreatePin(EEdGraphPinDirection::EGPD_Output, FPC_Public::PC_Text, FName(), VariableName);
}
#if WITH_EDITOR
void UTextNode::PostEditChangeChainProperty(FPropertyChangedChainEvent& PropertyChangedEvent)
{
	if (PropertyChangedEvent.GetPropertyName() == "VariableName")
	{
		Pins[0]->PinName = VariableName;
	}
	else if (PropertyChangedEvent.GetPropertyName() == "Value")
	{
		Pins[0]->DefaultTextValue = Value;
	}
	

	Super::PostEditChangeChainProperty(PropertyChangedEvent);
}
#endif // WITH_EDITOR