#pragma once

#include "CoreMinimal.h"
#include "Async/AsyncWork.h"

struct SIMPLETHREAD_API FSimpleAbandonable : FNonAbandonableTask
{
	FSimpleAbandonable(const FSimpleDelegate& SimpleDelegate);

	void DoWork();

	FORCEINLINE TStatId GetStatId() const
	{
		RETURN_QUICK_DECLARE_CYCLE_STAT(FSimpleAbandonable, STATGROUP_ThreadPoolAsyncTasks);
	}


protected:
	FSimpleDelegate ThreadDelegate;

};