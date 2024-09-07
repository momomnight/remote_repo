#pragma once

#include "CoreMinimal.h"
#include "BlueprintEditor\Core\Architect\VariableNode.h"
#include "NameNode.generated.h"


UCLASS()
class UNameNode : public UVariableNode
{
	GENERATED_BODY()

public:
	UNameNode();

	virtual void AllocateDefaultPins() override;

	virtual bool IsVariable() { return true; }

#if WITH_EDITOR
	virtual void PostEditChangeChainProperty(struct FPropertyChangedChainEvent& PropertyChangedEvent) override;
#endif // WITH_EDITOR


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Variable)
	FName VariableName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Instance)
	FName Value;

};
