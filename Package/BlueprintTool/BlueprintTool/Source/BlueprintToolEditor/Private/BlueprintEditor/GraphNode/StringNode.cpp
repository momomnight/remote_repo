#include "BlueprintEditor/GraphNode/StringNode.h"
#include "BlueprintToolEditor\Public\Type\BlueprintTypeEType.h"

StaticIndex(String);

UStringNode::UStringNode()
{
	VariableName = *FString::Printf(TEXT("NewString_%i"), Increase(String));
}

void UStringNode::AllocateDefaultPins()
{
	CreatePin(EEdGraphPinDirection::EGPD_Output, FPC_Public::PC_String, FName(), VariableName);
}
#if WITH_EDITOR
void UStringNode::PostEditChangeChainProperty(FPropertyChangedChainEvent& PropertyChangedEvent)
{
	if (PropertyChangedEvent.GetPropertyName() == "VariableName")
	{
		Pins[0]->PinName = VariableName;
	}
	else if (PropertyChangedEvent.GetPropertyName() == "Value")
	{
		Pins[0]->DefaultValue = Value;
	}
	
	Super::PostEditChangeChainProperty(PropertyChangedEvent);
}
#endif // WITH_EDITOR