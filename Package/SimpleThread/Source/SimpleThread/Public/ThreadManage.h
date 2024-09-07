#pragma once


#include "CoreMinimal.h"
#include "Core/Manage/ThreadProxyManage.h"
#include "Core/Manage/ThreadTaskManage.h"
#include "Core/Manage/ThreadAbandonableManage.h"
#include "Core/Manage/CoroutineManage.h"
#include "Core/Manage/ThreadGraphManage.h"
#include "Core/Manage/ResourceLoadingManage.h"
#include "Tickable.h"



namespace TM{
	
	//FThreadManagement是线程安全的
	class SIMPLETHREAD_API FThreadManagement 
		:	public TSharedFromThis<FThreadManagement>,
			public FTickableGameObject
	{
		FThreadManagement();

	public:
		static TSharedRef<FThreadManagement> Get();
		static void Destroy();

	private:
		virtual void Tick(float DeltaTime);
		virtual TStatId GetStatId() const;

	public:
		static TSharedRef<FThreadProxyManage>			GetProxyManage();
		static TSharedRef<FThreadTaskManage>			GetTaskManage();
		static TSharedRef<FThreadAbandonableManage>		GetAbandonableManage();		
		static TSharedRef<FCoRoutinesManage>			GetCoRoutinesManage();	
		static TSharedRef<FThreadGraphManage>			GetGraphManage();		
		static TSharedRef<FResourceLoadingManage>		GetResourecLoadingManage();

		static void	DestroyProxyManage();
		static void	DestroyTaskManage();
		static void	DestroyAbandonableManage();
		static void	DestroyCoRoutinesManage();
		static void	DestroyGraphManage();
		static void	DestroyResourecLoadingManage();
	
	protected:
		//自定义线程创建，用于简单且直接的创建线程
		TSharedPtr<FThreadProxyManage> ThreadProxyManage;

		//自定义线程池，任务直接丢入池中
		//需要自己初始化决定是否使用
		TSharedPtr<FThreadTaskManage> ThreadTaskManage;

		//使用UE的线程池
		TSharedPtr<FThreadAbandonableManage> ThreadAbandonableManage;

		//协程，功能简陋，只能用于定时
		//想实现更为复杂的协程功能，可使用SimpleCoroutineCpp20
		//这是对C++20协程的封装
		TSharedPtr<FCoRoutinesManage> CoRoutinesManage;

		//UE带前置任务的Graph
		TSharedPtr<FThreadGraphManage> ThreadGraphManage;

		//资源加载
		TSharedPtr<FResourceLoadingManage> ResourecLoadingManage;
	private:
		static TSharedPtr<FThreadManagement> ThreadManagement;

	};
}

typedef TM::FThreadManagement GThread;