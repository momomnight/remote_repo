#include "BlueprintEditor/GraphNode/IntNode.h"
#include "BlueprintToolEditor\Public\Type\BlueprintTypeEType.h"

StaticIndex(Int); 
StaticIndex(Int64);
UIntNode::UIntNode()
{
	VariableName = *FString::Printf(TEXT("NewInt_%i"), Increase(Int));
}

void UIntNode::AllocateDefaultPins()
{
	CreatePin(EEdGraphPinDirection::EGPD_Output, FPC_Public::PC_Int, FName(), VariableName);
}
#if WITH_EDITOR
void UIntNode::PostEditChangeChainProperty(FPropertyChangedChainEvent& PropertyChangedEvent)
{
	if (PropertyChangedEvent.GetPropertyName() == "VariableName")
	{
		Pins[0]->PinName = VariableName;
	}
	else if (PropertyChangedEvent.GetPropertyName() == "Value")
	{
		Pins[0]->DefaultValue = FString::FromInt(Value);
	}
	
	Super::PostEditChangeChainProperty(PropertyChangedEvent);
}
#endif // WITH_EDITOR

UInt64Node::UInt64Node()
{
	VariableName = *FString::Printf(TEXT("NewInt64_%i"), Increase(Int64));
}

void UInt64Node::AllocateDefaultPins()
{
	CreatePin(EEdGraphPinDirection::EGPD_Output, FPC_Public::PC_Int64, FName(), VariableName);
}
#if WITH_EDITOR
void UInt64Node::PostEditChangeChainProperty(FPropertyChangedChainEvent& PropertyChangedEvent)
{
	if (PropertyChangedEvent.GetPropertyName() == "VariableName")
	{
		Pins[0]->PinName = VariableName;
	}
	else if (PropertyChangedEvent.GetPropertyName() == "Value")
	{
		Pins[0]->DefaultValue = FString::FromInt(Value);
	}

	Super::PostEditChangeChainProperty(PropertyChangedEvent);
}
#endif // WITH_EDITOR