#pragma once

#include "CoreMinimal.h"

struct SIMPLETHREAD_API FSimpleThreadHandle : public TSharedFromThis<FSimpleThreadHandle>
{
	
	FSimpleThreadHandle(bool NewHandle = true);

	bool operator==(const FSimpleThreadHandle& OtherHandle)
	{
		return (GuidTypeA ^ OtherHandle.GuidTypeA |
				GuidTypeB ^ OtherHandle.GuidTypeB |
				GuidTypeC ^ OtherHandle.GuidTypeC |
				GuidTypeD ^ OtherHandle.GuidTypeD) == 0;
	}


protected:
	uint64 GuidTypeA;
	uint64 GuidTypeB;
	uint64 GuidTypeC;
	uint64 GuidTypeD;
};

typedef TWeakPtr<FSimpleThreadHandle> FThreadHandle;

enum class EThreadState
{
	ThreadState_Idle,
	ThreadState_Working,
	ThreadState_Error
};