#include "WeatherData.h"

void CWeatherData::RegisterObserver(WeatherObserver& observerRef, unsigned int priority)
{
	m_observersPriority.emplace(priority, &observerRef);
}

void CWeatherData::RemoveObserver(WeatherObserver& observerRef)
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

void CWeatherData::NotifyObservers()
{
	SWeatherInfo data = GetChangedData();

	auto priorities(m_observersPriority);

	for (auto priority : priorities)
	{
		priority.second->Update(data);
	}
}

void CWeatherData::MeasurementsChanged()
{
	NotifyObservers();
}

void CWeatherData::SetMeasurements(double temperature, double humidity, double pressure, double windSpeed, double windDirection)
{
	m_temperature = temperature;
	m_humidity = humidity;
	m_pressure = pressure;
	m_windSpeed = windSpeed;
	m_windDirection = windDirection;

	MeasurementsChanged();
}

SWeatherInfo CWeatherData::GetChangedData() const
{
	SWeatherInfo info;
	info.temperature = m_temperature;
	info.humidity = m_humidity;
	info.pressure = m_pressure;
	info.windSpeed = m_windSpeed;
	info.windDirection = m_windDirection;
	return info;
}