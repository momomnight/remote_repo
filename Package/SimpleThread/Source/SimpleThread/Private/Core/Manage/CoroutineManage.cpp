

#include "Core/Manage/CoroutineManage.h"

TSharedPtr<FCoRoutinesManage> FCoRoutinesManage::CoRoutinesManage = nullptr;

TSharedRef<FCoRoutinesManage> FCoRoutinesManage::Get()
{
	if (!CoRoutinesManage.IsValid())
	{
		CoRoutinesManage = MakeShareable(new FCoRoutinesManage());
	}

	return CoRoutinesManage.ToSharedRef();
}

void FCoRoutinesManage::Destroy()
{
	if (CoRoutinesManage.IsValid())
	{
		CoRoutinesManage.Reset();
	}
}

FCoRoutinesManage::FCoRoutinesManage()
	:TThreadTemplateBase<ICoroutinesContainer, FCoroutineHandle>()
{
}

void FCoRoutinesManage::Tick(float DeltaTime)
{
	*this <<= DeltaTime;	
}
