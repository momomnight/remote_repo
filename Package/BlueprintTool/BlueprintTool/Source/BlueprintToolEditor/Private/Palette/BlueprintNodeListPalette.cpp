#include "Palette/BlueprintNodeListPalette.h"
#include "AssetEditor/Architect/AssetArchitectToolkit.h"
#include "BlueprintEditor/Core/Architect/BTSchema.h"

#include "Styling\AppStyle.h"
#include "SGraphActionMenu.h"
#include "EdGraph\EdGraphSchema.h"
#include "Input\Events.h"



void SBlueprintNodeListPalette::Construct(const FArguments& InArgs, TWeakPtr<class FBlueprintToolEditorToolkit> InBlueprintToolkit)
{
	BlueprintToolkit = InBlueprintToolkit;

	ChildSlot
	[
		SNew(SBorder)
		.Padding(2.f)
		.BorderImage(FAppStyle::GetBrush("ToolPanel.GroupBorder"))
		[
			SNew(SVerticalBox)
			+ SVerticalBox::Slot()
			[
				SNew(SOverlay)
				+ SOverlay::Slot()
				[
					SAssignNew(GraphActionMenu, SGraphActionMenu)
					.OnActionDragged_Raw(this, &SBlueprintNodeListPalette::OnActionDragged)
					.OnCreateWidgetForAction(this, &SBlueprintNodeListPalette::OnCreateWidgetForAction)
					.OnCollectAllActions(this, &SBlueprintNodeListPalette::CollectAllActions)
				]
			]
		]
	
	];

}

TSharedRef<SWidget> SBlueprintNodeListPalette::OnCreateWidgetForAction(FCreateWidgetForActionData* const InCreateData)
{
	return Super::OnCreateWidgetForAction(InCreateData);
}

FReply SBlueprintNodeListPalette::OnActionDragged(const TArray<TSharedPtr<FEdGraphSchemaAction>>& InActions, const FPointerEvent& MouseEvent)
{
	return Super::OnActionDragged(InActions, MouseEvent);
}

//每次打开资产编辑器都会调用,但打开后不再调用
void SBlueprintNodeListPalette::CollectAllActions(FGraphActionListBuilderBase& OutAllActions)
{
	FGraphActionMenuBuilder ActionMenuBuilder;

	if (BlueprintToolkit.IsValid())
	{
		TSharedPtr<SGraphEditor> BPGraphEditor = BlueprintToolkit.Pin()->GetGraphEditor();	

		if (BPGraphEditor.IsValid())
		{
			if(const UBlueprintToolSchema* Schema = Cast<UBlueprintToolSchema>(BPGraphEditor->GetCurrentGraph()->GetSchema()))
			{
				TArray<TSharedPtr<FEdGraphSchemaAction>> Actions;
				Schema->GetActionList(Actions);

				for (auto& Action : Actions)
				{
					ActionMenuBuilder.AddAction(Action);
				}
			}
		}
	}

	OutAllActions.Append(ActionMenuBuilder);
}
