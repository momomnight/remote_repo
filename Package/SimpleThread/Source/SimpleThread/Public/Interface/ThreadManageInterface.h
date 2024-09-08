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
/// 可以自由创建线程, 执行完线程会加入线程池
/// 具有同步与异步功能，一般用于小场景
/// </summary>
class IThreadProxyContainer : public TArray<TSharedPtr<IThreadProxy>>, public IThreadContainer
{
	
protected:
	typedef TArray<TSharedPtr<IThreadProxy>> TProxyArray;

public:

	/// <summary>
	/// 将FThreadRunnable加入容器, 无论是否真正持有线程都可以应付
	/// </summary>
	/// <param name="InThreadProxy"></param>
	/// <returns> FThreadHandle </returns>
	SIMPLETHREAD_API IThreadProxyContainer& operator<<(const TSharedPtr<IThreadProxy>& InThreadProxy);


	/// <summary>
	/// 绑定并执行
	/// </summary>
	/// <param name="InDelegate"></param>
	/// <returns> FThreadHandle </returns>
	SIMPLETHREAD_API FThreadHandle operator>>(const FSimpleDelegate& InDelegate);

	/// <summary>
	/// 绑定不执行
	/// </summary>
	/// <param name="InDelegate"></param>
	/// <returns> FThreadHandle </returns>
	SIMPLETHREAD_API FThreadHandle operator<<(const FSimpleDelegate& InDelegate);

	/// <summary>
	/// 查询ThreadHandle，返回FThreadRunnable指针等效TSharedPtr<IThreadProxy>
	/// </summary>
	/// <param name="InThreadHandle"></param>
	/// <returns> TSharedPtr<IThreadProxy> </returns>
	SIMPLETHREAD_API TSharedPtr<IThreadProxy> operator<<(const FThreadHandle& InThreadHandle);

};


/// <summary>
/// 线程的任务管理，可以自动管理任务，自动配置闲置线程
/// </summary>
class IThreadTaskContainer : public TQueue<FSimpleDelegate>, public TArray<TSharedPtr<IThreadProxy>>, public IThreadContainer
{

protected:
	typedef TArray<TSharedPtr<IThreadProxy>> TProxyArray;
	typedef TQueue<FSimpleDelegate> TTaskQueue;
public:
	IThreadTaskContainer();

	/// <summary>
	/// 任务加入队列
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
	/// 任务移出队列;
	/// </summary>
	/// <param name="InDelegate"></param>
	/// <returns> IThreadTaskContainer& </returns>
	SIMPLETHREAD_API bool operator>>=(FSimpleDelegate& InDelegate);

	/// <summary>
	/// 添加线程
	/// </summary>
	/// <param name="InThreadProxy"></param>
	/// <returns> IThreadTaskContainer& </returns>
	SIMPLETHREAD_API IThreadTaskContainer& operator<<(const TSharedPtr<IThreadProxy>& InThreadProxy);

};

/// <summary>
/// 使用UE线程池
/// </summary>
class IAbandonableContainer : public IThreadContainer
{

public:
	/// <summary>
	/// 同步绑定
	/// </summary>
	/// <param name="SimpleDelegate"></param>
	/// <returns> IAbandonableContainer& </returns>
	SIMPLETHREAD_API IAbandonableContainer& operator<<(const FSimpleDelegate& SimpleDelegate);

	/// <summary>
	/// 异步绑定
	/// </summary>
	/// <param name="SimpleDelegate"></param>
	/// <returns> IAbandonableContainer& </returns>
	SIMPLETHREAD_API IAbandonableContainer& operator>>(const FSimpleDelegate& SimpleDelegate);
};

/// <summary>
/// 协程容器
/// </summary>
class ICoroutinesContainer
{
public:

	ICoroutinesContainer() : TempTotalTime(0.f){}

	virtual ~ICoroutinesContainer(){ICoroutineObject::Array.Empty(); }

public:
	/// <summary>
	/// 设定用于延迟执行的时间
	/// </summary>
	/// <param name="InTotalTime"></param>
	/// <returns> ICoroutinesContainer& </returns>
	SIMPLETHREAD_API ICoroutinesContainer& operator<<(float InTotalTime);

	/// <summary>
	/// 用代理和TempTotalTime构造FCoroutineObject, 并加入容器
	/// </summary>
	/// <param name="InSimpleDelegate"></param>
	/// <returns> ICoroutinesContainer& </returns>
	SIMPLETHREAD_API ICoroutinesContainer& operator<<(FSimpleDelegate InSimpleDelegate);

	/// <summary>
	/// 用代理直接构造FCoroutineObject，并加入容器
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
	
	//呼叫主线程
	SIMPLETHREAD_API FGraphEventRef operator<<(const FSimpleDelegate& InSimpleDelegate);

	//呼叫其他线程
	SIMPLETHREAD_API FGraphEventRef operator>>(const FSimpleDelegate& InSimpleDelegate);
};


class IStreamableContainer
{
public:
	virtual ~IStreamableContainer(){}

	//异步加载
	//存储路径
	SIMPLETHREAD_API IStreamableContainer& operator>>(const TArray<FSoftObjectPath>& InObjectPath);
	SIMPLETHREAD_API IStreamableContainer& operator>>(const FSoftObjectPath& InObjectPath);

	//加载
	SIMPLETHREAD_API TSharedPtr<struct FStreamableHandle> operator>>(const FSimpleDelegate& InSimpleDelegate);




	//同步加载
	SIMPLETHREAD_API TSharedPtr<struct FStreamableHandle> operator<<(const TArray<FSoftObjectPath>& InObjectPath);
	SIMPLETHREAD_API TSharedPtr<struct FStreamableHandle> operator<<(const FSoftObjectPath& InObjectPath);

protected:
	
	//设计模式，模板方法
	virtual void SetObjectPath(const TArray<FSoftObjectPath>& InObjectPath) = 0;
	virtual void SetObjectPath(const FSoftObjectPath& InObjectPath) = 0;
	virtual TArray<FSoftObjectPath>& GetObjectPath() = 0;
	virtual struct FStreamableManager* GetStreamableManager() = 0;

};
