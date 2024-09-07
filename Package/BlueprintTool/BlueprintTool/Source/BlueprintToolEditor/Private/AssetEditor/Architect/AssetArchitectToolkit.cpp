
#include "AssetEditor/Architect/AssetArchitectToolkit.h"
#include "Windows\WindowsPlatformApplicationMisc.h"
#include "Framework\Commands\GenericCommands.h"
#include "Viewport/SBlueprintViewportClient.h"
#include "Palette/BlueprintNodeListPalette.h"
#include "Framework\Commands\UICommandList.h"
#include "Subsystems\AssetEditorSubsystem.h"
#include "Framework\Docking\LayoutService.h"
#include "Framework\Docking\TabManager.h"
#include "Framework\Commands\UIAction.h"
#include "SAdvancedPreviewDetailsTab.h"
#include "Widgets\Docking\SDockTab.h"
#include "IContentBrowserSingleton.h"
#include "Modules\ModuleManager.h"
#include "ContentBrowserModule.h"
#include "Commands/BTCommands.h"
#include "Textures\SlateIcon.h"
#include "ScopedTransaction.h"
#include "Styling\AppStyle.h"
#include "EdGraphUtilities.h"
#include "EdGraph\EdGraph.h"
#include "BlueprintData.h"
#include "IDetailsView.h"
#include "CoreGlobals.h"
#include "GraphEditor.h"
#include "SNodePanel.h"
#include "Misc\Guid.h"
#include "ToolMenus.h"

#include "BlueprintEditor/Core/Architect/BPArchitectEdGraph.h"
#include "Compile/BTCompilationUtilities.h"
#include "SimpleCodeLibrary.h"
#include "BlueprintEditor/GraphNode/SObjectEditorDropTarget.h"
#include "SimpleCodeEvent.h"

namespace EditorTabId
{
	const FName ViewportId = "ViewportId";
	const FName PreviewViewportId = "PreviewViewportId";
	const FName ContentBrowerId = "ContentBrowerId";
	const FName DetailsId = "DetailsId";
	const FName BlueprintGraphId = "BlueprintGraphId";
	const FName BPNodeListId = "BPNodeListId";
	const FName PreviewSettingsId = "PreviewSettingsId";

	const FName AssetEditorToolBarId = "AssetEditorToolbar.CommonActions";
}

#define LOCTEXT_NAMESPACE "BlueprintToolEditorToolkit"
#pragma optimize("", off)

FBlueprintToolEditorToolkit::FBlueprintToolEditorToolkit():MyData(nullptr), PreviewViewport(nullptr)
{
}

void FBlueprintToolEditorToolkit::Tick(float DeltaTime)
{
	if (FSlateApplication::Get().IsDragDropping())
	{		
		if (AssetDropTarget.IsValid() && AssetDropTarget->GetOverlayVisibility().IsVisible())
		{
			AssetDropTarget->SetVisibility(EVisibility::Visible);
		}
		else
		{
			AssetDropTarget->SetVisibility(EVisibility::Collapsed);
		}
	}
	else
	{
		if (AssetDropTarget.IsValid())
		{
			AssetDropTarget->SetVisibility(EVisibility::Collapsed);
		}
	}
}

