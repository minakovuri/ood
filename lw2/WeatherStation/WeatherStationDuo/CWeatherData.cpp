#include "WeatherData.h"

void CWeatherData::RegisterObserver(InsideWeatherObserver& observerRef, unsigned int priority)
{
	m_observersPriority.emplace(priority, &observerRef);
}

void CWeatherData::RemoveObserver(InsideWeatherObserver& observerRef)
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
		priority.second->Update(data, *this);
	}
}

void CWeatherData::MeasurementsChanged()
{
	NotifyObservers();
}

void CWeatherData::SetMeasurements(double temperature, double humidity, double pressure)
{
	m_temperature = temperature;
	m_humidity = humidity;
	m_pressure = pressure;

	MeasurementsChanged();
}

SWeatherInfo CWeatherData::GetChangedData() const
{
	SWeatherInfo info;
	info.temperature = m_temperature;
	info.humidity = m_humidity;
	info.pressure = m_pressure;
	return info;
}