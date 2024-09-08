
#include "Core/Manage/ThreadGraphManage.h"

TSharedPtr<FThreadGraphManage> FThreadGraphManage::ThreadGraphManage = nullptr;

TSharedRef<FThreadGraphManage> FThreadGraphManage::Get()
{
    if (!ThreadGraphManage.IsValid())
    {
        ThreadGraphManage = MakeShareable(new FThreadGraphManage());
    }

    return ThreadGraphManage.ToSharedRef();
}
void FThreadGraphManage::Destroy()
{
    if (ThreadGraphManage.IsValid())
    {
        ThreadGraphManage.Reset();
    }
}


FThreadGraphManage::FThreadGraphManage()
{
}

void FThreadGraphManage::Wait(const FGraphEventRef& InGraphEventRef)
{
	FTaskGraphInterface::Get().WaitUntilTaskCompletes(InGraphEventRef);
}

void FThreadGraphManage::Wait(const FGraphEventArray& InGraphEventArray)
{
	FTaskGraphInterface::Get().WaitUntilTasksComplete(InGraphEventArray);
}

