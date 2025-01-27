#pragma once
#include "IObserver.h"
#include "EventType.h"

class IObservable
{
public:
	virtual void RemoveObserver(IObserver& observerRef) = 0;
	virtual void SubscribeToEvent(IObserver& observerRef, EventType eventType, unsigned int priority = 0) = 0;
	virtual void UnsubscribeFromEvent(IObserver& observerRef, EventType eventType) = 0;
	virtual ~IObservable() = default;
};
