#include "OutsideWeatherData.h"

void COutsideWeatherData::RegisterObserver(OutsideWeatherObserver& observerRef, unsigned int priority)
{
	m_observers.emplace(priority, &observerRef);
}

void COutsideWeatherData::RemoveObserver(OutsideWeatherObserver& observerRef)
{
	for (auto iterator = m_observers.begin(); iterator != m_observers.end(); ++iterator)
	{
		if (iterator->second == &observerRef)
		{
			m_observers.erase(iterator);
			break;
		}
	}
}

void COutsideWeatherData::NotifyObservers()
{
	SOutsideWeatherInfo data = GetChangedData();

	auto priorities(m_observers);

	for (auto priority : priorities)
	{
		priority.second->Update(data);
	}
}

void COutsideWeatherData::MeasurementsChanged()
{
	NotifyObservers();
}

void COutsideWeatherData::SetMeasurements(double temperature, double humidity, double pressure, double windSpeed, double windDirection)
{
	m_temperature = temperature;
	m_humidity = humidity;
	m_pressure = pressure;
	m_windSpeed = windSpeed;
	m_windDirection = windDirection;

	MeasurementsChanged();
}

SOutsideWeatherInfo COutsideWeatherData::GetChangedData() const
{
	SOutsideWeatherInfo info;
	info.temperature = m_temperature;
	info.humidity = m_humidity;
	info.pressure = m_pressure;
	info.windSpeed = m_windSpeed;
	info.windDirection = m_windDirection;
	return info;
}