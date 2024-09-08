#pragma once

#include "Runnable/ThreadRunnableProxy.h"
#include "Core/ThreadCoreMacro.h"
#include "SimpleThreadPlatform.h"

DEFINE_LOG_CATEGORY(LogFThreadRunnable);

int32 FThreadRunnable::ThreadCount = 0;

FThreadRunnable::FThreadRunnable(bool bNeedSuspend): IThreadProxy(),bSuspendAtTheBegining(bNeedSuspend),
	bSyncExit(false),Thread(nullptr), bBlockingAndCompletion(false)
{

}

FThreadRunnable::~FThreadRunnable()
{
	if (Thread)
	{
		delete Thread;
		Thread = nullptr;
	}

}

void FThreadRunnable::CreateSafeThread()
{
	RunnableName = *FString::Printf(TEXT("SimpleThread-%i"), ThreadCount);
	Thread = FRunnableThread::Create(this, *RunnableName.ToString(), 0, EThreadPriority::TPri_BelowNormal);
	if (!Thread)
	{
		UE_LOG(LogFThreadRunnable, Error, TEXT("Failure to create FRunnableThread"));
	}
	ThreadCount++;
}

void FThreadRunnable::WakeupThread()
{
	ThreadEvent.Trigger();
}

bool FThreadRunnable::IsSuspend()
{
	return ThreadEvent.IsWait();
}

void FThreadRunnable::WaitAndCompleted()
{
	Stop();

	for (int32 i = 0; i < WAIT_TIMES && bSyncExit == false; i++)
	{
		ThreadEvent.Trigger();
		FPlatformProcess::Sleep(WAIT_TIME_PER_TIME);
	}

	if (!bSyncExit)
	{
		UE_LOG(LogFThreadRunnable, Error, TEXT("Out of time, managed thread is failure to exit."));
	}
}

void FThreadRunnable::BlockingAndCompletion()
{
	if (IsSuspend())
	{
		bBlockingAndCompletion.exchange(true);
		WakeupThread();
		SyncMainAndManagedEvent.Wait();
		bBlockingAndCompletion.exchange(false);
	}
}

bool FThreadRunnable::IsValid()
{
	return Thread != nullptr;
}

bool FThreadRunnable::Init()
{
	if (!FPlatformProcess::SupportsMultithreading())
	{
		UE_LOG(LogFThreadRunnable, Error, TEXT("Not Supports Multithreading!"));
		Stop();
	}
	return StopTaskCounter.GetValue() == 0;
}

uint32 FThreadRunnable::Run()
{
	//线程刚开始时是否需要挂起
	if (!bSuspendAtTheBegining)
	{
		if (ThreadDelegate.IsBound())
		{
			ThreadDelegate.Execute();
			ThreadDelegate.Unbind();
		}
	}

	bSuspendAtTheBegining = true;

	while (StopTaskCounter.GetValue() == 0)
	{	
		ThreadEvent.Wait();


		if (ThreadDelegate.IsBound())
		{
			ThreadDelegate.Execute();
			ThreadDelegate.Unbind();
		}
		
		//是否处于同步等待状态
		if(bBlockingAndCompletion)
		{
			//防止死锁
			while (!SyncMainAndManagedEvent.IsWait())
			{
				std::this_thread::yield();
			}
			SyncMainAndManagedEvent.Trigger();
		}	
	}
	Exit();
	return 0;
}

void FThreadRunnable::Stop()
{
	StopTaskCounter.Increment();
}

void FThreadRunnable::Exit()
{
	bSyncExit = true;
}




 