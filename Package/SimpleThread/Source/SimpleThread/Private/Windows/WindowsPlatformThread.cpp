
#include "Windows/WindowsPlatformThread.h"


#if PLATFORM_WINDOWS

THIRD_PARTY_INCLUDES_START
#pragma warning(push)
#pragma warning(disable:4005)

#include <d2d1.h>
#include <strsafe.h>
#include <wincodec.h>

#pragma warning(pop)
THIRD_PARTY_INCLUDES_END

#pragma comment(lib, "windowscodecs.lib")

static HANDLE WindowsRawThread = nullptr;

FSimpleDelegate FWindowsPlatformThread::CompletedDelegate{};

FSimpleDelegate FWindowsPlatformThread::RunningDelegate{};

//�̺߳���
uint32 WINAPI StartThread(LPVOID ParamPtr)
{
	FWindowsPlatformThread::RunningDelegate.ExecuteIfBound();
	FWindowsPlatformThread::CompletedDelegate.ExecuteIfBound();

	
	FWindowsPlatformThread::RunningDelegate.Unbind();
	FWindowsPlatformThread::CompletedDelegate.Unbind();
	

	FWindowsPlatformThread::Hide();

	return 0;
}


void FWindowsPlatformThread::Show()
{
	if (!WindowsRawThread)
	{
		DWORD ThreadID = 0;
		WindowsRawThread = CreateThread(
			NULL, 128 * 1024, (LPTHREAD_START_ROUTINE)StartThread,
			NULL, 
			STACK_SIZE_PARAM_IS_A_RESERVATION, //
				//0 ����ִ��
				//CREATE_SUSPENDED �������
			&ThreadID
			);
	}
}

void FWindowsPlatformThread::Hide()
{
	if (WindowsRawThread)
	{
		CloseHandle(WindowsRawThread);
		WindowsRawThread = nullptr;
	}
}

bool FWindowsPlatformThread::IsShown()
{
	return WindowsRawThread != nullptr;
}

#endif