#include "AssetEditor/Architect/AssetArchitectActions.h"
#include "BlueprintData.h"
#include "Toolkits\IToolkitHost.h"
#include "ToolMenuSection.h"
#include "AssetEditor/Architect/AssetArchitectToolkit.h"


#define LOCTEXT_NAMESPACE "FBlueprintTypeActions"

FText FBlueprintTypeActions::GetName() const
{
	return LOCTEXT("FBlueprintTypeActionsName","Blueprint Theme");
}

UClass* FBlueprintTypeActions::GetSupportedClass() const
{
	return UBlueprintData::StaticClass();
}

FColor FBlueprintTypeActions::GetTypeColor() const
{
	return FColor::Cyan;
}

void FBlueprintTypeActions::OpenAssetEditor(const TArray<UObject*>& InObjects, TSharedPtr<class IToolkitHost> EditWithinLevelEditor)
{
	//FSimpleAssetEditor::CreateEditor(EToolkitMode::Standalone, EditWithinLevelEditor, InObjects);

	EToolkitMode::Type Mode = EditWithinLevelEditor.IsValid() ? EToolkitMode::WorldCentric : EToolkitMode::Standalone;

	for (auto& TempObj : InObjects)
	{
		auto BlueprintDataAsset = Cast<UBlueprintData>(TempObj);

		if (BlueprintDataAsset)
		{
			TSharedPtr<FBlueprintToolEditorToolkit> Toolkit = MakeShareable(new FBlueprintToolEditorToolkit);
			Toolkit->Initialize(BlueprintDataAsset, Mode, EditWithinLevelEditor);
		}
	}

}

bool FBlueprintTypeActions::HasActions(const TArray<UObject*>& InObjects) const
{
	return false;
}

void FBlueprintTypeActions::GetActions(const TArray<UObject*>& InObjects, FToolMenuSection& Section)
{
}

uint32 FBlueprintTypeActions::GetCategories()
{
	return EAssetTypeCategories::Basic;
}

#undef LOCTEXT_NAMESPACE