void FBlueprintToolEditorToolkit::RegisterTabSpawners(const TSharedRef<class FTabManager>& InTabManager)
{
	Super::RegisterTabSpawners(InTabManager);
	InTabManager->RegisterTabSpawner(EditorTabId::PreviewViewportId, FOnSpawnTab::CreateSP(this, &FBlueprintToolEditorToolkit::SpawnPreviewTab))
		.SetDisplayName(LOCTEXT("PreviewTab","BP_Preview"))
		.SetIcon(FSlateIcon(FAppStyle::Get().GetStyleSetName(), "LevelEditor.Tabs.Viewports"));
	InTabManager->RegisterTabSpawner(EditorTabId::ContentBrowerId, FOnSpawnTab::CreateSP(this, &FBlueprintToolEditorToolkit::SpawnContentBrowserTab))
		.SetDisplayName(LOCTEXT("ContentBrowerTab", "BP_ContentBrower"))
		.SetIcon(FSlateIcon(FAppStyle::Get().GetStyleSetName(), "LevelEditor.Tabs.ContentBrower"));
	InTabManager->RegisterTabSpawner(EditorTabId::BlueprintGraphId, FOnSpawnTab::CreateSP(this, &FBlueprintToolEditorToolkit::SpawnBlueprintGraphTab))
		.SetDisplayName(LOCTEXT("BlueprintGraphTab", "BP_BlueprintGraph"))
		.SetIcon(FSlateIcon(FAppStyle::Get().GetStyleSetName(), "LevelEditor.Tabs.Viewports"));
	InTabManager->RegisterTabSpawner(EditorTabId::BPNodeListId, FOnSpawnTab::CreateSP(this, &FBlueprintToolEditorToolkit::SpawnNodeListPaletteTab))
		.SetDisplayName(LOCTEXT("NodeListPaletteTab", "BP_NodeListPalette"))
		.SetIcon(FSlateIcon(FAppStyle::Get().GetStyleSetName(), "Kismet.Tabs.Palette"));
	InTabManager->RegisterTabSpawner(EditorTabId::DetailsId, FOnSpawnTab::CreateSP(this, &FBlueprintToolEditorToolkit::SpawnDetailsTab))
		.SetDisplayName(LOCTEXT("DetailsTab", "BP_Details"))
		.SetIcon(FSlateIcon(FAppStyle::Get().GetStyleSetName(), "LevelEditor.Tabs.Details"));
	InTabManager->RegisterTabSpawner(EditorTabId::PreviewSettingsId, FOnSpawnTab::CreateSP(this, &FBlueprintToolEditorToolkit::SpawnPreviewSettingsTab))
		.SetDisplayName(LOCTEXT("PreviewSettingsTabLabel", "BP_PreviewSettings"))
		.SetIcon(FSlateIcon(FAppStyle::Get().GetStyleSetName(), "Kismet.Tabs.Palette"));
}

void FBlueprintToolEditorToolkit::UnregisterTabSpawners(const TSharedRef<class FTabManager>& InTabManager)
{
	InTabManager->UnregisterTabSpawner(EditorTabId::PreviewViewportId);
	InTabManager->UnregisterTabSpawner(EditorTabId::ContentBrowerId);
	InTabManager->UnregisterTabSpawner(EditorTabId::BlueprintGraphId);
	InTabManager->UnregisterTabSpawner(EditorTabId::BPNodeListId);
	InTabManager->UnregisterTabSpawner(EditorTabId::DetailsId);
	InTabManager->UnregisterTabSpawner(EditorTabId::PreviewSettingsId);
	Super::UnregisterTabSpawners(InTabManager);
	FBTCommands::Unregister();
}

