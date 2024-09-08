#pragma once
#include <thread>
#include "Misc/ScopeLock.h"
#include "Async/AsyncWork.h"
#include "Abandonable/SimpleAbandonable.h"
#include "Delegates/Delegate.h"

#define WAIT_TIME_PER_TIME 0.03f
#define WAIT_MILLISECONDS 30 
#define WAIT_SECONDS 1


#define WAIT_TIMES 30
#define SCOPE_MUTEX(Mutex) FScopeLock ScopeLock(&Mutex)
#define CPU_THREAD_NUMBER std::thread::hardware_concurrency()


//异步
#define USE_UE_THREAD_POOL_ASYNC_TASK(ThreadDelegate)\
(new FAutoDeleteAsyncTask<FSimpleAbandonable>(ThreadDelegate))->StartBackgroundTask()

//同步
#define USE_UE_THREAD_POOL_SYNC_TASK(ThreadDelegate)\
{FAsyncTask<FSimpleAbandonable>* SimpleAbandonable = new FAsyncTask<FSimpleAbandonable>(ThreadDelegate);\
SimpleAbandonable->StartBackgroundTask();\
SimpleAbandonable->EnsureCompletion();\
delete SimpleAbandonable;}


//同步
#define SYNC_TASK_UOBJECT(Object, ...)\
USE_UE_THREAD_POOL_SYNC_TASK(FSimpleDelegate::CreateUObject(Object,__VA_ARGS__))

#define SYNC_TASK_RAW(Object, ...)\
USE_UE_THREAD_POOL_SYNC_TASK(FSimpleDelegate::CreateRaw(Object,__VA_ARGS__))

#define SYNC_TASK_SP(Object, ...)\
USE_UE_THREAD_POOL_SYNC_TASK(FSimpleDelegate::CreateSP(Object, __VA_ARGS__))

#define SYNC_TASK_LAMBDA(...)\
USE_UE_THREAD_POOL_SYNC_TASK(FSimpleDelegate::CreateLambda(__VA_ARGS__))

#define SYNC_TASK_THREADSAFESP(Object, ...)\
USE_UE_THREAD_POOL_SYNC_TASK(FSimpleDelegate::CreateThreadSafeSP(Object, __VA_ARGS__))

#define SYNC_TASK_SPLAMBDA(Object, ...)\
USE_UE_THREAD_POOL_SYNC_TASK(FSimpleDelegate::CreateSPLambda(Object, __VA_ARGS__))

#define SYNC_TASK_WEAKLAMBDA(Object, ...)\
USE_UE_THREAD_POOL_SYNC_TASK(FSimpleDelegate::CreateWeakLambda(Object, __VA_ARGS__))

#define SYNC_TASK_UFUNCTION(Object, ...)\
USE_UE_THREAD_POOL_SYNC_TASK(FSimpleDelegate::CreateUFunction(Object, __VA_ARGS__))

#define SYNC_TASK_STATIC(...)\
USE_UE_THREAD_POOL_SYNC_TASK(FSimpleDelegate::CreateStatic(__VA_ARGS__))


//异步
#define ASYNC_TASK_UOBJECT(Object, ...)\
USE_UE_THREAD_POOL_ASYNC_TASK(FSimpleDelegate::CreateUObject(Object, __VA_ARGS__))

#define ASYNC_TASK_RAW(Object, ...)\
USE_UE_THREAD_POOL_ASYNC_TASK(FSimpleDelegate::CreateRaw(Object, __VA_ARGS__))

#define ASYNC_TASK_SP(Object, ...)\
USE_UE_THREAD_POOL_ASYNC_TASK(FSimpleDelegate::CreateSP(Object, __VA_ARGS__))

#define ASYNC_TASK_LAMBDA(...)\
USE_UE_THREAD_POOL_ASYNC_TASK(FSimpleDelegate::CreateLambda(__VA_ARGS__))

#define ASYNC_TASK_THREADSAFESP(Object, ...)\
USE_UE_THREAD_POOL_ASYNC_TASK(FSimpleDelegate::CreateThreadSafeSP(Object, __VA_ARGS__))

#define ASYNC_TASK_SPLAMBDA(Object, ...)\
USE_UE_THREAD_POOL_ASYNC_TASK(FSimpleDelegate::CreateSPLambda(Object, __VA_ARGS__))

#define ASYNC_TASK_WEAKLAMBDA(Object, ...)\
USE_UE_THREAD_POOL_ASYNC_TASK(FSimpleDelegate::CreateWeakLambda(Object, __VA_ARGS__))

#define ASYNC_TASK_UFUNCTION(Object, ...)\
USE_UE_THREAD_POOL_ASYNC_TASK(FSimpleDelegate::CreateUFunction(Object, __VA_ARGS__))

#define ASYNC_TASK_STATIC(...)\
USE_UE_THREAD_POOL_ASYNC_TASK(FSimpleDelegate::CreateStatic(__VA_ARGS__))


//GraphTask_Lambda
#define SYNC_GRAPH_TASK_LAMBDA(RequestedThread, OtherTaskEvent, Lambda)\
{FGraphEventRef NewTask = FFunctionGraphTask::CreateAndDispatchWhenReady(\
	Lambda, TStatId(), OtherTaskEvent, RequestedThread);\
FTaskGraphInterface::Get().WaitUntilTaskCompletes(NewTask);}

#define ASYNC_GRAPH_TASK_LAMBDA(RequestedThread, OtherTaskEvent, Lambda)\
FFunctionGraphTask::CreateAndDispatchWhenReady(\
	Lambda, TStatId(), OtherTaskEvent, RequestedThread);




