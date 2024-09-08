#pragma once

#include "CoreMinimal.h"
#include "AssetThumbnail.h"

class FObjectEdiotrThumbnailPool : public FAssetThumbnailPool
{
public:

	FObjectEdiotrThumbnailPool(int Number) : FAssetThumbnailPool(Number){}

	static TSharedPtr<FObjectEdiotrThumbnailPool> Get() { return Instance; }

	static void Create()
	{
		Instance = MakeShareable(new FObjectEdiotrThumbnailPool(512));
	}

private:

	static TSharedPtr<FObjectEdiotrThumbnailPool> Instance;

};