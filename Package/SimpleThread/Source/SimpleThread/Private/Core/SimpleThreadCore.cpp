
#include "Core/SimpleThreadType.h"
#include "Interface/ProxyInterface.h"

inline uint64 SpawnUniqueId()
{
	return FMath::Abs(FMath::RandRange(100, 12452328) + FDateTime::Now().GetTicks());
}


FSimpleThreadHandle::FSimpleThreadHandle(bool NewHandle)
{
	if (NewHandle)
	{
		GuidTypeA = SpawnUniqueId();
		GuidTypeB = SpawnUniqueId();
		GuidTypeC = SpawnUniqueId();
		GuidTypeD = SpawnUniqueId();
	}
	else
	{
		GuidTypeA = 0;
		GuidTypeB = 0;
		GuidTypeC = 0;
		GuidTypeD = 0;
	}
}


IThreadProxy::IThreadProxy() :SimpleThreadHandle(MakeShareable(new FSimpleThreadHandle))
{

}

IThreadProxy::~IThreadProxy()
{
}
