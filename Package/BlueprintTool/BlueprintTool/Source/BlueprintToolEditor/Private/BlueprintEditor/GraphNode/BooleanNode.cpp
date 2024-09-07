#include "BlueprintEditor/GraphNode/BooleanNode.h"
#include "BlueprintToolEditor\Public\Type\BlueprintTypeEType.h"

StaticIndex(Bool);

UBooleanNode::UBooleanNode()
{
	VariableName = *FString::Printf(TEXT("NewBool_%i"), Increase(Bool));
}

void UBooleanNode::AllocateDefaultPins()
{
	CreatePin(EEdGraphPinDirection::EGPD_Output, FPC_Public::PC_Boolean, FName(), VariableName);
}
#if WITH_EDITOR
void UBooleanNode::PostEditChangeChainProperty(FPropertyChangedChainEvent& PropertyChangedEvent)
{
	if (PropertyChangedEvent.GetPropertyName() == "VariableName")
	{
		Pins[0]->PinName = VariableName;
	}
	else if (PropertyChangedEvent.GetPropertyName() == "Value")
	{
		if (Value)
		{
			Pins[0]->DefaultValue = "true";
		}
		else
		{
			Pins[0]->DefaultValue = "false";
		}

	}
	

	Super::PostEditChangeChainProperty(PropertyChangedEvent);
}
#endif // WITH_EDITOR