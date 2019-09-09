#pragma once

template <typename T>
class IObservable;

template <typename T>
class IObserver
{
public:
	virtual void Update(T const& data, IObservable<T>& subject) = 0;
	virtual ~IObserver() = default;
};