#pragma once
#include "IObserver.h"

template <typename T>
class ISubject
{
public:
	typedef IObserver<T> ObserverType;

	virtual void RegisterObserver(ObserverType& observerRef) = 0;
	virtual void RemoveObserver(ObserverType& observerRef) = 0;
	virtual void NotifyObservers() = 0;
};

template <typename T>
class IPrioritySubject
{
public:
	typedef IObserver<T> ObserverType;

	virtual void RegisterObserver(ObserverType& observerRef, unsigned int priority = 0) = 0;
	virtual void RemoveObserver(ObserverType& observerRef) = 0;
	virtual void NotifyObservers() = 0;
};
