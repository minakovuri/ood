#include "WeatherData.h"

void CWeatherPrioritiesData::RegisterObserver(WeatherObserver& observerRef, unsigned int priority)
{
	m_observersPriority.emplace(priority, &observerRef);
}

void CWeatherPrioritiesData::RemoveObserver(WeatherObserver& observerRef)
{
	for (auto iterator = m_observersPriority.begin(); iterator != m_observersPriority.end(); ++iterator)
	{
		if (iterator->second == &observerRef)
		{
			m_observersPriority.erase(iterator);
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

void CWeatherPrioritiesData::SetMeasurements(double temperature, double humidity, double pressure)
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