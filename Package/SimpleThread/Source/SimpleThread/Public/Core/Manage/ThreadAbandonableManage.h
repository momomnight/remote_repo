#pragma once

#include "CoreMinimal.h"
#include "Interface/ThreadManageInterface.h"
#include "Core/Manage/ManageBase/ThreadManageBase.h"

// Bind 从UE线程池获取线程,同步执行任务
// Create 从UE线程池获取线程,异步执行任务
class SIMPLETHREAD_API FThreadAbandonableManage :public TThreadTemplate<IAbandonableContainer, void>
{
	static TSharedPtr<FThreadAbandonableManage> ThreadAbandonableManage;
	
	FThreadAbandonableManage();
	FThreadAbandonableManage(const FThreadAbandonableManage&) = delete;
	FThreadAbandonableManage& operator=(const FThreadAbandonableManage&) = delete;

public:
        
	static TSharedRef<FThreadAbandonableManage> Get();
	static void Destroy();
};