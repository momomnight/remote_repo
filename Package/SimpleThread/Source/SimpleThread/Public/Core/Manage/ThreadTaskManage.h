#pragma once

#include "CoreMinimal.h"
#include "Interface/ThreadManageInterface.h"
#include "Core/Manage/ManageBase/ThreadManageBase.h"




//Bind 添加任务到队列, 由外部Tick
//Create 寻找线程池里的线程, 执行任务, 如无挂起线程, 则添加到队列
class SIMPLETHREAD_API FThreadTaskManage 
	: public TThreadTemplate<IThreadTaskContainer, IThreadTaskContainer&>
{
	//FThreadTaskManage线程数固定
	void Initialize(int32 ThreadNumber);

private:
	static TSharedPtr<FThreadTaskManage> ThreadTaskManage;

	FThreadTaskManage();
	FThreadTaskManage(const FThreadTaskManage&) = delete;
	FThreadTaskManage& operator=(const FThreadTaskManage&) = delete;

public:
	using Super = TThreadTemplate<IThreadTaskContainer, IThreadTaskContainer&>;

	static TSharedRef<FThreadTaskManage> Get();
	static void Destroy();
	
	~FThreadTaskManage();

	//会多线程访问
	void Tick(float DeltaTime);
};