// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

#include "BlueprintData.generated.h"

/*
*  UBlueprintData用于保持蓝图实体UEdGraph，并序列化与反序列化
*/

UCLASS()
class BLUEPRINTTOOLRUNTIME_API UBlueprintData : public UObject
{
	GENERATED_BODY()


public:
	UBlueprintData();

#if WITH_EDITORONLY_DATA
	UPROPERTY()
	class UEdGraph* EdGraph;
#endif

	static void AddReferencedObjects(class UObject* InThis,class FReferenceCollector& Collector);
};
