#pragma once

#include "Toolkits\AssetEditorToolkit.h"
#include "Misc\NotifyHook.h"


//FSlateApplication::Get().IsDragDropping();

class FBlueprintToolEditorToolkit : public FAssetEditorToolkit, public FNotifyHook, public FTickableEditorObject
{
	//GetStatId, IsTickable, and Tick methods
public:
	using Super = FAssetEditorToolkit;

	FBlueprintToolEditorToolkit();

	virtual bool IsTickable() const  override { return true; }
	virtual void Tick(float DeltaTime) override;
	virtual TStatId GetStatId() const override { RETURN_QUICK_DECLARE_CYCLE_STAT(FBlueprintToolEditorToolkit, STATGROUP_TaskGraphTasks); }
	//虚函数，基类调用
	virtual void RegisterTabSpawners(const TSharedRef<class FTabManager>& InTabManager) override;
	virtual void UnregisterTabSpawners(const TSharedRef<class FTabManager>& InTabManager) override;
	void Initialize(class UBlueprintData* InAsset, const EToolkitMode::Type InMode, const TSharedPtr<class IToolkitHost>& InToolKitHost);

private:
	TSharedRef<class SGraphEditor> CreateBPGrpahEditor(class UEdGraph* InGrpah);
	void BindCommands();

	void ExtendToolBar();

	void Compile();
	void Help();
	void Run();

	virtual void SaveAsset_Execute() override;
	
	//Data
	virtual UBlueprintData* GetBlueprintData() const;

private:
	TSharedRef<class SDockTab> SpawnPreviewTab(const class FSpawnTabArgs& InTabArgs);
	TSharedRef<class SDockTab> SpawnContentBrowserTab(const class FSpawnTabArgs& InTabArgs);
	TSharedRef<class SDockTab> SpawnBlueprintGraphTab(const class FSpawnTabArgs& InTabArgs);
	TSharedRef<class SDockTab> SpawnNodeListPaletteTab(const class FSpawnTabArgs& InTabArgs);
	TSharedRef<class SDockTab> SpawnDetailsTab(const class FSpawnTabArgs& InTabArgs);
	TSharedRef<class SDockTab> SpawnPreviewSettingsTab(const class FSpawnTabArgs& InTabArgs);

private:
	void AssetDropped(const FDragDropEvent&, TArrayView<FAssetData>);
	bool IsAssetAcceptableForDrop(TArrayView<FAssetData>) const;
	FVector2D GetAssetDropGridLocation() const;


	void OnSelectedBPNodesChanged(const TSet<class UObject*>& SelectionNode);

public:
	
	FORCEINLINE TSharedRef<class SGraphEditor> GetGraphEditor(){return GraphEditor.ToSharedRef();}


public:
	virtual FName GetToolkitFName() const override;
	virtual FText GetBaseToolkitName() const override;
	virtual FString GetWorldCentricTabPrefix() const override;
	virtual FLinearColor GetWorldCentricTabColorScale() const override;

private:

	void DeleteSelectedNodes();
	bool CanDeleteNodes() const;

	void CopySelectedNodes();
	bool CanCopyNodes() const;

	void PasteNodes();
	bool CanPasteNodes()const;

	void CutSelectedNodes();
	bool CanCutNodes()const;

	void DuplicateNodes();
	bool CanDuplicateNodes() const;

	void SelectAllNodes();
	bool CanSelectAllNodes()const;

	void Undo();
	void Redo();

private:
	
	class UBlueprintData* MyData;

	class UStaticMeshComponent* StaticMeshComponent;

private:	
	TSharedPtr<class IDetailsView> PropertyEditor;
	TSharedPtr<class SBlueprintViewportClient> PreviewViewport;
	TSharedPtr<class SGraphEditor> GraphEditor;//Graph的显示
	TSharedPtr<class SBlueprintNodeListPalette> NodeListPalette;
	TSharedPtr<class FUICommandList> GraphEditorCommands;
	TSharedPtr<class SObjectEditorDropTarget> AssetDropTarget;
};