void FBlueprintToolEditorToolkit::Initialize(UBlueprintData* InAsset, const EToolkitMode::Type InMode, const TSharedPtr<class IToolkitHost>& InToolKitHost)
{
	check(InAsset);
	
	FBTCommands::Register();
	BindCommands();

	MyData = InAsset;
	if (!MyData->EdGraph)
	{
		UBPArchitectEdGraph* Graph = NewObject<UBPArchitectEdGraph>(MyData, UBPArchitectEdGraph::StaticClass(), NAME_None, RF_Transactional);
		Graph->InitializeGraph();
		MyData->EdGraph = Graph;//为了能序列化
	}

	StaticMeshComponent = NewObject<UStaticMeshComponent>();


	// 
	// |----------------------------------------|
	// |		|					|			|
	// |		|					|			|
	// |Viewport|					|			|
	// |		|	  Blueprint		|			|
	// |		|					|BPNodeList	|
	// |--------|					|			|
	// |		|------------------	|			|
	// |Details	|					|			|
	// |		|	ContentBrowser	|			|
	// |		|					|			|
	// |----------------------------------------|
	// 
	// 

	const TSharedRef<FTabManager::FLayout> Layout = FTabManager::NewLayout("StandaloneWindowCustomLayout");

	TSharedRef<FTabManager::FArea> PrimaryArea = FTabManager::NewPrimaryArea()->SetOrientation(Orient_Vertical);
	Layout->AddArea(PrimaryArea);

	TSharedRef<FTabManager::FSplitter> MainSplitter = FTabManager::NewSplitter()->SetOrientation(Orient_Horizontal);
	PrimaryArea->Split(MainSplitter);

	TSharedRef<FTabManager::FSplitter> SecondLevelSplitter1 = FTabManager::NewSplitter()
		->SetOrientation(Orient_Vertical)->SetSizeCoefficient(0.23f);
	TSharedRef<FTabManager::FSplitter> SecondLevelSplitter2 = FTabManager::NewSplitter()
		->SetOrientation(Orient_Vertical)->SetSizeCoefficient(0.54f);

	//Viewport
	TSharedRef<FTabManager::FStack> ViewportStack = FTabManager::NewStack()
		->SetSizeCoefficient(0.5f)
		->AddTab(EditorTabId::PreviewViewportId, ETabState::OpenedTab);
	//Details
	TSharedRef<FTabManager::FStack> DetailsStack = FTabManager::NewStack()
		->SetSizeCoefficient(0.5f)
		->AddTab(EditorTabId::DetailsId, ETabState::OpenedTab)
		->AddTab(EditorTabId::PreviewSettingsId, ETabState::OpenedTab);//PreviewSettings

	SecondLevelSplitter1->Split(ViewportStack)->Split(DetailsStack);


	//Blueprint
	TSharedRef<FTabManager::FStack> BlueprintStack = FTabManager::NewStack()
		->SetSizeCoefficient(0.6f)->SetHideTabWell(true)
		->AddTab(EditorTabId::BlueprintGraphId, ETabState::OpenedTab);
	//ContentBrowser
	TSharedRef<FTabManager::FStack> ContentBrowserStack = FTabManager::NewStack()
		->SetSizeCoefficient(0.4f)
		->AddTab(EditorTabId::ContentBrowerId, ETabState::OpenedTab);

	SecondLevelSplitter2->Split(BlueprintStack)->Split(ContentBrowserStack);

	//BPNodeList
	TSharedRef<FTabManager::FStack> BPNodeListStack = FTabManager::NewStack()
		->AddTab(EditorTabId::BPNodeListId, ETabState::OpenedTab)->SetSizeCoefficient(0.23f);


	MainSplitter->Split(SecondLevelSplitter1)->Split(SecondLevelSplitter2)->Split(BPNodeListStack);

#if UE_BUILD_DEVELOPMENT
	FLayoutSaveRestore::SaveToConfig(GEditorLayoutIni, Layout);
#endif

	InitAssetEditor(InMode, InToolKitHost, EditorTabId::ViewportId, Layout,
		true, true, MyData);

	RegenerateMenusAndToolbars();

}

