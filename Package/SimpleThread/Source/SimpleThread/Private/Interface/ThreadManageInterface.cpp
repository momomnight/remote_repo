#pragma once

#include "Interface/ThreadManageInterface.h"

DEFINE_LOG_CATEGORY(LogIThreadContainer);
//Proxy
IThreadProxyContainer& IThreadProxyContainer::operator<<(const TSharedPtr<IThreadProxy>& InThreadProxy)
{
	if (InThreadProxy.IsValid())
	{	
		if (!InThreadProxy->IsValid())
		{
			//确保加入容器的FThreadRunnable都是有线程的
			InThreadProxy->CreateSafeThread();		
		}
		SCOPE_MUTEX(Mutex);
		this->Add(InThreadProxy);
	}
	else
	{
		UE_LOG(LogIThreadContainer, Error, TEXT("In IThreadProxyContainer::operator<<(), !InThreadProxy.IsValid()."));
	}
	return *this;
}

FThreadHandle IThreadProxyContainer::operator>>(const FSimpleDelegate& InDelegate)
{
	FThreadHandle ThreadHandle = nullptr;

	{//operatro<<也有锁，防止死锁
		SCOPE_MUTEX(Mutex);
		for (auto& Temp : *this)
		{
			if (Temp->IsSuspend() && !Temp->GetThreadDelegate().IsBound())
			{
				Temp->GetThreadDelegate() = InDelegate;
				ThreadHandle = Temp->GetThreadHandle();
				Temp->WakeupThread();
				break;
			}
		}
	}

	if (!ThreadHandle.IsValid())
	{
		TSharedPtr<IThreadProxy> Temp(new FThreadRunnable(false));
		Temp->GetThreadDelegate() = InDelegate;
		*this << Temp;
		ThreadHandle = Temp->GetThreadHandle();
	}

	return ThreadHandle;
}

FThreadHandle IThreadProxyContainer::operator<<(const FSimpleDelegate& InDelegate)
{
	FThreadHandle ThreadHandle = nullptr;

	{//operatro<<也有锁，防止死锁
		SCOPE_MUTEX(Mutex);
		for (auto& Temp : *this)
		{
			if (Temp->IsSuspend() && !Temp->GetThreadDelegate().IsBound())
			{
				Temp->GetThreadDelegate() = InDelegate;
				ThreadHandle = Temp->GetThreadHandle();
				break;
			}
		}
	}

	if (!ThreadHandle.IsValid())
	{
		TSharedPtr<IThreadProxy> Temp(new FThreadRunnable(true));
		Temp->GetThreadDelegate() = InDelegate;
		*this << Temp ;
		ThreadHandle = Temp->GetThreadHandle();
	}

	return ThreadHandle;
}

TSharedPtr<IThreadProxy> IThreadProxyContainer::operator<<(const FThreadHandle& InThreadHandle)
{
	SCOPE_MUTEX(Mutex);
	for (auto& Temp : *this)
	{
		if (Temp.IsValid() && Temp->GetThreadHandle() == InThreadHandle)
		{
			return Temp;
		}
	}
	return nullptr;
}

//Task
IThreadTaskContainer& IThreadTaskContainer::operator<<(const TSharedPtr<IThreadProxy>& InThreadProxy)
{
	// TODO: insert return statement here
	if (InThreadProxy.IsValid())
	{
		if (!InThreadProxy->IsValid())
		{
			InThreadProxy->CreateSafeThread();
		}
		SCOPE_MUTEX(Mutex);
		this->Add(InThreadProxy);
	}
	else
	{
		UE_LOG(LogIThreadContainer, Error, TEXT("In IThreadTaskContainer::operator<<(), !InThreadProxy.IsValid()."));
	}
	return *this;
}

IThreadTaskContainer::IThreadTaskContainer() : IThreadContainer()
{
}

IThreadTaskContainer& IThreadTaskContainer::operator<<(const FSimpleDelegate& InDelegate)
{
	SCOPE_MUTEX(Mutex);
	this->Enqueue(InDelegate);
	return *this;
}

bool IThreadTaskContainer::operator>>=(FSimpleDelegate& InDelegate)
{
	SCOPE_MUTEX(Mutex);
	return this->Dequeue(InDelegate);
}



IThreadTaskContainer& IThreadTaskContainer::operator>>(const FSimpleDelegate& InDelegate)
{
	// TODO: insert return statement here
	bool bSuccessful = false;

	{//operatro<<也有锁，防止死锁
		SCOPE_MUTEX(Mutex);
		for (auto& Temp : *this)
		{
			if (Temp->IsSuspend() && !Temp->GetThreadDelegate().IsBound())
			{
				Temp->GetThreadDelegate() = InDelegate;
				Temp->WakeupThread();
				bSuccessful = true;
				break;
			}
		}
	}

	if (!bSuccessful)
	{
		*this << InDelegate;
	}
	return *this;
}


