#pragma once

#include "CoreMinimal.h"
#include "EdGraph\EdGraphSchema.h"
#include "EdGraph\EdGraph.h"
#include "BlueprintEditor/Core/Architect/BTSchemaAction.h"
#include "BlueprintEditor/GraphNode/BoardGraphNode.h"
#include <type_traits>
#include "UObject\Class.h"


struct BLUEPRINTTOOLEDITOR_API FBPToolSchemaUtils
{


	template<typename T>
	static void CreateAction(const FString& InTitle, const FString& InCategory, FText InTooltip,
		TArray<TSharedPtr<FEdGraphSchemaAction>>& OutActions,FFieldParam InFieldParam)
	{
		//static_assert(std::is_base_of<UK3Node, T>::value, "UK3Node is not a base class of T");
		check(T::StaticClass()->IsChildOf<UK3Node>());
		const FText MenuDesc = FText::FromString(InTitle);
		const FText	Category = FText::FromString(InCategory == "" ? TEXT("Default") : InCategory);
		const FText Tooltip = InTooltip;

		TSharedPtr<FBlueprintToolSchemaAction> Action(new FBlueprintToolSchemaAction(Category, MenuDesc, Tooltip, 0, InFieldParam));
		Action->K3NodeClass = T::StaticClass();
		OutActions.Add(Action);
	}


	template<typename T>
	static TSharedRef<FEdGraphSchemaAction> CreateAction(const FString& InTitle, const FString& InCategory,const FText& InTooltip,
		FFieldParam InFieldParam)
	{
		//static_assert(std::is_base_of<UK3Node, T>::value, "UK3Node is not a base class of T");
		check(T::StaticClass()->IsChildOf<UK3Node>());
		const FText MenuDesc = FText::FromString(InTitle);
		const FText	Category = FText::FromString(InCategory);
		const FText Tooltip = InTooltip;

		TSharedPtr<FBlueprintToolSchemaAction> Action(new FBlueprintToolSchemaAction(Category, MenuDesc, Tooltip, 0, InFieldParam));
		Action->K3NodeClass = T::StaticClass();
		return Action.ToSharedRef();
	}
};