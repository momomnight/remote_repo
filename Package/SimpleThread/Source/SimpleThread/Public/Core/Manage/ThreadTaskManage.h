#pragma once

#include "CoreMinimal.h"
#include "Interface/ThreadManageInterface.h"
#include "Core/Manage/ManageBase/ThreadManageBase.h"




//Bind ������񵽶���, ���ⲿTick
//Create Ѱ���̳߳�����߳�, ִ������, ���޹����߳�, ����ӵ�����
class SIMPLETHREAD_API FThreadTaskManage 
	: public TThreadTemplate<IThreadTaskContainer, IThreadTaskContainer&>
{
	//FThreadTaskManage�߳����̶�
	void Initialize(int32 ThreadNumber);

private:
	static TSharedPtr<FThreadTaskManage> ThreadTaskManage;

	FThreadTaskManage();
	FThreadTaskManage(const FThreadTaskManage&) = delete;
	FThreadTaskManage& operator=(const FThreadTaskManage&) = delete;

public:
	using Super = TThreadTemplate<IThreadTaskContainer, IThreadTaskContainer&>;

	static TSharedRef<FThreadTaskManage> Get();
	static void Destroy();
	
	~FThreadTaskManage();

	//����̷߳���
	void Tick(float DeltaTime);
};