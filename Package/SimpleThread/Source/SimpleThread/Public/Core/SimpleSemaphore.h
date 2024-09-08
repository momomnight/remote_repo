#pragma once

#include "CoreMinimal.h"


class FEvent;

class FSimpleSemaphore
{
public:
	FSimpleSemaphore();
	~FSimpleSemaphore();


	FORCEINLINE bool IsWait(){return bWait;}

	void Wait();
	void Wait(uint32 WaitTime, const bool bIgnoreThreadIdleStats = false);
	void Trigger();

private:

	FEvent* Event;
	std::atomic_bool bWait;
};
