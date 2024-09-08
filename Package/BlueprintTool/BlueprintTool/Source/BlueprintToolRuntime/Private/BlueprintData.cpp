#include "BlueprintData.h"
#include "EdGraph\EdGraph.h"

UBlueprintData::UBlueprintData()
{
}

void UBlueprintData::AddReferencedObjects(UObject* InThis, FReferenceCollector& Collector)
{
#if WITH_EDITORONLY_DATA
	UBlueprintData* This = CastChecked<UBlueprintData>(InThis);
	Collector.AddReferencedObject(This->EdGraph, This);
#endif

	Super::AddReferencedObjects(InThis, Collector);
}
