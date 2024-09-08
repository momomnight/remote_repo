#include "BlueprintEditor/GraphNode/FloatNode.h"
#include "BlueprintToolEditor\Public\Type\BlueprintTypeEType.h"

StaticIndex(Float);
StaticIndex(Double);

UFloatNode::UFloatNode()
{
	VariableName = *FString::Printf(TEXT("NewFloat_%i"), Increase(Float));
}

void UFloatNode::AllocateDefaultPins()
{
	CreatePin(EEdGraphPinDirection::EGPD_Output, FPC_Public::PC_Real, FPC_Public::PC_Float, VariableName);
}

#if WITH_EDITOR
void UFloatNode::PostEditChangeChainProperty(FPropertyChangedChainEvent& PropertyChangedEvent)
{
	if (PropertyChangedEvent.GetPropertyName() == "VariableName")
	{
		Pins[0]->PinName = VariableName;
	}
	else if (PropertyChangedEvent.GetPropertyName() == "Value")
	{
		Pins[0]->DefaultValue = FString::SanitizeFloat(Value);
	}
	Super::PostEditChangeChainProperty(PropertyChangedEvent);
}
#endif // WITH_EDITOR


UDoubleNode::UDoubleNode()
{
	VariableName = *FString::Printf(TEXT("NewDouble_%i"), Increase(Double));
}

void UDoubleNode::AllocateDefaultPins()
{
	CreatePin(EEdGraphPinDirection::EGPD_Output, FPC_Public::PC_Real, FPC_Public::PC_Double, VariableName);
}

#if WITH_EDITOR
void UDoubleNode::PostEditChangeChainProperty(FPropertyChangedChainEvent & PropertyChangedEvent)
{
	if (PropertyChangedEvent.GetPropertyName() == "VariableName")
	{
		Pins[0]->PinName = VariableName;
	}
	else if (PropertyChangedEvent.GetPropertyName() == "Value")
	{
		Pins[0]->DefaultValue = FString::SanitizeFloat(Value);
	}
	Super::PostEditChangeChainProperty(PropertyChangedEvent);
}
#endif // WITH_EDITOR