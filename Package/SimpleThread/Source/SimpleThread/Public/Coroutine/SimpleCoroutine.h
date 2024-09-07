#pragma once

#include "CoreMinimal.h"
#include "Core/SimpleThreadType.h"

struct FCoroutineRequest
{
	FCoroutineRequest(float InDeltaTime);

	bool bCompleteRequest;
	float DeltaTime;
};

class ICoroutineObject : public TSharedFromThis<ICoroutineObject>
{
	friend class ICoroutinesContainer;
public:
	ICoroutineObject();
	virtual ~ICoroutineObject(){}

	bool operator==(const ICoroutineObject& InCoroutineObject)
	{
		return this->Handle == InCoroutineObject.Handle;
	}
	FORCEINLINE void Awake(){ bAwaken = true;}

protected:
	virtual void Update(FCoroutineRequest& InRequest) = 0;


protected:

	static TArray<TSharedPtr<ICoroutineObject>> Array;
	bool bAwaken;
	FSimpleThreadHandle Handle;
};

typedef TWeakPtr<ICoroutineObject> FCoroutineHandle;


class FCoroutineObject : public ICoroutineObject
{
public:
	//如果不提供TotalTime,则需要使用Awake
	FCoroutineObject(const FSimpleDelegate& InSimpleDelegate, float InTotalTime = -1.f);
	~FCoroutineObject(){}

protected:
	virtual void Update(FCoroutineRequest& InRequest) final;


private:
	FSimpleDelegate SimpleDelegate;
	const float TotalTime;
	float RunningTime;

};
