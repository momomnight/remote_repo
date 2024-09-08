// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "EditorViewportClient.h"


class BLUEPRINTTOOLEDITOR_API FBPEditorViewportClient : public FEditorViewportClient, public TSharedFromThis<FBPEditorViewportClient>
{

public:
	using Super = FEditorViewportClient;

	FBPEditorViewportClient(TWeakPtr<class FBlueprintToolEditorToolkit> InEditorToolkit,
		class FPreviewScene* InPreviewScene, 
		const TWeakPtr<SEditorViewport>& InEditorViewportWidget, 
		class UBlueprintData* InData);

	virtual void Tick(float DeltaSeconds) override;

private:
	class UBlueprintData* MyData;

};