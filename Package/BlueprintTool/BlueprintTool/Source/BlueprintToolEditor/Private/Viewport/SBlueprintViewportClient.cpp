#include "Viewport/SBlueprintViewportClient.h"
#include "Viewport/BlueprintViewportClient.h"

#include "PreviewScene.h"
#include "AdvancedPreviewScene.h"

#include "Components\SkyLightComponent.h"
#include "Components\SkyAtmosphereComponent.h"
#include "Components\DirectionalLightComponent.h"

void SBlueprintViewportClient::Construct(const FArguments& InArgs, class UStaticMeshComponent* StaticMeshComponent)
{
	BPEditorPtr = InArgs._BPEditorPtr;
	ObjectToEdit = InArgs._ObjectToEdit;

	{
		FPreviewScene::ConstructionValues ConstructionArgs;
		ConstructionArgs.bCreatePhysicsScene = false;
		ConstructionArgs.LightBrightness = 3;
		ConstructionArgs.SkyBrightness = 1;

		PreviewScene = MakeShareable(new FAdvancedPreviewScene(ConstructionArgs));
		PreviewScene->SetFloorOffset(-100000);

		Skylight = NewObject<USkyLightComponent>(PreviewScene->GetWorld());
		AtmosphericFog = NewObject<USkyAtmosphereComponent>(PreviewScene->GetWorld());
		PreviewScene->AddComponent(Skylight, FTransform::Identity);
		PreviewScene->AddComponent(AtmosphericFog, FTransform::Identity);

		PreviewScene->DirectionalLight->SetMobility(EComponentMobility::Movable);
		PreviewScene->DirectionalLight->CastShadows = true;
		PreviewScene->DirectionalLight->CastStaticShadows = true;
		PreviewScene->DirectionalLight->CastDynamicShadows = true;
		PreviewScene->DirectionalLight->SetIntensity(3);
	}

	if (StaticMeshComponent)
	{
		StaticMeshComponent->SetRelativeScale3D(FVector(3.f, 3.f, 1.f));
		StaticMeshComponent->SetVisibility(true);
		PreviewScene->AddComponent(StaticMeshComponent, FTransform::Identity);
	}

	SEditorViewport::Construct(SEditorViewport::FArguments());
}

TSharedRef<FEditorViewportClient> SBlueprintViewportClient::MakeEditorViewportClient()
{
	EditorViewportClient = MakeShareable(new FBPEditorViewportClient(BPEditorPtr, PreviewScene.Get(), SharedThis(this), ObjectToEdit));

	return EditorViewportClient.ToSharedRef();
}

void SBlueprintViewportClient::Tick(const FGeometry& AllottedGeometry, const double InCurrentTime, const float InDeltaTime)
{
	SEditorViewport::Tick(AllottedGeometry, InCurrentTime, InDeltaTime);
}
