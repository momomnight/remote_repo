// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "SEditorViewport.h"

class BLUEPRINTTOOLEDITOR_API SBlueprintViewportClient : public SEditorViewport
{

public:
	SLATE_BEGIN_ARGS(SBlueprintViewportClient){}

	SLATE_ARGUMENT(TWeakPtr<class FBlueprintToolEditorToolkit>, BPEditorPtr)

	SLATE_ARGUMENT(class UBlueprintData*, ObjectToEdit)

	SLATE_END_ARGS()


public:
	void Construct(const FArguments& InArgs, class UStaticMeshComponent* StaticMeshComponent);

	virtual TSharedRef<FEditorViewportClient> MakeEditorViewportClient() override;

	virtual void Tick(const FGeometry& AllottedGeometry, const double InCurrentTime, const float InDeltaTime) override;

	FORCEINLINE TSharedPtr<class FAdvancedPreviewScene> GetPreviewScene(){return PreviewScene;}
private:
	TWeakPtr<class FBlueprintToolEditorToolkit> BPEditorPtr;
	TSharedPtr<class FAdvancedPreviewScene> PreviewScene;
	TSharedPtr<class FBPEditorViewportClient> EditorViewportClient;
	
	class UBlueprintData* ObjectToEdit;

	class USkyLightComponent* Skylight;
	class USkyAtmosphereComponent * AtmosphericFog;
};
