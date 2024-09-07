

#include "Coroutine/SimpleCoroutine.h"

TArray<TSharedPtr<ICoroutineObject>> ICoroutineObject::Array{};

ICoroutineObject::ICoroutineObject()
	: bAwaken(false), Handle()
{
}

FCoroutineRequest::FCoroutineRequest(float InDeltaTime)
	:bCompleteRequest(false), DeltaTime(InDeltaTime)
{
}


FCoroutineObject::FCoroutineObject(const FSimpleDelegate& InSimpleDelegate, float InTotalTime)
	:ICoroutineObject(), SimpleDelegate(InSimpleDelegate), TotalTime(InTotalTime), RunningTime(0)
{

}

void FCoroutineObject::Update(FCoroutineRequest& InRequest)
{
	if (TotalTime != -1.f)
	{
		RunningTime += InRequest.DeltaTime;
		if (RunningTime >= TotalTime)
		{
			SimpleDelegate.ExecuteIfBound();
			InRequest.bCompleteRequest = true;
		}
	}
	else
	{
		if (bAwaken)
		{
			SimpleDelegate.ExecuteIfBound();
			InRequest.bCompleteRequest = true;
		}
	}
}
