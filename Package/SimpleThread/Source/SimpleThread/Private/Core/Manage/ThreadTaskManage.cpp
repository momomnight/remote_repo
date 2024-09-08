
#include "Core/Manage/ThreadTaskManage.h"

TSharedPtr<FThreadTaskManage> FThreadTaskManage::ThreadTaskManage = nullptr;

TSharedRef<FThreadTaskManage> FThreadTaskManage::Get()
{
    if (!ThreadTaskManage.IsValid())
    {
        ThreadTaskManage = MakeShareable(new FThreadTaskManage());
    }

    return ThreadTaskManage.ToSharedRef();
}

void FThreadTaskManage::Destroy()
{
    if (ThreadTaskManage.IsValid())
    {
        ThreadTaskManage.Reset();
    }
}

FThreadTaskManage::FThreadTaskManage() : Super()
{
    Initialize(CPU_THREAD_NUMBER);
}

FThreadTaskManage::~FThreadTaskManage()
{
    for (auto& Temp : *this)
    {
        if(Temp.IsValid() && Temp->IsValid())
        {
            Temp->WaitAndCompleted();
        }
    }
}

void FThreadTaskManage::Initialize(int32 ThreadNumber)
{
    for (int32 i = 0; i < ThreadNumber; i++)
    {
        TSharedPtr<IThreadProxy> ThreadProxy = MakeShareable(new FThreadRunnable);
        ThreadProxy->CreateSafeThread();
        *this << ThreadProxy;
    }
}

void FThreadTaskManage::Tick(float DeltaTime)
{
    TSharedPtr<IThreadProxy> ThreadProxy = nullptr;
    {
        SCOPE_MUTEX(Mutex);

        for (auto& Temp : *this)
        {
            if (Temp->IsSuspend() && !Temp->GetThreadDelegate().IsBound())
            {
                ThreadProxy = Temp;
                break;
            }
        }

    }
    if (ThreadProxy.IsValid() && ThreadProxy->IsValid())
    {
        if (!((TTaskQueue*)this)->IsEmpty())
        {
            FSimpleDelegate SimpleDelegate;
            if (*this >>= SimpleDelegate)
            {
                SCOPE_MUTEX(Mutex);
                ThreadProxy->GetThreadDelegate() = SimpleDelegate;
                ThreadProxy->WakeupThread();
            }
        }
    }
}

