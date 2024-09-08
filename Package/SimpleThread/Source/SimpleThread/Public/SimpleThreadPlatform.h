#pragma once

#include "GenericPlatform/GenericPlatformProcess.h"

#if	PLATFORM_WINDOWS
#include "Windows/WindowsPlatformProcess.h"
#elif PLATFORM_LINUX
#include "Linux/LinuxPlatformProcess.h"
#elif PLATFORM_MAC
#include "Mac/MacPlatformProcess.h"
#endif