TSharedRef<SGraphEditor> FBlueprintToolEditorToolkit::CreateBPGrpahEditor(UEdGraph* InGrpah)
{
	FGraphAppearanceInfo AppearanceInfo;
	AppearanceInfo.CornerText = LOCTEXT("MyAppearanceCornerText","BP Editor");

	TSharedRef<SWidget> TitleBar = 
		SNew(SBorder)
		.BorderImage(FAppStyle::GetBrush(TEXT("Graph.TitleBackground")))
		.HAlign(HAlign_Fill)
		[
			SNew(SHorizontalBox)
			+ SHorizontalBox::Slot()
			.HAlign(HAlign_Center)
			.FillWidth(1.f)
			[
				SNew(STextBlock)
				.Text(LOCTEXT("MyText","MyText"))
				.TextStyle(FAppStyle::Get(), TEXT("GraphBreadcrumbButtonText"))
			]
				
		];
	
	//绑定命令 (自定义的没有, 绑定后才有)
	GraphEditorCommands = MakeShareable(new FUICommandList);
	{
		GraphEditorCommands->MapAction(FGenericCommands::Get().Delete,
			FExecuteAction::CreateSP(this, &FBlueprintToolEditorToolkit::DeleteSelectedNodes),
			FCanExecuteAction::CreateSP(this, &FBlueprintToolEditorToolkit::CanDeleteNodes)
		);
		GraphEditorCommands->MapAction(FGenericCommands::Get().Copy,
			FExecuteAction::CreateSP(this, &FBlueprintToolEditorToolkit::CopySelectedNodes),
			FCanExecuteAction::CreateSP(this, &FBlueprintToolEditorToolkit::CanCopyNodes)
		);
		GraphEditorCommands->MapAction(FGenericCommands::Get().Paste,
			FExecuteAction::CreateSP(this, &FBlueprintToolEditorToolkit::PasteNodes),
			FCanExecuteAction::CreateSP(this, &FBlueprintToolEditorToolkit::CanPasteNodes)
		);
		GraphEditorCommands->MapAction(FGenericCommands::Get().Cut,
			FExecuteAction::CreateSP(this, &FBlueprintToolEditorToolkit::CutSelectedNodes),
			FCanExecuteAction::CreateSP(this, &FBlueprintToolEditorToolkit::CanCutNodes)
		);
		GraphEditorCommands->MapAction(FGenericCommands::Get().Duplicate,
			FExecuteAction::CreateSP(this, &FBlueprintToolEditorToolkit::DuplicateNodes),
			FCanExecuteAction::CreateSP(this, &FBlueprintToolEditorToolkit::CanDuplicateNodes)
		);
		GraphEditorCommands->MapAction(FGenericCommands::Get().SelectAll,
			FExecuteAction::CreateSP(this, &FBlueprintToolEditorToolkit::SelectAllNodes),
			FCanExecuteAction::CreateSP(this, &FBlueprintToolEditorToolkit::CanSelectAllNodes)
		);
		GraphEditorCommands->MapAction(FGenericCommands::Get().Undo,
			FExecuteAction::CreateSP(this, &FBlueprintToolEditorToolkit::Undo)	
		);
		GraphEditorCommands->MapAction(FGenericCommands::Get().Redo,
			FExecuteAction::CreateSP(this, &FBlueprintToolEditorToolkit::Redo)
		);
	}
	

	//绑定代理，点击蓝图节点时，切换对象属性
	SGraphEditor::FGraphEditorEvents InGraphEvent;
	InGraphEvent.OnSelectionChanged.BindSP(this, &FBlueprintToolEditorToolkit::OnSelectedBPNodesChanged);

	//创建SWidget
	TSharedPtr<SGraphEditor> GrpahEditorInstance; 
	SAssignNew(GrpahEditorInstance, SGraphEditor)
		.Appearance(AppearanceInfo)
		.TitleBar(TitleBar)
		.GraphToEdit(InGrpah)
		.GraphEvents(InGraphEvent)
		.AdditionalCommands(GraphEditorCommands);//
		
	return GrpahEditorInstance.ToSharedRef();
}

void FBlueprintToolEditorToolkit::BindCommands()
{
	const FBTCommands& Commands = FBTCommands::Get();
	ToolkitCommands->MapAction(Commands.Compile, FExecuteAction::CreateRaw(this, &FBlueprintToolEditorToolkit::Compile));
	ToolkitCommands->MapAction(Commands.Help, FExecuteAction::CreateRaw(this, &FBlueprintToolEditorToolkit::Help));
	ToolkitCommands->MapAction(Commands.Run, FExecuteAction::CreateRaw(this, &FBlueprintToolEditorToolkit::Run));

	//UToolMenus::RegisterStartupCallback(FSimpleMulticastDelegate::FDelegate::CreateRaw(this, &FBlueprintToolEditorToolkit::ExtendToolBar));
	ExtendToolBar();
}

