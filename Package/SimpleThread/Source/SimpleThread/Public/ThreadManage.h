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
	
	//FThreadManagement���̰߳�ȫ��
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
		//�Զ����̴߳��������ڼ���ֱ�ӵĴ����߳�
		TSharedPtr<FThreadProxyManage> ThreadProxyManage;

		//�Զ����̳߳أ�����ֱ�Ӷ������
		//��Ҫ�Լ���ʼ�������Ƿ�ʹ��
		TSharedPtr<FThreadTaskManage> ThreadTaskManage;

		//ʹ��UE���̳߳�
		TSharedPtr<FThreadAbandonableManage> ThreadAbandonableManage;

		//Э�̣����ܼ�ª��ֻ�����ڶ�ʱ
		//��ʵ�ָ�Ϊ���ӵ�Э�̹��ܣ���ʹ��SimpleCoroutineCpp20
		//���Ƕ�C++20Э�̵ķ�װ
		TSharedPtr<FCoRoutinesManage> CoRoutinesManage;

		//UE��ǰ�������Graph
		TSharedPtr<FThreadGraphManage> ThreadGraphManage;

		//��Դ����
		TSharedPtr<FResourceLoadingManage> ResourecLoadingManage;
	private:
		static TSharedPtr<FThreadManagement> ThreadManagement;

	};
}

typedef TM::FThreadManagement GThread;