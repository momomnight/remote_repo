#pragma once

#include "CoreMinimal.h"
#include "EdGraph\EdGraphSchema.h"
#include <type_traits>
#include "UObject\UnrealType.h"
#include "UObject\Class.h"
#include "UObject\Field.h"
#include "BTSchemaAction.generated.h"


class FFieldParam
{
public:
	FFieldParam() : Function(nullptr), Property(nullptr) {}
	explicit FFieldParam(UField* InFunction) : Function(InFunction), Property(nullptr) {}
	explicit FFieldParam(FField* InProperty) : Function(nullptr), Property(InProperty) {}

	FORCEINLINE bool IsFunction() { return Function && !Property; }
	FORCEINLINE bool IsProperty() { return !Function && Property; }

	UFunction* GetFunction(){ return Cast<UFunction>(Function); }
	FProperty* GetProperty(){ return CastField<FProperty>(Property); }
private:
	UField* Function;
	FField* Property;
};

USTRUCT()
struct FBlueprintToolSchemaAction : public FEdGraphSchemaAction
{
	GENERATED_BODY()

	FBlueprintToolSchemaAction() : FEdGraphSchemaAction(), FieldParam(), K3NodeClass()
	{}

	FBlueprintToolSchemaAction(FText InNodeCategory, FText InMenuDesc, FText InToolTip, const int32 InGrouping, FFieldParam InFieldParm)
		: FEdGraphSchemaAction(MoveTemp(InNodeCategory), MoveTemp(InMenuDesc), InToolTip, InGrouping)
		, FieldParam(InFieldParm), K3NodeClass()
	{}

	// FEdGraphSchemaAction interface
	virtual class UEdGraphNode* PerformAction(class UEdGraph* ParentGraph, class UEdGraphPin* FromPin, const FVector2D Location,
		bool bSelectNewNode = true) override;

	template<class T>
	class UK3Node* CreateUK3Node(UObject* Outer)
	{
		//static_assert(std::is_base_of<UK3Node, T>::value, "UK3Node is not a base of T");

		check(T::StaticClass()->IsChildOf<UK3Node>());

		UK3Node* Node = NewObject<T>(Outer, K3NodeClass);


		if (FieldParam.IsFunction())
		{
			Node->Function = FieldParam.GetFunction();
		}
		else if (FieldParam.IsProperty())
		{
			Node->Property = FieldParam.GetProperty();
		}

		return Node;
	}


	FFieldParam FieldParam;

	//class UK3Node* K3Node;
	TSubclassOf<class UK3Node> K3NodeClass;
	
};