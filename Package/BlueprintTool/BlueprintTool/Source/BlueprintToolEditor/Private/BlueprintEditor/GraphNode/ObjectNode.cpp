#include "BlueprintEditor/GraphNode/ObjectNode.h"
#include "BlueprintToolEditor\Public\Type\BlueprintTypeEType.h"

int32 VariableIndex = 0;

UObjectNode::UObjectNode()
{
	VariableName = *FString::Printf(TEXT("NewObject_%i"), VariableIndex++);
}

void UObjectNode::AllocateDefaultPins()
{
	CreatePin(EEdGraphPinDirection::EGPD_Output, FPC_Public::PC_Object, FName(), VariableName);
}

void UObjectNode::SetValue(UObject* InValue)
{
	Value = InValue;
	//从磁盘里读取到内存
	//LoadObject()
	//LoadClass()

	//在内存中查找对象
	//FindObject()

	//StaticMesh'/Game/Head_Hight.Head_Hight'
	if (Value)
	{
		FString Left, Right;
		FString OuterName = Value->GetOuter()->GetName();
		// Value->GetOuter()->GetName() = /Game/Head_Hight
		OuterName.Split(TEXT("/"), &Left, &Right, ESearchCase::IgnoreCase, ESearchDir::FromEnd);
		// /Game/Head_Hight.Head_Hight
		FString ValueName = Value->GetOuter()->GetName() + TEXT(".") + Right;

		FString TempPath = FString::Printf(TEXT("%s\'%s\'"), *Value->GetClass()->GetName(), *ValueName);

		UStaticMesh* Mesh = LoadObject<UStaticMesh>(nullptr, *TempPath);
		if (Mesh)
		{
			Path = TempPath;
			Pins[0]->DefaultValue = Path;
		}
	}
}


#if WITH_EDITOR
void UObjectNode::PostEditChangeChainProperty(FPropertyChangedChainEvent& PropertyChangedEvent)
{
	if (PropertyChangedEvent.GetPropertyName() == "VariableName")
	{
		Pins[0]->PinName = VariableName;
	}
	else if (PropertyChangedEvent.GetPropertyName() == "Value")
	{
		SetValue(Value);
		Update.ExecuteIfBound();
	}
	

	Super::PostEditChangeChainProperty(PropertyChangedEvent);
}
#endif // WITH_EDITOR