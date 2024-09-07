#pragma once

#include "CoreMinimal.h"
#include "Interface/ThreadManageInterface.h"
#include "Core/Manage/ManageBase/ThreadManageBase.h"

DECLARE_LOG_CATEGORY_EXTERN(LogThreadProxyManage, Log, All);

// Bind 寻找挂起线程, 绑定任务, 如无挂起线程则创建线程, 不执行直接执行任务
//		通过Join()和Detach()执行
// Create 寻找挂起线程, 绑定任务, 如无挂起线程则创建线程, 并执行任务
class SIMPLETHREAD_API FThreadProxyManage :public TThreadTemplate<IThreadProxyContainer, FThreadHandle>
{
public:
	static TSharedRef<FThreadProxyManage> Get();
	static void Destroy();

private:
	static TSharedPtr<FThreadProxyManage> ThreadProxyManage;

	FThreadProxyManage();
	FThreadProxyManage(const FThreadProxyManage&) = delete;
	FThreadProxyManage& operator=(const FThreadProxyManage&) = delete;

public:
	~FThreadProxyManage();

	//同步
	bool Join(FThreadHandle Handle);

	//异步
	bool Detach(FThreadHandle Handle);

	EThreadState Joinable(FThreadHandle Handle);
};