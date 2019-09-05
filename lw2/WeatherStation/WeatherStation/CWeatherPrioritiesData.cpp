#include "WeatherData.h"

void CWeatherPrioritiesData::RegisterObserver(WeatherObserver& observerRef, unsigned int priority)
{
	m_observersPriority.emplace(priority, &observerRef);
}

void CWeatherPrioritiesData::RemoveObserver(WeatherObserver& observerRef)
{
	for (auto priority : m_observersPriority)
	{
		if (priority.second == &observerRef)
		{
			m_observersPriority.erase(priority.first);
			break;
		}
	}
}

void CWeatherPrioritiesData::NotifyObservers()
{
	SWeatherInfo data = GetChangedData();

	auto priorities(m_observersPriority);

	for (auto priority : priorities)
	{
		priority.second->Update(data);
	}
}

void CWeatherPrioritiesData::MeasurementsChanged()
{
	NotifyObservers();
}

void CWeatherPrioritiesData::SetMeasurements(float temperature, float humidity, float pressure)
{
	m_temperature = temperature;
	m_humidity = humidity;
	m_pressure = pressure;

	MeasurementsChanged();
}

SWeatherInfo CWeatherPrioritiesData::GetChangedData() const
{
	SWeatherInfo info;
	info.temperature = m_temperature;
	info.humidity = m_humidity;
	info.pressure = m_pressure;
	return info;
}