
#include "Abandonable/SimpleAbandonable.h"

FSimpleAbandonable::FSimpleAbandonable(const FSimpleDelegate& SimpleDelegate) : ThreadDelegate(SimpleDelegate)
{
	
}

void FSimpleAbandonable::DoWork()
{
	ThreadDelegate.ExecuteIfBound();
}
