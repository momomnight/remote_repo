#pragma once

#include "CoreMinimal.h"
#include "Interface/ThreadManageInterface.h"
#include "Core/Manage/ManageBase/ThreadManageBase.h"

DECLARE_LOG_CATEGORY_EXTERN(LogThreadProxyManage, Log, All);

// Bind Ѱ�ҹ����߳�, ������, ���޹����߳��򴴽��߳�, ��ִ��ֱ��ִ������
//		ͨ��Join()��Detach()ִ��
// Create Ѱ�ҹ����߳�, ������, ���޹����߳��򴴽��߳�, ��ִ������
class SIMPLETHREAD_API FThreadProxyManage :public TThreadTemplate<IThreadProxyContainer, FThreadHandle>
{
public:
	static TSharedRef<FThreadProxyManage> Get();
	static void Destroy();

private:
	static TSharedPtr<FThreadProxyManage> ThreadProxyManage;

	FThreadProxyManage();
	FThreadProxyManage(const FThreadProxyManage&) = delete;
	FThreadProxyManage& operator=(const FThreadProxyManage&) = delete;

public:
	~FThreadProxyManage();

	//ͬ��
	bool Join(FThreadHandle Handle);

	//�첽
	bool Detach(FThreadHandle Handle);

	EThreadState Joinable(FThreadHandle Handle);
};