void FBlueprintToolEditorToolkit::ExtendToolBar()
{

	//AssetEditor.BlueprintToolEditorToolkit.ToolBar
	//使用GetToolMenuToolbarName()
	const FBTCommands& Commands = FBTCommands::Get();
	UToolMenus* ToolMenus = UToolMenus::Get();

	FName ToolBarName = GetToolMenuToolbarName();
	UToolMenu* ToolMenu = ToolMenus->ExtendMenu(ToolBarName);
	{
		FToolMenuInsert InsertPos(TEXT("Asset"), EToolMenuInsertType::Before);

		{
			FToolMenuSection& SectionCompile = ToolMenu->FindOrAddSection(TEXT("Compile"));
			SectionCompile.InsertPosition = InsertPos;

			SectionCompile.AddSeparator(TEXT("Compile"));

			FToolMenuEntry MenuEntry = FToolMenuEntry::InitToolBarButton(
				Commands.Compile, LOCTEXT("CompileButton", "Compile"), LOCTEXT("CompileTooltip", "Compile Blueprint"),
				FSlateIcon(), TEXT("Compile"), FName(TEXT("Compile"))
			);

			SectionCompile.AddEntry(MenuEntry);
		}

		{
			FToolMenuSection& SectionHelp = ToolMenu->FindOrAddSection(TEXT("Help"));
			SectionHelp.InsertPosition = InsertPos;

			SectionHelp.AddSeparator(TEXT("Help"));
			FToolMenuEntry MenuEntry = FToolMenuEntry::InitToolBarButton(
				Commands.Help, LOCTEXT("HelpButton", "Help"), LOCTEXT("HelpTooltip", "Help Document"),
				FSlateIcon(), TEXT("Help"), FName(TEXT("Help"))
			);

			SectionHelp.AddEntry(MenuEntry);
		}

		{
			FToolMenuSection& SectionRun = ToolMenu->FindOrAddSection(TEXT("Run"));
			SectionRun.InsertPosition = InsertPos;

			SectionRun.AddSeparator(TEXT("Run"));
			FToolMenuEntry MenuEntry = FToolMenuEntry::InitToolBarButton(
				Commands.Run, LOCTEXT("RunButton", "Run"), LOCTEXT("RunTooltip", "Run Blueprint"),
				FSlateIcon(), TEXT("Run"), FName(TEXT("Run"))
			);

			SectionRun.AddEntry(MenuEntry);
		}
	}
}

void FBlueprintToolEditorToolkit::Compile()
{
	UBlueprintData* BlueprintData = GetBlueprintData();
	if (BlueprintData)
	{
		FBTCompilationUtilities::FlushCompilationQueueImpl(BlueprintData);
	}
	
}

void FBlueprintToolEditorToolkit::Help()
{
}

void FBlueprintToolEditorToolkit::Run()
{
	Compile();
	USimpleCodeEvent::BlueprintGameBegins(StaticMeshComponent);
}

void FBlueprintToolEditorToolkit::SaveAsset_Execute()
{
	//const TArray< UObject* >&  Objects = GetEditingObjects();
	Super::SaveAsset_Execute();//Super::SaveAssetAs_Execute();
}

UBlueprintData* FBlueprintToolEditorToolkit::GetBlueprintData() const
{
	auto& EditedObjects = GetEditingObjects();

	return EditedObjects.Num() == 1 ? Cast<UBlueprintData>(EditedObjects[0]) : nullptr;//?
}

// SEditorViewport
TSharedRef<class SDockTab> FBlueprintToolEditorToolkit::SpawnPreviewTab(const FSpawnTabArgs& InTabArgs)
{
	TSharedPtr<SWidget> Viewport = SNullWidget::NullWidget;
	if(MyData)
	{
		PreviewViewport = SNew(SBlueprintViewportClient, StaticMeshComponent).BPEditorPtr(SharedThis(this)).ObjectToEdit(MyData);
		Viewport = PreviewViewport;
	}

	return SNew(SDockTab)
		.Label(LOCTEXT("ViewportMeshComponentPreview", "Preview"))
		.TabColorScale(GetTabColorScale())
		[
			Viewport.ToSharedRef()
		];

}

//SContentBrowser
TSharedRef<class SDockTab> FBlueprintToolEditorToolkit::SpawnContentBrowserTab(const FSpawnTabArgs& InTabArgs)
{
	TSharedPtr<SDockTab> DockTab = SNew(SDockTab)
		.Label(LOCTEXT("ViewportContentBrowser", "ContentBrowser"))
		.TabColorScale(GetTabColorScale())
		[
			SNullWidget::NullWidget
		];

		IContentBrowserSingleton& ContentBrowserSingleton = FModuleManager::LoadModuleChecked<FContentBrowserModule>("ContentBrowser").Get();
		FName ContentBrowserName = *("BP_ContentBrowser_" + FGuid::NewGuid().ToString());
		FContentBrowserConfig ContentBrowserConfig;
		TSharedPtr<SWidget> ContentBrowser = ContentBrowserSingleton.CreateContentBrowser(ContentBrowserName, DockTab, &ContentBrowserConfig);
		DockTab->SetContent(ContentBrowser.ToSharedRef());
	return DockTab.ToSharedRef();
}

