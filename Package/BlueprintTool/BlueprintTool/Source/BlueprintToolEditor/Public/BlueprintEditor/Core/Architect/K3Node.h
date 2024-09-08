
#pragma once

#include "CoreMinimal.h"
#include "EdGraph/EdGraphNode.h"
#include "UObject\UnrealType.h"
#include "K3Node.generated.h"

UCLASS(MinimalAPI)
class UK3Node : public UEdGraphNode
{
	GENERATED_BODY()

public:
	UK3Node() : Function(nullptr), Property(nullptr){}

	virtual void AllocateDefaultPins() override;

	virtual FText GetNodeTitle(ENodeTitleType::Type TitleType) const override;

	void CreatePinType(FProperty* InProperty, EEdGraphPinDirection PinDir);

	virtual bool IsPure();

	FORCEINLINE bool IsFunction()
	{
		return Function && Property.IsPathToFieldEmpty();
	}

	FORCEINLINE bool IsProperty()
	{
		return !Function && !Property.IsPathToFieldEmpty();
	}


	UPROPERTY()
	class UFunction* Function;

	UPROPERTY()
	TFieldPath<FProperty> Property;

	UPROPERTY()
	FText NodeTitle;

private:
	//FText GetNodeTitlePrivate();

};