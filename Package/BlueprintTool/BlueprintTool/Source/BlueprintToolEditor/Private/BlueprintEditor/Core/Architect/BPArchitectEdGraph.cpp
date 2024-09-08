
#include "BlueprintEditor/Core/Architect/BPArchitectEdGraph.h"
#include "BlueprintEditor/Core/Architect/BTSchema.h"
#include "BlueprintEditor/GraphNode/ObjectNode.h"

UBPArchitectEdGraph::UBPArchitectEdGraph(const FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer)
{
	Schema = UBlueprintToolSchema::StaticClass();
}

void UBPArchitectEdGraph::InitializeGraph()
{
}

UEdGraphNode* UBPArchitectEdGraph::CreateNewNode(UObject* AssetObject, const FVector2D& Location)
{
	UObjectNode* ObjectNode = CreateNewNode<UObjectNode>(Location);
	if (ObjectNode)
	{
		ObjectNode->SetValue(AssetObject);
	}
	return ObjectNode;
}
