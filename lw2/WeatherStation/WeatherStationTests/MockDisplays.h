#pragma once
#include "../WeatherStation/WeatherData.h"
#include <string>

class MockDeleteDisplay : public IObserver<SWeatherInfo>
{
public:
	MockDeleteDisplay(ISubject<SWeatherInfo>& weatherDataRef)
	{
		m_subject = &weatherDataRef;
		m_subject->RegisterObserver(*this);
	}

	void Update(SWeatherInfo const& data)
	{
		m_subject->RemoveObserver(*this);
	}

private:
	ISubject<SWeatherInfo>* m_subject;
};

class MockPriorityObserver : public IObserver<SWeatherInfo>
{
	MockPriorityObserver(std::string& const name)
	{
		m_name = name;
	}

	void Update(SWeatherInfo const& data)
	{
	}

private:
	std::string m_name;
};