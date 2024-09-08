
#include "ThreadManage.h"


namespace TM{
	TSharedPtr<FThreadManagement> FThreadManagement::ThreadManagement{ nullptr };

	FThreadManagement::FThreadManagement()
		:	ThreadProxyManage(nullptr), ThreadTaskManage(nullptr), ThreadAbandonableManage(nullptr)
			,CoRoutinesManage(nullptr), ThreadGraphManage(nullptr), ResourecLoadingManage(nullptr)
	{
	}

	TSharedRef<FThreadManagement> FThreadManagement::Get()
	{

		if (!ThreadManagement.IsValid())
		{
			ThreadManagement = MakeShareable(new FThreadManagement());
		}

		return ThreadManagement.ToSharedRef();
	}

	void FThreadManagement::Destroy()
	{
		if (ThreadManagement.IsValid())
		{
			if (ThreadManagement->ThreadProxyManage.IsValid())
			{
				//置空FThreadProxyManage内的静态ThreadProxyManage
				ThreadManagement->ThreadProxyManage->Destroy();
				//析构ThreadProxyManage所指向的对象，并置空
				ThreadManagement->ThreadProxyManage.Reset();
			}

			if (ThreadManagement->ThreadTaskManage.IsValid())
			{
				ThreadManagement->ThreadTaskManage->Destroy();
				ThreadManagement->ThreadTaskManage.Reset();
			}

			if (ThreadManagement->ThreadAbandonableManage.IsValid())
			{
				ThreadManagement->ThreadAbandonableManage->Destroy();
				ThreadManagement->ThreadAbandonableManage.Reset();
			}

			if (ThreadManagement->CoRoutinesManage.IsValid())
			{
				ThreadManagement->CoRoutinesManage->Destroy();
				ThreadManagement->CoRoutinesManage.Reset();
			}

			if (ThreadManagement->ThreadGraphManage.IsValid())
			{
				ThreadManagement->ThreadGraphManage->Destroy();
				ThreadManagement->ThreadGraphManage.Reset();
			}

			if (ThreadManagement->ResourecLoadingManage.IsValid())
			{
				ThreadManagement->ResourecLoadingManage->Destroy();
				ThreadManagement->ResourecLoadingManage.Reset();
			}

			ThreadManagement.Reset();
		}
	}

	void FThreadManagement::Tick(float DeltaTime)
	{
		if (CoRoutinesManage.IsValid())
		{
			CoRoutinesManage->Tick(DeltaTime);
		}
		if (ThreadTaskManage.IsValid())
		{
			ThreadTaskManage->Tick(DeltaTime);
		}

		
	}

	TStatId FThreadManagement::GetStatId() const
	{
		return TStatId();
	}

	TSharedRef<FThreadProxyManage> FThreadManagement::GetProxyManage()
	{
		if(!Get()->ThreadProxyManage.IsValid())
		{
			Get()->ThreadProxyManage = FThreadProxyManage::Get();
		}
		return Get()->ThreadProxyManage.ToSharedRef();
	}

	TSharedRef<FThreadTaskManage> FThreadManagement::GetTaskManage()
	{ 
		if (!Get()->ThreadTaskManage.IsValid())
		{
			Get()->ThreadTaskManage = FThreadTaskManage::Get();
		}
		return Get()->ThreadTaskManage.ToSharedRef();
	}

	TSharedRef<FThreadAbandonableManage> FThreadManagement::GetAbandonableManage()
	{ 
		if (!Get()->ThreadAbandonableManage.IsValid())
		{
			Get()->ThreadAbandonableManage = FThreadAbandonableManage::Get();
		}
		return Get()->ThreadAbandonableManage.ToSharedRef();
	}
	TSharedRef<FCoRoutinesManage> FThreadManagement::GetCoRoutinesManage()
	{ 
		if (!Get()->CoRoutinesManage.IsValid())
		{
			Get()->CoRoutinesManage = FCoRoutinesManage::Get();
		}
		return Get()->CoRoutinesManage.ToSharedRef(); 
	}

	TSharedRef<FThreadGraphManage> FThreadManagement::GetGraphManage()
	{ 
		if (!Get()->ThreadGraphManage.IsValid())
		{
			Get()->ThreadGraphManage = FThreadGraphManage::Get();
		}
		return Get()->ThreadGraphManage.ToSharedRef(); 
	
	}
	TSharedRef<FResourceLoadingManage> FThreadManagement::GetResourecLoadingManage()
	{ 
		if (!Get()->ResourecLoadingManage.IsValid())
		{
			Get()->ResourecLoadingManage = FResourceLoadingManage::Get();
		}
		return Get()->ResourecLoadingManage.ToSharedRef();
	}

	void FThreadManagement::DestroyProxyManage()
	{
		if (ThreadManagement.IsValid() && ThreadManagement->ThreadProxyManage.IsValid())
		{
			ThreadManagement->ThreadProxyManage->Destroy();
			ThreadManagement->ThreadProxyManage.Reset();
		}
	}

	void FThreadManagement::DestroyTaskManage()
	{
		if (ThreadManagement.IsValid() && ThreadManagement->ThreadTaskManage.IsValid())
		{
			ThreadManagement->ThreadTaskManage->Destroy();
			ThreadManagement->ThreadTaskManage.Reset();
		}
	}

	void FThreadManagement::DestroyAbandonableManage()
	{
		if (ThreadManagement.IsValid() && ThreadManagement->ThreadAbandonableManage.IsValid())
		{
			ThreadManagement->ThreadAbandonableManage->Destroy();
			ThreadManagement->ThreadAbandonableManage.Reset();
		}
	}

	void FThreadManagement::DestroyCoRoutinesManage()
	{
		if (ThreadManagement.IsValid() && ThreadManagement->CoRoutinesManage.IsValid())
		{
			ThreadManagement->CoRoutinesManage->Destroy();
			ThreadManagement->CoRoutinesManage.Reset();
		}
	}

	void FThreadManagement::DestroyGraphManage()
	{
		if (ThreadManagement.IsValid() && ThreadManagement->ThreadGraphManage.IsValid())
		{
			ThreadManagement->ThreadGraphManage->Destroy();
			ThreadManagement->ThreadGraphManage.Reset();
		}
	}

	void FThreadManagement::DestroyResourecLoadingManage()
	{
		if (ThreadManagement.IsValid() && ThreadManagement->ResourecLoadingManage.IsValid())
		{
			ThreadManagement->ResourecLoadingManage->Destroy();
			ThreadManagement->ResourecLoadingManage.Reset();
		}
	}
}

