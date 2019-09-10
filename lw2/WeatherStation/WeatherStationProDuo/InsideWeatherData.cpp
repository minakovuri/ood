#include "InsideWeatherData.h"

void CInsideWeatherData::RegisterObserver(InsideWeatherObserver& observerRef, unsigned int priority)
{
	m_observers.emplace(priority, &observerRef);
}

void CInsideWeatherData::RemoveObserver(InsideWeatherObserver& observerRef)
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

void CInsideWeatherData::NotifyObservers()
{
	SInsideWeatherInfo data = GetChangedData();

	auto priorities(m_observers);

	for (auto priority : priorities)
	{
		priority.second->Update(data);
	}
}

void CInsideWeatherData::MeasurementsChanged()
{
	NotifyObservers();
}

void CInsideWeatherData::SetMeasurements(double temperature, double humidity, double pressure)
{
	m_temperature = temperature;
	m_humidity = humidity;
	m_pressure = pressure;

	MeasurementsChanged();
}

SInsideWeatherInfo CInsideWeatherData::GetChangedData() const
{
	SInsideWeatherInfo info;
	info.temperature = m_temperature;
	info.humidity = m_humidity;
	info.pressure = m_pressure;
	return info;
}