#pragma once
#include "../WeatherStation/WeatherData.h"
#include <string>
#include <vector>

class MockDeleteDisplay : public IObserver<SWeatherInfo>
{
public:
	MockDeleteDisplay(IObservable<SWeatherInfo>& weatherDataRef)
	{
		m_subject = &weatherDataRef;
		m_subject->RegisterObserver(*this);
	}

	void Update(SWeatherInfo const& data)
	{
		m_subject->RemoveObserver(*this);
	}

private:
	IObservable<SWeatherInfo>* m_subject;
};

class MockPriorityObserver : public IObserver<SWeatherInfo>
{
public:
	MockPriorityObserver(const std::string& name, std::vector<std::string>* priorities)
	{
		m_name = name;
		m_priorityVector = priorities;
	}

	void Update(SWeatherInfo const& data)
	{
		m_priorityVector->push_back(m_name);
	}

private:
	std::string m_name;
	std::vector<std::string>* m_priorityVector;
};