#pragma once

#include "CoreMinimal.h"

#include "DescriptionBPTool.generated.h"

USTRUCT(BlueprintType)
struct FDescriptionBPTool
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Transform")
	FTransform MeshTansform;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Actor")
	AActor* MyActor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "hello")
	float A;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "hello", Meta = (Test = "Hide"))
	int32 B;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "hello")
	int32 C;

};