#pragma once

#include "CoreMinimal.h"
#include "HAL/Runnable.h"
#include "Core/SimpleSemaphore.h"
#include "Interface/ProxyInterface.h"
#include "HAL/RunnableThread.h"


DECLARE_LOG_CATEGORY_EXTERN(LogFThreadRunnable, Log, All);

class FSimpleSemaphore;
class FRunnableThread;

class SIMPLETHREAD_API FThreadRunnable : public FRunnable, public IThreadProxy
{
public:
	FThreadRunnable(bool bNeedSuspend = true);
	virtual ~FThreadRunnable() override;
	virtual void CreateSafeThread() override;
	virtual void WakeupThread() override;
	virtual bool IsSuspend() override;
	virtual void WaitAndCompleted() override;
	virtual void BlockingAndCompletion() override;
	virtual bool IsValid() override;

private:
	virtual bool Init();
	virtual uint32 Run();
	virtual void Stop();
	virtual void Exit();

private:
	FThreadSafeCounter StopTaskCounter;
	bool bSuspendAtTheBegining;

	//�����ж��߳��Ƿ��˳�
	bool bSyncExit;

	//�����ж��Ƿ���ͬ���ȴ��߳��������״̬
	std::atomic_bool bBlockingAndCompletion;
	//���ڹ����̺߳ͱ������߳�ֱ�ӵ�ͬ��
	FSimpleSemaphore SyncMainAndManagedEvent;
	//�����̵߳Ĺ���
	FSimpleSemaphore ThreadEvent;

	FRunnableThread* Thread;
	FName RunnableName;
	
	static int32 ThreadCount;
};

 