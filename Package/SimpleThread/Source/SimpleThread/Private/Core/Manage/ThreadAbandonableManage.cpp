

#include "Core/Manage/ThreadAbandonableManage.h"


TSharedPtr<FThreadAbandonableManage> FThreadAbandonableManage::ThreadAbandonableManage = nullptr;

FThreadAbandonableManage::FThreadAbandonableManage()
{
}

TSharedRef<FThreadAbandonableManage> FThreadAbandonableManage::Get()
{
    if (!ThreadAbandonableManage.IsValid())
    {
        ThreadAbandonableManage = MakeShareable(new FThreadAbandonableManage());
    }

    return ThreadAbandonableManage.ToSharedRef();
}
void FThreadAbandonableManage::Destroy()
{
    if (ThreadAbandonableManage.IsValid())
    {
        ThreadAbandonableManage.Reset();
    }
}
