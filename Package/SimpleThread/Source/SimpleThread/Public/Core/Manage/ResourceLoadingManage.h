#pragma once

#include "CoreMinimal.h"
#include "Interface/ThreadManageInterface.h"
#include "Core/Manage/ManageBase/ThreadManageBase.h"

//TArray<FSoftObjectPath> ObjectPath;
//TSharedPtr<FStreamableHandle> Handle;
//
//auto Lambda = [&Handle]()
//	{
//		TArray<UObject*> ExampleObject;
//		Handle->GetLoadedAssets(ExampleObject);
//	};
//
////Òì²½
//Handle = GThread::GetResourecLoadingManage() >> ObjectPath >> FSimpleDelegate::CreateLambda(Lambda);
//
//////////////////////////////////////////////////////////////////////////
////Í¬²½
//Handle = GThread::GetResourecLoadingManage() << ObjectPath;
//Lambda();
struct SIMPLETHREAD_API FResourceLoadingManage : IStreamableContainer
{

	virtual ~FResourceLoadingManage();
	static TSharedRef<FResourceLoadingManage> Get();
	static void Destroy();
	void Empty();

protected:
	virtual void SetObjectPath(const TArray<FSoftObjectPath>& InObjectPath) override final;
	virtual void SetObjectPath(const FSoftObjectPath& InObjectPath)override final;
	virtual TArray<FSoftObjectPath>& GetObjectPath()override final;
	virtual struct FStreamableManager* GetStreamableManager()override final;

private:
	TArray<FSoftObjectPath> SoftObjectPath;
	FStreamableManager* StreamableManager;

	static TSharedPtr<FResourceLoadingManage> ResourceLoadingManage;

	FResourceLoadingManage();
	FResourceLoadingManage(const FResourceLoadingManage&) = delete;
	FResourceLoadingManage& operator=(const FResourceLoadingManage&) = delete;

};