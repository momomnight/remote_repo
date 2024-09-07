#include "Viewport/BlueprintViewportClient.h"
#include "AssetEditor/Architect/AssetArchitectToolkit.h"

#include "EditorModeManager.h"
#include "AssetEditorModeManager.h"
#include "PreviewScene.h"
#include "SEditorViewport.h"
#include "BlueprintData.h"


FBPEditorViewportClient::FBPEditorViewportClient(
	TWeakPtr<class FBlueprintToolEditorToolkit> InM,
	FPreviewScene* InPreviewScene, 
	const TWeakPtr<SEditorViewport>& InEditorViewportWidget, 
	UBlueprintData* InData)
	:Super(nullptr, InPreviewScene, InEditorViewportWidget)
	,MyData(InData)
{
	StaticCastSharedPtr<FAssetEditorModeManager>(ModeTools)->SetPreviewScene(PreviewScene);

	if (!IsSetShowGridChecked())
	{
		SetShowGrid();
	}
	SetShowBounds(true);
	SetRealtime(true);
	SetViewMode(EViewModeIndex::VMI_Lit);
	OverrideNearClipPlane(1.f);//¸²¸Ç½ü¼ô²ÃÃæ
	SetViewLocation(FVector(500.f, 300.f, 500.f));

	DrawHelper.bDrawGrid = true;
	DrawHelper.bDrawPivot = true;

	DrawHelper.GridColorAxis = FColor(0,0,160);
	DrawHelper.GridColorMajor = FColor(144,0,0);
	DrawHelper.GridColorMinor = FColor(0,128,0);

	DrawHelper.PerspectiveGridSize = 2048.f;
	DrawHelper.NumCells = DrawHelper.PerspectiveGridSize / 32.f;
}

void FBPEditorViewportClient::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);


	PreviewScene->GetWorld()->Tick(ELevelTick::LEVELTICK_All, DeltaSeconds);
}
