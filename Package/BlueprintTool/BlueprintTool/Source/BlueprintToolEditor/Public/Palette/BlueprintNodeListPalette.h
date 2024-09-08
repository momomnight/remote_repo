// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once
#include "SGraphPalette.h"

class BLUEPRINTTOOLEDITOR_API SBlueprintNodeListPalette :public SGraphPalette
{

public:
	using Super = SGraphPalette;

	SLATE_BEGIN_ARGS(SBlueprintNodeListPalette){}

	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs, TWeakPtr<class FBlueprintToolEditorToolkit> InBlueprintToolkit);

	virtual TSharedRef<SWidget> OnCreateWidgetForAction(struct FCreateWidgetForActionData* const InCreateData) override;

	virtual FReply OnActionDragged(const TArray< TSharedPtr<struct FEdGraphSchemaAction> >& InActions, const struct FPointerEvent& MouseEvent) override;

	virtual void CollectAllActions(struct FGraphActionListBuilderBase& OutAllActions) override;

private:
	TWeakPtr<class FBlueprintToolEditorToolkit> BlueprintToolkit;


};