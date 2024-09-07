#pragma once

//#include "CoreMinimal.h"
#include "AssetTypeActions_Base.h"

class BLUEPRINTTOOLEDITOR_API FBlueprintTypeActions : public FAssetTypeActions_Base
{
public:
	/** Returns the name of this type */
	virtual FText GetName() const override;

	/** Get the supported class of this type. */
	virtual UClass* GetSupportedClass() const override;

	/** Returns the color associated with this type */
	virtual FColor GetTypeColor() const override;

	virtual void OpenAssetEditor(const TArray<UObject*>& InObjects, TSharedPtr<class IToolkitHost> EditWithinLevelEditor = TSharedPtr<IToolkitHost>()) override;

	virtual bool HasActions(const TArray<UObject*>& InObjects) const override;

	/** Generates a menu section for the specified objects. */
	virtual void GetActions(const TArray<UObject*>& InObjects, struct FToolMenuSection& Section) override;

	virtual uint32 GetCategories() override;

};