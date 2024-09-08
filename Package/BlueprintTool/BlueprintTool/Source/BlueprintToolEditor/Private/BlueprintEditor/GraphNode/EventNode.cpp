#include "BlueprintEditor/GraphNode/EventNode.h"
#include "Type\BlueprintTypeEType.h"

void UEventNode::AllocateDefaultPins()
{
	if (Function && Function->GetMetaData(TEXT("CodeType")) == TEXT("Event"))
	{
		CreatePin(EGPD_Output, FPC_Public::PC_Exec, FName(), FPC_Public::PC_Exec);

		for (TFieldIterator<FProperty> Iter(Function); Iter; ++Iter)
		{
			FProperty* Prop = *Iter;
			if(Prop)
			{
				if(Prop->GetFName() != TEXT("ReturnValue"))
				{
					CreatePinType(Prop, EGPD_Output);
				}
			}
		}
	}
}

#if WITH_EDITOR
void UEventNode::PostEditChangeChainProperty(struct FPropertyChangedChainEvent& PropertyChangedEvent)
{
	Super::PostEditChangeChainProperty(PropertyChangedEvent);
}
#endif // WITH_EDITOR