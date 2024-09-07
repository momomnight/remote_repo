#pragma once

#include "CoreMinimal.h"
#include "BlueprintEditor\Core\Architect\VariableNode.h"
#include "LocationNode.generated.h"


UCLASS()
class UVectorNode : public UVariableNode
{
	GENERATED_BODY()

public:
	UVectorNode();

	virtual void AllocateDefaultPins() override;

	virtual bool IsVariable() { return true; }

#if WITH_EDITOR
	virtual void PostEditChangeChainProperty(struct FPropertyChangedChainEvent& PropertyChangedEvent) override;
#endif // WITH_EDITOR


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Variable)
	FName VariableName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Instance)
	FVector Value;

};

UCLASS()
class URotatorNode : public UVariableNode
{
	GENERATED_BODY()

public:
	URotatorNode();

	virtual void AllocateDefaultPins() override;

	virtual bool IsVariable() { return true; }

#if WITH_EDITOR
	virtual void PostEditChangeChainProperty(struct FPropertyChangedChainEvent& PropertyChangedEvent) override;
#endif // WITH_EDITOR


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Variable)
	FName VariableName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Instance)
	FRotator Value;
};


UCLASS()
class UTransformNode : public UVariableNode
{
	GENERATED_BODY()

public:
	UTransformNode();

	virtual void AllocateDefaultPins() override;

	virtual bool IsVariable() { return true; }

#if WITH_EDITOR
	virtual void PostEditChangeChainProperty(struct FPropertyChangedChainEvent& PropertyChangedEvent) override;
#endif // WITH_EDITOR


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Variable)
	FName VariableName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Instance)
	FTransform Value;
};