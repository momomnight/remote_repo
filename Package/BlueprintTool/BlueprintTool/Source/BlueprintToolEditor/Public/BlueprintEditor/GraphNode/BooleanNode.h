#pragma once

#include "CoreMinimal.h"
#include "BlueprintEditor\Core\Architect\VariableNode.h"
#include "BooleanNode.generated.h"


UCLASS()
class UBooleanNode : public UVariableNode
{
	GENERATED_BODY()

public:
	UBooleanNode();

	virtual void AllocateDefaultPins() override;

	virtual bool IsVariable() { return true; }

#if WITH_EDITOR
	virtual void PostEditChangeChainProperty(struct FPropertyChangedChainEvent& PropertyChangedEvent) override;
#endif // WITH_EDITOR


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Variable)
	FName VariableName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Instance)
	bool Value;

};
