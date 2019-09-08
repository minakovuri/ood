#pragma once

template <typename T>
class ISubject;

template <typename T>
class IObserver
{
public:
	virtual void Update(T const& data, ISubject<T>& subject) = 0;
	virtual ~IObserver() = default;
};