//GraphTask_FSimpleDelegate
#define GRAPH_TASK_SIMPLE_DELEGATE(EventRef, RequestedThread, OtherTaskEvent, SimpleDelegate)\
EventRef = FSimpleDelegateGraphTask::CreateAndDispatchWhenReady(\
	SimpleDelegate, TStatId(), OtherTaskEvent, RequestedThread)



#define GRAPH_TASK_UOBJECT(EventRef, RequestedThread, OtherTaskEvent, Object, ...)\
	GRAPH_TASK_SIMPLE_DELEGATE(EventRef, RequestedThread, OtherTaskEvent,\
		FSimpleDelegate::CreateUObject(Object, __VA_ARGS__))

#define GRAPH_TASK_RAW(EventRef, RequestedThread, OtherTaskEvent, Object, ...)\
	GRAPH_TASK_SIMPLE_DELEGATE(EventRef, RequestedThread, OtherTaskEvent, \
		FSimpleDelegate::CreateRaw(Object, __VA_ARGS__))

#define GRAPH_TASK_SP(EventRef, RequestedThread, OtherTaskEvent, Object, ...)\
	GRAPH_TASK_SIMPLE_DELEGATE(EventRef, RequestedThread, OtherTaskEvent, \
		FSimpleDelegate::CreateSP(Object, __VA_ARGS__))

#define GRAPH_TASK_LAMBDA(EventRef, RequestedThread, OtherTaskEvent, ...)\
	GRAPH_TASK_SIMPLE_DELEGATE(EventRef, RequestedThread, OtherTaskEvent, \
		FSimpleDelegate::CreateLambda(__VA_ARGS__))

#define GRAPH_TASK_THREADSAFESP(EventRef, RequestedThread, OtherTaskEvent, Object, ...)\
	GRAPH_TASK_SIMPLE_DELEGATE(EventRef, RequestedThread, OtherTaskEvent, \
		FSimpleDelegate::CreateThreadSafeSP(Object, __VA_ARGS__))

#define GRAPH_TASK_SPLambda(EventRef, RequestedThread, OtherTaskEvent, Object, ...)\
	GRAPH_TASK_SIMPLE_DELEGATE(EventRef, RequestedThread, OtherTaskEvent, \
		FSimpleDelegate::CreateSPLambda(Object, __VA_ARGS__))

#define GRAPH_TASK_WeakLambda(EventRef, RequestedThread, OtherTaskEvent, Object, ...)\
	GRAPH_TASK_SIMPLE_DELEGATE(EventRef, RequestedThread, OtherTaskEvent, \
		FSimpleDelegate::CreateWeakLambda(Object, __VA_ARGS__))

#define GRAPH_TASK_Static(EventRef, RequestedThread, OtherTaskEvent, ...)\
	GRAPH_TASK_SIMPLE_DELEGATE(EventRef, RequestedThread, OtherTaskEvent, \
		FSimpleDelegate::CreateStatic(__VA_ARGS__))

#define GRAPH_TASK_UFunction(EventRef, RequestedThread, OtherTaskEvent, Object, ...)\
	GRAPH_TASK_SIMPLE_DELEGATE(EventRef, RequestedThread, OtherTaskEvent, \
		FSimpleDelegate::CreateUFunction(Object, __VA_ARGS__))


//等待GraphTask
#define WAIT_GRAPH_TASK_COMPLETED(EventRef)\
FTaskGraphInterface::Get().WaitUntilTaskCompletes(EventRef)

#define WAIT_MULTIPLY_GRAPH_TASK_COMPLETED(EventArray)\
FTaskGraphInterface::Get().WaitUntilTasksComplete(EventArray)


////RenderThread
//class FRenderThread
//{
//
//public:
//	static ENamedThreads::Type GetDesiredThread()
//	{
//		check(!GIsThreadedRendering || ENamedThreads::GetRenderThread()
//			!= ENamedThreads::GameThread);
//		return ENamedThreads::GetRenderThread();
//	}
//
//	static ESubsequentsMode::Type GetSubsequentsMode()
//	{
//		return ESubsequentsMode::FireAndForget;
//	}
//
//};
//
//
//#define DO_TASK_THREAD(Code)\
//void DoTask(ENamedThreads::Type CurrentThread, const FGraphEventRef& InGraphEventRef)\
//{\
//	FRHICommandListImmediate& RHICmdList = GetImmediateCommandList_ForRenderCommand();\
//	Code;\
//}
//
//#define DO_TASK_THREAD_ID(TypeName)\
//FORCEINLINE TStatId GetStatId() const\
//{\
//	RETURN_QUICK_DECLARE_CYCLE_STAT(TypeName, STATGROUP_RenderThreadCommands);\
//}
//
//
//#define CALL_RENDER_THREAD(Code)\
//{class FRanderExample : public FRenderThread\
//{\
//public:\
//	DO_TASK_THREAD(Code);\
//	DO_TASK_THREAD_ID(FRanderExample);\
//};\
//{\
//	if(ShouldExecuteOnRenderThread())\
//	{\
//		CheckNotBlockedOnRenderThread()\
//		TGraphTask<FRenderExample>::CreateTask().ConstructAndDispathWhenReady();\
//	}\
//	else\
//	{\
//		FRanderExample RenderExample;\
//		FScopeCycleCounter ScopeCycleCounter(RenderExample.GetStatId());\
//		RenderExample.DoTask(ENamedThreads::GameThread, FGraphEventRef());\
//	}\
//}}
//








