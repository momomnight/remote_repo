#pragma once

#include "CoreMinimal.h"
#include "Containers/Queue.h"
#include "Core/ThreadCoreMacro.h"
#include "Coroutine/SimpleCoroutine.h"
#include "Engine/StreamableManager.h"
#include "Runnable/ThreadRunnableProxy.h"

DECLARE_LOG_CATEGORY_EXTERN(LogIThreadContainer, Log, All)

class SIMPLETHREAD_API IThreadContainer
{
public:
	IThreadContainer(){}
	virtual ~IThreadContainer() {}
protected:
	FCriticalSection Mutex;
};


/// <summary>
/// �������ɴ����߳�, ִ�����̻߳�����̳߳�
/// ����ͬ�����첽���ܣ�һ������С����
/// </summary>
class IThreadProxyContainer : public TArray<TSharedPtr<IThreadProxy>>, public IThreadContainer
{
	
protected:
	typedef TArray<TSharedPtr<IThreadProxy>> TProxyArray;

public:

	/// <summary>
	/// ��FThreadRunnable��������, �����Ƿ����������̶߳�����Ӧ��
	/// </summary>
	/// <param name="InThreadProxy"></param>
	/// <returns> FThreadHandle </returns>
	SIMPLETHREAD_API IThreadProxyContainer& operator<<(const TSharedPtr<IThreadProxy>& InThreadProxy);


	/// <summary>
	/// �󶨲�ִ��
	/// </summary>
	/// <param name="InDelegate"></param>
	/// <returns> FThreadHandle </returns>
	SIMPLETHREAD_API FThreadHandle operator>>(const FSimpleDelegate& InDelegate);

	/// <summary>
	/// �󶨲�ִ��
	/// </summary>
	/// <param name="InDelegate"></param>
	/// <returns> FThreadHandle </returns>
	SIMPLETHREAD_API FThreadHandle operator<<(const FSimpleDelegate& InDelegate);

	/// <summary>
	/// ��ѯThreadHandle������FThreadRunnableָ���ЧTSharedPtr<IThreadProxy>
	/// </summary>
	/// <param name="InThreadHandle"></param>
	/// <returns> TSharedPtr<IThreadProxy> </returns>
	SIMPLETHREAD_API TSharedPtr<IThreadProxy> operator<<(const FThreadHandle& InThreadHandle);

};


/// <summary>
/// �̵߳�������������Զ����������Զ����������߳�
/// </summary>
class IThreadTaskContainer : public TQueue<FSimpleDelegate>, public TArray<TSharedPtr<IThreadProxy>>, public IThreadContainer
{

protected:
	typedef TArray<TSharedPtr<IThreadProxy>> TProxyArray;
	typedef TQueue<FSimpleDelegate> TTaskQueue;
public:
	IThreadTaskContainer();

	/// <summary>
	/// ����������
	/// </summary>
	/// <param name="InDelegate"></param>
	/// <returns> bool </returns>
	SIMPLETHREAD_API IThreadTaskContainer& operator<<(const FSimpleDelegate& InDelegate);
	
	/// <summary>
	/// 
	/// </summary>
	/// <param name="InDelegate"></param>
	SIMPLETHREAD_API IThreadTaskContainer& operator>>(const FSimpleDelegate& InDelegate);
	
	/// <summary>
	/// �����Ƴ�����;
	/// </summary>
	/// <param name="InDelegate"></param>
	/// <returns> IThreadTaskContainer& </returns>
	SIMPLETHREAD_API bool operator>>=(FSimpleDelegate& InDelegate);

	/// <summary>
	/// ����߳�
	/// </summary>
	/// <param name="InThreadProxy"></param>
	/// <returns> IThreadTaskContainer& </returns>
	SIMPLETHREAD_API IThreadTaskContainer& operator<<(const TSharedPtr<IThreadProxy>& InThreadProxy);

};

/// <summary>
/// ʹ��UE�̳߳�
/// </summary>
class IAbandonableContainer : public IThreadContainer
{

public:
	/// <summary>
	/// ͬ����
	/// </summary>
	/// <param name="SimpleDelegate"></param>
	/// <returns> IAbandonableContainer& </returns>
	SIMPLETHREAD_API IAbandonableContainer& operator<<(const FSimpleDelegate& SimpleDelegate);

	/// <summary>
	/// �첽��
	/// </summary>
	/// <param name="SimpleDelegate"></param>
	/// <returns> IAbandonableContainer& </returns>
	SIMPLETHREAD_API IAbandonableContainer& operator>>(const FSimpleDelegate& SimpleDelegate);
};

/// <summary>
/// Э������
/// </summary>
class ICoroutinesContainer
{
public:

	ICoroutinesContainer() : TempTotalTime(0.f){}

	virtual ~ICoroutinesContainer(){ICoroutineObject::Array.Empty(); }

public:
	/// <summary>
	/// �趨�����ӳ�ִ�е�ʱ��
	/// </summary>
	/// <param name="InTotalTime"></param>
	/// <returns> ICoroutinesContainer& </returns>
	SIMPLETHREAD_API ICoroutinesContainer& operator<<(float InTotalTime);

	/// <summary>
	/// �ô����TempTotalTime����FCoroutineObject, ����������
	/// </summary>
	/// <param name="InSimpleDelegate"></param>
	/// <returns> ICoroutinesContainer& </returns>
	SIMPLETHREAD_API ICoroutinesContainer& operator<<(FSimpleDelegate InSimpleDelegate);

	/// <summary>
	/// �ô���ֱ�ӹ���FCoroutineObject������������
	/// </summary>
	/// <param name="InSimpleDelegate"></param>
	/// <returns> FCoroutineHandle </returns>
	SIMPLETHREAD_API FCoroutineHandle operator>>(FSimpleDelegate InSimpleDelegate);

	SIMPLETHREAD_API void operator<<=(float InDeltaTime);

private:
	float TempTotalTime;

};

/// <summary>
/// GraphTask
/// </summary>
class IThreadGraphContainer : public IThreadContainer
{
public:
	
	//�������߳�
	SIMPLETHREAD_API FGraphEventRef operator<<(const FSimpleDelegate& InSimpleDelegate);

	//���������߳�
	SIMPLETHREAD_API FGraphEventRef operator>>(const FSimpleDelegate& InSimpleDelegate);
};


class IStreamableContainer
{
public:
	virtual ~IStreamableContainer(){}

	//�첽����
	//�洢·��
	SIMPLETHREAD_API IStreamableContainer& operator>>(const TArray<FSoftObjectPath>& InObjectPath);
	SIMPLETHREAD_API IStreamableContainer& operator>>(const FSoftObjectPath& InObjectPath);

	//����
	SIMPLETHREAD_API TSharedPtr<struct FStreamableHandle> operator>>(const FSimpleDelegate& InSimpleDelegate);




	//ͬ������
	SIMPLETHREAD_API TSharedPtr<struct FStreamableHandle> operator<<(const TArray<FSoftObjectPath>& InObjectPath);
	SIMPLETHREAD_API TSharedPtr<struct FStreamableHandle> operator<<(const FSoftObjectPath& InObjectPath);

protected:
	
	//���ģʽ��ģ�巽��
	virtual void SetObjectPath(const TArray<FSoftObjectPath>& InObjectPath) = 0;
	virtual void SetObjectPath(const FSoftObjectPath& InObjectPath) = 0;
	virtual TArray<FSoftObjectPath>& GetObjectPath() = 0;
	virtual struct FStreamableManager* GetStreamableManager() = 0;

};