//SGraphEditor
TSharedRef<class SDockTab> FBlueprintToolEditorToolkit::SpawnBlueprintGraphTab(const FSpawnTabArgs& InTabArgs)
{
	GraphEditor = CreateBPGrpahEditor(MyData->EdGraph);

	AssetDropTarget = SNew(SObjectEditorDropTarget)
		.OnAssetsDropped(this, &FBlueprintToolEditorToolkit::AssetDropped)
		.OnAreAssetsAcceptableForDrop(this, &FBlueprintToolEditorToolkit::IsAssetAcceptableForDrop);

	TSharedPtr<SDockTab> DockTab = SNew(SDockTab)
		.Label(LOCTEXT("BlueprintGraph", "Blueprint Graph"))
		.TabColorScale(GetTabColorScale())
		[
			SNew(SOverlay)
			+SOverlay::Slot()
			.ZOrder(0)
			[
				GraphEditor.ToSharedRef()
			]
			+ SOverlay::Slot()
			.ZOrder(1)
			[
				AssetDropTarget.ToSharedRef()
			]
		];
	AssetDropTarget->SetVisibility(EVisibility::Collapsed);

	return DockTab.ToSharedRef();
}

//SGraphPalette
TSharedRef<class SDockTab> FBlueprintToolEditorToolkit::SpawnNodeListPaletteTab(const FSpawnTabArgs& InTabArgs)
{

	TSharedPtr<SWidget> Palette = SNullWidget::NullWidget;
	NodeListPalette = SNew(SBlueprintNodeListPalette, SharedThis(this));

	if (NodeListPalette.IsValid())
	{
		Palette = NodeListPalette;
	}

	TSharedPtr<SDockTab> DockTab = SNew(SDockTab)
		.Label(LOCTEXT("NodeListPalette", "Node List Palette"))
		[
			SNew(SOverlay)
				+ SOverlay::Slot()
				[
					Palette.ToSharedRef()
				]
		];

	return DockTab.ToSharedRef();
}

//SDetailsView
TSharedRef<class SDockTab> FBlueprintToolEditorToolkit::SpawnDetailsTab(const FSpawnTabArgs& InTabArgs)
{
	FPropertyEditorModule& PropertyEditorModule = FModuleManager::LoadModuleChecked<FPropertyEditorModule>("PropertyEditor");

	FDetailsViewArgs DetailsViewArgs;
	DetailsViewArgs.bUpdatesFromSelection = false;
	DetailsViewArgs.bLockable = false;
	DetailsViewArgs.bAllowSearch = true;
	DetailsViewArgs.NameAreaSettings = FDetailsViewArgs::ENameAreaSettings::HideNameArea;
	DetailsViewArgs.bHideSelectionTip = true;
	DetailsViewArgs.NotifyHook = this;	//FNotifyHook,当属性被改变时调用


	TSharedRef<IDetailsView> DetailsView = PropertyEditorModule.CreateDetailView(DetailsViewArgs);
	
	PropertyEditor = DetailsView;
	
	return SNew(SDockTab)
		.Label(LOCTEXT("DetailsTab", "Details"))
		[
			DetailsView
		];
}

//SAdvancedPreviewDetailsTab
TSharedRef<class SDockTab> FBlueprintToolEditorToolkit::SpawnPreviewSettingsTab(const FSpawnTabArgs& InTabArgs)
{
	TSharedPtr<FAdvancedPreviewScene> PreviewScene;
	TSharedPtr<SWidget> SettingsView = SNullWidget::NullWidget;

	if (PreviewViewport.IsValid())
	{
		PreviewScene = PreviewViewport->GetPreviewScene();
		TSharedPtr<SAdvancedPreviewDetailsTab> PreviewSettingsView = SNew(SAdvancedPreviewDetailsTab, PreviewScene.ToSharedRef());
		PreviewSettingsView->Refresh(); 
		SettingsView = PreviewSettingsView;
	}

	return SNew(SDockTab)
		.Label(LOCTEXT("PreviewSettingsTitle", "BPToolPreview Settings"))
		[
			SNew(SBox)
			.AddMetaData<FTagMetaData>(FTagMetaData(TEXT("BPTool Preview Settings")))
			[
				SettingsView.ToSharedRef()
			]
		]
	;
}

