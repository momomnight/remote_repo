// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"
#include "PropertyEditorDelegates.h"


class FBlueprintToolEditorModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

	void RegisterAssetTypeAction(class IAssetTools& AssetTools, TSharedRef<class IAssetTypeActions> Action);
	void RegisterPropertyTypeCustomization(class FPropertyEditorModule& PropertyEditorModule, FName PropertName, FOnGetPropertyTypeCustomizationInstance Generator);
private:
	TArray<TSharedPtr<class IAssetTypeActions>> RegisteredAssetTypeActions;

	TSet<FName> RegisteredPropertyTypes;

};
