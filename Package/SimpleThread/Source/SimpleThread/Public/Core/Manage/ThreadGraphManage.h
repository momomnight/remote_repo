#pragma once


#include "CoreMinimal.h"
#include "Core/Manage/ManageBase/ThreadManageBase.h"
#include "Interface/ThreadManageInterface.h"
#include "Async/TaskGraphInterfaces.h"

struct SIMPLETHREAD_API FThreadGraphManage :public TThreadTemplate<IThreadGraphContainer, FGraphEventRef>
{
private:
	static TSharedPtr<FThreadGraphManage> ThreadGraphManage;
	FThreadGraphManage();
	FThreadGraphManage(const FThreadGraphManage&) = delete;
	FThreadGraphManage& operator=(const FThreadGraphManage&) = delete;

public:


	static void Wait(const FGraphEventRef& InGraphEventRef);
	static void Wait(const FGraphEventArray& InGraphEventArray);
	static TSharedRef<FThreadGraphManage> Get();
	static void Destroy();
};