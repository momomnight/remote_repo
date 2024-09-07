#include "BlueprintEditor/GraphNode/LocationNode.h"
#include "BlueprintToolEditor\Public\Type\BlueprintTypeEType.h"

StaticIndex(Vector);
StaticIndex(Rotator);
StaticIndex(Transform);

UVectorNode::UVectorNode()
{
	VariableName = *FString::Printf(TEXT("NewVector_%i"), Increase(Vector));
}

void UVectorNode::AllocateDefaultPins()
{
	CreatePin(EEdGraphPinDirection::EGPD_Output, FPC_Public::PC_Struct, FName(), TBaseStructure<::FVector>::Get(), VariableName);
}
#if WITH_EDITOR
void UVectorNode::PostEditChangeChainProperty(FPropertyChangedChainEvent& PropertyChangedEvent)
{
	if (PropertyChangedEvent.GetPropertyName() == "VariableName")
	{
		Pins[0]->PinName = VariableName;
	}
	else if (PropertyChangedEvent.GetPropertyName() == "Value")
	{
		TArray<uint8> Buffer;
		FBPHelperWriter Writer(Buffer);
		Writer << Value;
		Pins[0]->DefaultValue = FString::FromBlob(Buffer.GetData(), Buffer.Num());
	}

	Super::PostEditChangeChainProperty(PropertyChangedEvent);
}
#endif // WITH_EDITOR

URotatorNode::URotatorNode()
{
	VariableName = *FString::Printf(TEXT("NewRotator_%i"), Increase(Rotator));
}

void URotatorNode::AllocateDefaultPins()
{
	CreatePin(EEdGraphPinDirection::EGPD_Output, FPC_Public::PC_Struct, FName(), TBaseStructure<::FRotator>::Get(), VariableName);
}
#if WITH_EDITOR
void URotatorNode::PostEditChangeChainProperty(FPropertyChangedChainEvent& PropertyChangedEvent)
{
	if (PropertyChangedEvent.GetPropertyName() == "VariableName")
	{
		Pins[0]->PinName = VariableName;
	}
	else if (PropertyChangedEvent.GetPropertyName() == "Value")
	{
		TArray<uint8> Buffer;
		FBPHelperWriter Writer(Buffer);
		Writer << Value;
		Pins[0]->DefaultValue = FString::FromBlob(Buffer.GetData(), Buffer.Num());
	}

	Super::PostEditChangeChainProperty(PropertyChangedEvent);
}
#endif // WITH_EDITOR

UTransformNode::UTransformNode()
{
	VariableName = *FString::Printf(TEXT("NewTransform_%i"), Increase(Transform));
}

void UTransformNode::AllocateDefaultPins()
{
	CreatePin(EEdGraphPinDirection::EGPD_Output, FPC_Public::PC_Struct, FName(), TBaseStructure<::FTransform>::Get(), VariableName);
}
#if WITH_EDITOR
void UTransformNode::PostEditChangeChainProperty(FPropertyChangedChainEvent& PropertyChangedEvent)
{
	if (PropertyChangedEvent.GetPropertyName() == "VariableName")
	{
		Pins[0]->PinName = VariableName;
	}
	else if (PropertyChangedEvent.GetPropertyName() == "Value")
	{
		TArray<uint8> Buffer;
		FBPHelperWriter Writer(Buffer);
		Writer << Value;
		Pins[0]->DefaultValue = FString::FromBlob(Buffer.GetData(), Buffer.Num());
	}

	Super::PostEditChangeChainProperty(PropertyChangedEvent);
}
#endif // WITH_EDITOR