//Abandonable
IAbandonableContainer& IAbandonableContainer::operator<<(const FSimpleDelegate& SimpleDelegate)
{
	FAsyncTask<FSimpleAbandonable>* SimpleAbandonable = new FAsyncTask<FSimpleAbandonable>(SimpleDelegate);
	SimpleAbandonable->StartBackgroundTask();
	SimpleAbandonable->EnsureCompletion();
	delete SimpleAbandonable;
	return *this;
}

IAbandonableContainer& IAbandonableContainer::operator>>(const FSimpleDelegate& SimpleDelegate)
{
	(new FAutoDeleteAsyncTask<FSimpleAbandonable>(SimpleDelegate))->StartBackgroundTask();
	return *this;
}



ICoroutinesContainer& ICoroutinesContainer::operator<<(float InTotalTime)
{
	TempTotalTime = InTotalTime;
	return *this;
}

ICoroutinesContainer& ICoroutinesContainer::operator<<(FSimpleDelegate InSimpleDelegate)
{
	ICoroutineObject::Array.Add(MakeShareable(new FCoroutineObject(InSimpleDelegate, TempTotalTime)));
	return *this;
}

FCoroutineHandle ICoroutinesContainer::operator>>(FSimpleDelegate InSimpleDelegate)
{
	ICoroutineObject::Array.Add(MakeShareable(new FCoroutineObject(InSimpleDelegate)));
	return ICoroutineObject::Array[ICoroutineObject::Array.Num() - 1];
}

void ICoroutinesContainer::operator<<=(float InDeltaTime)
{
	//TArray<TSharedPtr<ICoroutineObject>> RemoveObject;
	for (auto& Temp : ICoroutineObject::Array)
	{
		if(Temp.IsValid())
		{
			FCoroutineRequest Request(InDeltaTime);
			Temp->Update(Request);
			if (Request.bCompleteRequest)
			{
				Temp.Reset();
			}
		}
		else
		{
			UE_LOG(LogIThreadContainer, Error, TEXT("In ICoroutinesContainer::operator<<=(), !Temp.IsValid()."));
		}
	}

	auto RemoveOp = [](const TSharedPtr<ICoroutineObject>& InSharedPtr)->bool
		{
			if (InSharedPtr.IsValid())
			{
				return false;
			}
			else
			{
				return true;
			}
		};

	ICoroutineObject::Array.RemoveAllSwap(RemoveOp, false);
}

FGraphEventRef IThreadGraphContainer::operator<<(const FSimpleDelegate& InSimpleDelegate)
{
	return FSimpleDelegateGraphTask::CreateAndDispatchWhenReady(
		InSimpleDelegate, TStatId(), nullptr, ENamedThreads::GameThread
	);
}

//呼叫其他线程
FGraphEventRef IThreadGraphContainer::operator>>(const FSimpleDelegate& InSimpleDelegate)
{
	return FSimpleDelegateGraphTask::CreateAndDispatchWhenReady(
		InSimpleDelegate, TStatId(), nullptr, ENamedThreads::AnyThread
	);
}


//异步加载
	//存储路径
IStreamableContainer& IStreamableContainer::operator>>(const TArray<FSoftObjectPath>& InObjectPath)
{
	this->SetObjectPath(InObjectPath);
	return *this;
}

IStreamableContainer& IStreamableContainer::operator>>(const FSoftObjectPath& InObjectPath)
{
	// TODO: insert return statement here
	this->SetObjectPath(InObjectPath);
	return *this;
}

	//加载
TSharedPtr<struct FStreamableHandle> IStreamableContainer::operator>>(const FSimpleDelegate& InSimpleDelegate)
{
	return this->GetStreamableManager()->RequestAsyncLoad(this->GetObjectPath(), InSimpleDelegate);
}

//同步加载
TSharedPtr<struct FStreamableHandle> IStreamableContainer::operator<<(const TArray<FSoftObjectPath>& InObjectPath)
{
	return this->GetStreamableManager()->RequestSyncLoad(InObjectPath);
}

TSharedPtr<struct FStreamableHandle> IStreamableContainer::operator<<(const FSoftObjectPath& InObjectPath)
{
	return this->GetStreamableManager()->RequestSyncLoad(InObjectPath);
}
