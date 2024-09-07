// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

#include "BlueprintData.generated.h"

/*
*  UBlueprintData���ڱ�����ͼʵ��UEdGraph�������л��뷴���л�
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
