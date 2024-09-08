
#include "Core/Manage/ThreadProxyManage.h"

DEFINE_LOG_CATEGORY(LogThreadProxyManage);

TSharedPtr<FThreadProxyManage> FThreadProxyManage::ThreadProxyManage = nullptr;

FThreadProxyManage::FThreadProxyManage()
{

}

TSharedRef<FThreadProxyManage> FThreadProxyManage::Get()
{
    if (!ThreadProxyManage.IsValid())
    {
        ThreadProxyManage = MakeShareable(new FThreadProxyManage());
    }

    return ThreadProxyManage.ToSharedRef();
}

void FThreadProxyManage::Destroy()
{
    if (ThreadProxyManage.IsValid())
    {
        ThreadProxyManage.Reset();
    }
}
FThreadProxyManage::~FThreadProxyManage()
{
    for (auto& Temp : *this)
    {
        Temp->WaitAndCompleted();
    }
    this->Empty();
}

bool FThreadProxyManage::Join(FThreadHandle Handle)
{
    TSharedPtr<IThreadProxy> ThreadProxy = ((*this) << Handle);

    if (ThreadProxy.IsValid() && ThreadProxy->IsValid())
    {
        ThreadProxy->BlockingAndCompletion();
        return true;
    }
    else
    {
        UE_LOG(LogThreadProxyManage, Error, TEXT("In FThreadProxyManage::Join(), !ThreadProxy.IsValid() or !ThreadProxy->IsValid()"));
    }
    return false;
}

bool FThreadProxyManage::Detach(FThreadHandle Handle)
{
    TSharedPtr<IThreadProxy> ThreadProxy = ((*this) << Handle);

    if (ThreadProxy.IsValid() && ThreadProxy->IsValid())
    {
        ThreadProxy->WakeupThread();
        return true;
    }
    else
    {
        UE_LOG(LogThreadProxyManage, Error, TEXT("In FThreadProxyManage::Detach(), !ThreadProxy.IsValid() or !ThreadProxy->IsValid()"));
    }
    return false;
}

EThreadState FThreadProxyManage::Joinable(FThreadHandle Handle)
{
    TSharedPtr<IThreadProxy> ThreadProxy = ((*this) << Handle);

    if (ThreadProxy.IsValid() && ThreadProxy->IsValid())
    {
        if (ThreadProxy->IsSuspend())
        {
            return EThreadState::ThreadState_Idle;
        }
        else
        {
            return EThreadState::ThreadState_Working;
        }
    }

    return EThreadState::ThreadState_Error;
}
