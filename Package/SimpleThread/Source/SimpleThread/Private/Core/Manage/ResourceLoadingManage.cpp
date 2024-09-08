
#include "Core/Manage/ResourceLoadingManage.h"

TSharedPtr<FResourceLoadingManage> FResourceLoadingManage::ResourceLoadingManage = nullptr;

FResourceLoadingManage::FResourceLoadingManage()
	:StreamableManager(new FStreamableManager())
{
}

FResourceLoadingManage::~FResourceLoadingManage()
{
	if (StreamableManager != nullptr)
	{
		delete StreamableManager;
	}
	Empty();
}

TSharedRef<FResourceLoadingManage> FResourceLoadingManage::Get()
{
	if (!ResourceLoadingManage.IsValid())
	{
		ResourceLoadingManage = MakeShareable(new FResourceLoadingManage());
	}

	return ResourceLoadingManage.ToSharedRef();
}

void FResourceLoadingManage::Empty()
{
	SoftObjectPath.Empty();
}

void FResourceLoadingManage::Destroy()
{
	if (ResourceLoadingManage.IsValid())
	{
		ResourceLoadingManage.Reset();
	}
}
void FResourceLoadingManage::SetObjectPath(const TArray<FSoftObjectPath>& InObjectPath)
{
	if (InObjectPath.IsEmpty())
	{
		return;
	}
	SoftObjectPath += InObjectPath;
}

void FResourceLoadingManage::SetObjectPath(const FSoftObjectPath& InObjectPath)
{
	if (InObjectPath.IsNull())
	{
		return;
	}
	SoftObjectPath.Add(InObjectPath);
}

TArray<FSoftObjectPath>& FResourceLoadingManage::GetObjectPath()
{
	// TODO: insert return statement here
	return SoftObjectPath;
}

FStreamableManager* FResourceLoadingManage::GetStreamableManager()
{
	return StreamableManager;
}
