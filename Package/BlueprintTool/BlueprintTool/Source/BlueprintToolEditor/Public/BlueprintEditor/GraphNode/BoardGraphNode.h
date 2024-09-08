#pragma once

#include "BlueprintEditor/Core/Architect/K3Node.h"
#include "Details/DescriptionBPTool.h"
#include "BoardGraphNode.generated.h"

UCLASS()
class UBoardGraphNode : public UK3Node
{
	GENERATED_BODY()

public:
	using Super = UK3Node;

	UBoardGraphNode();

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = K3Node)
	FTransform Transform;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = K3Node)
	FDescriptionBPTool DescriptionBPTool;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "hello")
	float A;

};