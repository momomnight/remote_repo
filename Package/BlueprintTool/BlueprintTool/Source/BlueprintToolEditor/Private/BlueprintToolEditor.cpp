// Copyright Epic Games, Inc. All Rights Reserved.

#include "BlueprintToolEditor.h"

#include "IAssetTypeActions.h"
#include "IAssetTools.h"
#include "AssetToolsModule.h"
#include "AssetEditor/Architect/AssetArchitectActions.h"
#include "Modules\ModuleManager.h"
#include "Factory/Blueprint/BlueprintToolFactory.h"
#include "Details/DescriptionBPTool.h"
#include "Details/BlueprintPropertyTypeCustomization.h"
#include "BlueprintEditor/GraphNode/CAssetThumbnailPool.h"


#define LOCTEXT_NAMESPACE "FBlueprintToolEditorModule"

void FBlueprintToolEditorModule::StartupModule()
{
	FObjectEdiotrThumbnailPool::Create();


	IAssetTools& AssetTools = FAssetToolsModule::GetModule().Get();
	FPropertyEditorModule& PropertyEditorModule = FModuleManager::Get().LoadModuleChecked<FPropertyEditorModule>("PropertyEditor");

	RegisterPropertyTypeCustomization(PropertyEditorModule, FDescriptionBPTool::StaticStruct()->GetFName(), FOnGetPropertyTypeCustomizationInstance::CreateStatic(&FBlueprintVariableMappings::MakeInstance));
	RegisterAssetTypeAction(AssetTools, MakeShareable(new FBlueprintTypeActions));	
	BTGraphPanelFactoryUtility::RegisterBTGraphPanelFactory();

	PropertyEditorModule.NotifyCustomizationModuleChanged();

}

void FBlueprintToolEditorModule::ShutdownModule()
{

	if (FModuleManager::Get().IsModuleLoaded("AssetTools"))
	{
		IAssetTools& AssetTools = FAssetToolsModule::GetModule().Get();
		for (auto& Temp : RegisteredAssetTypeActions)
		{
			AssetTools.UnregisterAssetTypeActions(Temp.ToSharedRef());
		}
		RegisteredAssetTypeActions.Empty();
	}

	if (FModuleManager::Get().IsModuleLoaded("PropertyEditor"))
	{
		FPropertyEditorModule& PropertyEditorModule = FModuleManager::Get().LoadModuleChecked<FPropertyEditorModule>("PropertyEditor");
		for (auto& Temp : RegisteredPropertyTypes)
		{
			PropertyEditorModule.UnregisterCustomPropertyTypeLayout(Temp);
		}
		
		PropertyEditorModule.NotifyCustomizationModuleChanged();
		RegisteredPropertyTypes.Empty();
	}

	BTGraphPanelFactoryUtility::UnregisterBTGraphPanelFactory();
}

void FBlueprintToolEditorModule::RegisterAssetTypeAction(IAssetTools& AssetTools, TSharedRef<class IAssetTypeActions> Action)
{
	AssetTools.RegisterAssetTypeActions(Action);
	RegisteredAssetTypeActions.Add(Action);
}

void FBlueprintToolEditorModule::RegisterPropertyTypeCustomization(FPropertyEditorModule& PropertyEditorModule, FName PropertName, FOnGetPropertyTypeCustomizationInstance Generator)
{
	check(PropertName != NAME_None);
	PropertyEditorModule.RegisterCustomPropertyTypeLayout(PropertName, Generator);
	RegisteredPropertyTypes.Add(PropertName);
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FBlueprintToolEditorModule, BlueprintToolEditor)