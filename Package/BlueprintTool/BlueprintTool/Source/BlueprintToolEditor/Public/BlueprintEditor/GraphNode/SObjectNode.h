#pragma once

#include "CoreMinimal.h"
#include "BlueprintEditor/Core/Architect/K3Node.h"
#include "SGraphNode.h"

class SObjectNode : public SGraphNode
{

public:
	SLATE_BEGIN_ARGS(SObjectNode){}

	SLATE_END_ARGS()


	struct FObjectAssetData
	{
		UObject* Object;
		FAssetData AssetData;
		FObjectAssetData(UObject* InObj = nullptr) : Object(InObj)
		{
			AssetData = (InObj != nullptr && !InObj->IsA<AActor>()) ? FAssetData(InObj) : FAssetData();
		}
		FObjectAssetData(const FAssetData& InAssetData) : Object(nullptr), AssetData(InAssetData)
		{
			if (AssetData.IsValid())
			{
				Object = AssetData.GetAsset();
			}
		}

		bool IsValid() const
		{
			return Object != nullptr || AssetData.IsValid();
		}
	};

	void Construct(const FArguments& InArgs, UK3Node* MarkerNode);

	virtual void UpdateGraphNode() override;

	void SetThumbnail(UObject* AssetOject);
	void BuildThumbnail();
	void UpdataObjectThumbnailWidget();
	bool GetValue(struct FObjectAssetData& OutValue) const;

private:
	FIntPoint ThumbnailSize;
	TSharedPtr<class FAssetThumbnail> AssetThumbnail;

};