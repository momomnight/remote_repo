#pragma once

#include "CoreMinimal.h"
#include "BlueprintEditor\Core\Architect\VariableNode.h"
#include "ObjectNode.generated.h"


UCLASS()
class UObjectNode : public UVariableNode
{
	GENERATED_BODY()

public:
	UObjectNode();

	virtual void AllocateDefaultPins() override;

	virtual bool IsVariable() { return true; }

	void SetValue(UObject* InValue);

#if WITH_EDITOR
	virtual void PostEditChangeChainProperty(struct FPropertyChangedChainEvent& PropertyChangedEvent) override;

	UPROPERTY()
	FString Path;
#endif // WITH_EDITOR


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Variable)
	FName VariableName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Instance)
	UObject* Value;

	FSimpleDelegate Update;

};
