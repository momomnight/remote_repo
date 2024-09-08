#pragma once

#include "CoreMinimal.h"
#include "Interface/ThreadManageInterface.h"
#include "Core/Manage/ManageBase/ThreadManageBase.h"

// Bind ��UE�̳߳ػ�ȡ�߳�,ͬ��ִ������
// Create ��UE�̳߳ػ�ȡ�߳�,�첽ִ������
class SIMPLETHREAD_API FThreadAbandonableManage :public TThreadTemplate<IAbandonableContainer, void>
{
	static TSharedPtr<FThreadAbandonableManage> ThreadAbandonableManage;
	
	FThreadAbandonableManage();
	FThreadAbandonableManage(const FThreadAbandonableManage&) = delete;
	FThreadAbandonableManage& operator=(const FThreadAbandonableManage&) = delete;

public:
        
	static TSharedRef<FThreadAbandonableManage> Get();
	static void Destroy();
};