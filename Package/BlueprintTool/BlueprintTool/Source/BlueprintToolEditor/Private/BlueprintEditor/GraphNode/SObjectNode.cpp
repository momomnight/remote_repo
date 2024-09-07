#include "BlueprintEditor/GraphNode/SObjectNode.h"
#include "BlueprintEditor\GraphNode\ObjectNode.h"
#include "BlueprintEditor/GraphNode/CAssetThumbnailPool.h"

#pragma optimize("", off)

void SObjectNode::Construct(const FArguments& InArgs, UK3Node* MarkerNode)
{
	ThumbnailSize = FIntPoint(512, 512);
	GraphNode = MarkerNode;

	UObjectNode* ObjectNode = Cast<UObjectNode>(GraphNode);
	if (ObjectNode)
	{
		ObjectNode->Update.BindSP(this, &SObjectNode::UpdataObjectThumbnailWidget);
	}

	SetCursor(EMouseCursor::GrabHand);
	BuildThumbnail();
	UpdateGraphNode();
}

void SObjectNode::UpdateGraphNode()
{
	InputPins.Empty();
	OutputPins.Empty();

	LeftNodeBox.Reset();
	RightNodeBox.Reset();

	const FSlateBrush* MyNodeIcon = FAppStyle::GetBrush(TEXT("Graph.StateNode.Icon"));

	this->GetOrAddSlot(ENodeZone::Center)
		.HAlign(HAlign_Fill)
		.VAlign(VAlign_Fill)
		[
			SAssignNew(RightNodeBox, SVerticalBox)
			+ SVerticalBox::Slot()
			.Padding(10.f)
			[
				SNew(SBox)
				.HeightOverride(64.f)
				.WidthOverride(64.f)
				[
					AssetThumbnail->MakeThumbnailWidget()
				]
			]
		];
	CreatePinWidgets();
}

void SObjectNode::SetThumbnail(UObject* AssetOject)
{
	AssetThumbnail->SetAsset(FAssetData(AssetOject));
}

void SObjectNode::BuildThumbnail()
{
	FObjectAssetData Value;
	GetValue(Value);
	AssetThumbnail = MakeShareable(new FAssetThumbnail(Value.AssetData, ThumbnailSize.X, ThumbnailSize.Y, FObjectEdiotrThumbnailPool::Get()));
}

void SObjectNode::UpdataObjectThumbnailWidget()
{
	UObjectNode* ObjectNode = Cast<UObjectNode>(GraphNode);
	if(ObjectNode)
	{
		SetThumbnail(ObjectNode->Value);
	}
}

bool SObjectNode::GetValue(FObjectAssetData& OutValue) const
{
	if(GIsSavingPackage || IsGarbageCollecting())
	{
		return false;
	}

	UObjectNode* ObjectNode = Cast<UObjectNode>(GraphNode);
	if (ObjectNode)
	{
		OutValue = FObjectAssetData(ObjectNode->Value);

		return ObjectNode->Value != nullptr;
	}
	else
	{
		return false;
	}

}


#pragma optimize("", on)