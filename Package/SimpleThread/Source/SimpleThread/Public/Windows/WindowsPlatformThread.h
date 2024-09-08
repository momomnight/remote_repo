#pragma once


#include "CoreTypes.h"

#if PLATFORM_WINDOWS

struct SIMPLETHREAD_API FWindowsPlatformThread
{
	static void Show();
	static void Hide();
	static bool IsShown();

	static FSimpleDelegate CompletedDelegate;

	static FSimpleDelegate RunningDelegate;


};

#endif