void FBlueprintToolEditorToolkit::AssetDropped(const FDragDropEvent& DragDropEvent, TArrayView<FAssetData> AssetData)
{

	if (GraphEditor.IsValid() && AssetData.Num())
	{
		UObject* AssetObject = AssetData[0].GetAsset();
		UBPArchitectEdGraph* ThemeGraph = Cast<UBPArchitectEdGraph>(GraphEditor->GetCurrentGraph());
	
		if (ThemeGraph)
		{
			FVector2D GridLocation = GetAssetDropGridLocation();
			ThemeGraph->CreateNewNode(AssetObject, GridLocation);
		}
	}

	AssetDropTarget->SetVisibility(EVisibility::Collapsed);
}

bool FBlueprintToolEditorToolkit::IsAssetAcceptableForDrop(TArrayView<FAssetData> AssetData) const
{
	if (AssetData.Num())
	{	
		UClass* AssetClass = AssetData[0].GetAsset()->GetClass();

		bool bCanDrop = AssetClass->IsChildOf<UStaticMesh>() ||
			AssetClass->IsChildOf<UClass>() ||
			AssetClass->IsChildOf<AActor>() ||
			AssetClass->IsChildOf<UBlueprint>();
		return bCanDrop;
	}
	return false;
}

FVector2D FBlueprintToolEditorToolkit::GetAssetDropGridLocation() const
{
	if (AssetDropTarget.IsValid())
	{
		FVector2D PanelCoordinate = AssetDropTarget->GetPanelCoordinate();
		FVector2D ViewLocation = FVector2D::ZeroVector;
		float ZoomFactor = 1.f;
		GraphEditor->GetViewLocation(ViewLocation, ZoomFactor);
		FVector2D GridLocation = (PanelCoordinate - ViewLocation) / ZoomFactor;
		return GridLocation;
		//return FSlateApplication::Get().GetCursorPos();
	}

	return FVector2D::ZeroVector;
}

void FBlueprintToolEditorToolkit::OnSelectedBPNodesChanged(const TSet<class UObject*>& SelectionNode)
{
	if (SelectionNode.Num() > 0)
	{
		//当选择节点时切换对应的属性面板, 即IDetailsView
		PropertyEditor->SetObjects(SelectionNode.Array());
	}
	else
	{
		PropertyEditor->SetObject(MyData, true);
	}
}

FName FBlueprintToolEditorToolkit::GetToolkitFName() const
{
	return FName("BlueprintToolEditorToolkit");
}

FText FBlueprintToolEditorToolkit::GetBaseToolkitName() const
{
	return LOCTEXT("BlueprintToolLabel","BlueprintTool Editor Toolkit");
}

FString FBlueprintToolEditorToolkit::GetWorldCentricTabPrefix() const
{
	return LOCTEXT("BlueprintToolEditorPrefix", "BlueprintData").ToString();
}

FLinearColor FBlueprintToolEditorToolkit::GetWorldCentricTabColorScale() const
{
	return FLinearColor(0.3f, 0.2f, 0.5f, 0.5f);
}

void FBlueprintToolEditorToolkit::DeleteSelectedNodes()
{
	TArray<UEdGraphNode*> NodesToDelete;
	const FGraphPanelSelectionSet& SelectedNodes = GraphEditor->GetSelectedNodes();

	for (auto& TempObject : SelectedNodes)
	{
		if(UEdGraphNode* NodeObject = Cast<UEdGraphNode>(TempObject))
		{
			NodesToDelete.Add(NodeObject);
		}
	}
	

	if (NodesToDelete.Num() > 0)
	{
		for (auto& TempNode : NodesToDelete)
		{
			TempNode->BreakAllNodeLinks();

	/*		const UEdGraphSchema* Schema = nullptr;

			if (UEdGraph* GraphObject = TempNode->GetGraph())
			{
				GraphObject->Modify();
				Schema = GraphObject->GetSchema();
			}

			TempNode->Modify();

			if (Schema)
			{
				Schema->BreakNodeLinks(*TempNode);
			}*/

			TempNode->DestroyNode();
		}
	}
}

bool FBlueprintToolEditorToolkit::CanDeleteNodes() const
{
	return true;
}

void FBlueprintToolEditorToolkit::CopySelectedNodes()
{
	const FGraphPanelSelectionSet SelectedNodes = GraphEditor->GetSelectedNodes();
	FString ExportedText;
	FEdGraphUtilities::ExportNodesToText(SelectedNodes, ExportedText);
	FPlatformApplicationMisc::ClipboardCopy(*ExportedText);
}

