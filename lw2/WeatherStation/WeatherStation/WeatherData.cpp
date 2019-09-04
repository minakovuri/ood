#include "WeatherData.h"

void CWeatherData::RegisterObserver(CWeatherData::WeatherObserver& observerRef)
{
	m_observers.push_back(&observerRef);
}

void CWeatherData::RemoveObserver(CWeatherData::WeatherObserver& observerRef)
{
	m_observers.remove(&observerRef);
}

void CWeatherData::NotifyObservers()
{
	SWeatherInfo data = GetChangedData();
	for (auto& observer : m_observers)
	{
		observer->Update(data);
	}
}

void CWeatherData::MeasurementsChanged()
{
	NotifyObservers();
}

void CWeatherData::SetMeasurements(float temperature, float humidity, float pressure)
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