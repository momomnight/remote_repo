#include "BlueprintEditor/GraphNode/ByteNode.h"
#include "BlueprintToolEditor\Public\Type\BlueprintTypeEType.h"

StaticIndex(Byte);

UByteNode::UByteNode()
{
	VariableName = *FString::Printf(TEXT("NewByte_%i"), Increase(Byte));
}

void UByteNode::AllocateDefaultPins()
{
	CreatePin(EEdGraphPinDirection::EGPD_Output, FPC_Public::PC_Byte, FName(), VariableName);
}
#if WITH_EDITOR
void UByteNode::PostEditChangeChainProperty(FPropertyChangedChainEvent& PropertyChangedEvent)
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