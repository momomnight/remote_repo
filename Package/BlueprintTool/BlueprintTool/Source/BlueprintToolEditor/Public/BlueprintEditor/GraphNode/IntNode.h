#pragma once

#include "CoreMinimal.h"
#include "BlueprintEditor\Core\Architect\VariableNode.h"
#include "IntNode.generated.h"


UCLASS()
class UIntNode : public UVariableNode
{
	GENERATED_BODY()

public:
	UIntNode();

	virtual void AllocateDefaultPins() override;

	virtual bool IsVariable() { return true; }

#if WITH_EDITOR
	virtual void PostEditChangeChainProperty(struct FPropertyChangedChainEvent& PropertyChangedEvent) override;
#endif // WITH_EDITOR


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Variable)
	FName VariableName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Instance)
	int32 Value;

};


UCLASS()
class UInt64Node : public UVariableNode
{
	GENERATED_BODY()

public:
	UInt64Node();

	virtual void AllocateDefaultPins() override;

	virtual bool IsVariable() { return true; }

#if WITH_EDITOR
	virtual void PostEditChangeChainProperty(struct FPropertyChangedChainEvent& PropertyChangedEvent) override;
#endif // WITH_EDITOR


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Variable)
	FName VariableName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Instance)
	int64 Value;

};