bool FBlueprintToolEditorToolkit::CanCopyNodes() const
{
	return true;
}

void FBlueprintToolEditorToolkit::PasteNodes()
{
	const FScopedTransaction Transaction(LOCTEXT("BPToolNodesPaste","Pasting"));
	GraphEditor->ClearSelectionSet();
	
	GraphEditor->GetCurrentGraph()->Modify();

	FString TextToImport;
	FPlatformApplicationMisc::ClipboardPaste(TextToImport);

	TSet<UEdGraphNode*> PastedNodes;
	FEdGraphUtilities::ImportNodesFromText(GraphEditor->GetCurrentGraph(), TextToImport, PastedNodes);
	
	if (PastedNodes.Num() > 0)
	{
		FVector2D AvgNodePosition(0.f, 0.f);

		for (auto& TempNode : PastedNodes)
		{
			AvgNodePosition.X += TempNode->NodePosX;
			AvgNodePosition.Y += TempNode->NodePosY;
		}

		float AvgNumNodes = 1.f/ float(PastedNodes.Num());
		AvgNodePosition.X *= AvgNumNodes;
		AvgNodePosition.Y *= AvgNumNodes;


		const FVector2D Location = GraphEditor->GetPasteLocation();
		for (auto& TempNode : PastedNodes)
		{
			GraphEditor->SetNodeSelection(TempNode, true);

			TempNode->NodePosX = (TempNode->NodePosX - AvgNodePosition.X) + Location.X;
			TempNode->NodePosY = (TempNode->NodePosY - AvgNodePosition.Y) + Location.Y;
			TempNode->SnapToGrid(SNodePanel::GetSnapGridSize());

			TempNode->CreateNewGuid();

			for (auto& TempPin : TempNode->Pins)
			{
				TempPin->PinId = FGuid::NewGuid();
			}
		}
		GraphEditor->NotifyGraphChanged();
	}
}

bool FBlueprintToolEditorToolkit::CanPasteNodes() const
{
	FString TextToImport;
	FPlatformApplicationMisc::ClipboardPaste(TextToImport);
	return FEdGraphUtilities::CanImportNodesFromText(GraphEditor->GetCurrentGraph(), TextToImport);
}

void FBlueprintToolEditorToolkit::CutSelectedNodes()
{
	CopySelectedNodes();
	const FGraphPanelSelectionSet OldSelectedNodes = GraphEditor->GetSelectedNodes();
	FGraphPanelSelectionSet RemainingNodes;

	for (auto& TempNode : OldSelectedNodes)
	{
		UEdGraphNode* Node = Cast<UEdGraphNode>(TempNode);
		if (Node && Node->CanDuplicateNode())
		{
			GraphEditor->SetNodeSelection(Node, true);
		}
		else
		{
			RemainingNodes.Add(Node);
		}
	}

	DeleteSelectedNodes();
	GraphEditor->ClearSelectionSet();

	for (auto& TempNode : RemainingNodes)
	{
		if (UEdGraphNode* Node = Cast<UEdGraphNode>(TempNode))
		{
			GraphEditor->SetNodeSelection(Node, true);
		}
	}

}

bool FBlueprintToolEditorToolkit::CanCutNodes() const
{
	return CanCopyNodes() && CanDeleteNodes();
}

void FBlueprintToolEditorToolkit::DuplicateNodes()
{
	CopySelectedNodes();
	PasteNodes();
}

bool FBlueprintToolEditorToolkit::CanDuplicateNodes() const
{
	return CanCopyNodes();
}

void FBlueprintToolEditorToolkit::SelectAllNodes()
{
	GraphEditor->SelectAllNodes();
}

bool FBlueprintToolEditorToolkit::CanSelectAllNodes() const
{
	return GraphEditor.IsValid();
}

void FBlueprintToolEditorToolkit::Undo()
{
	GEditor->UndoTransaction();
	GraphEditor->NotifyGraphChanged();
}

void FBlueprintToolEditorToolkit::Redo()
{
	GEditor->RedoTransaction();
	GraphEditor->NotifyGraphChanged();
}

#pragma optimize("", on)
#undef LOCTEXT_NAMESPACE