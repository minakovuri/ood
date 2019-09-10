#include "WeatherData.h"

void CWeatherData::RegisterObserver(InsideWeatherObserver& observerRef)
{
	m_observers.insert(&observerRef);
}

void CWeatherData::RemoveObserver(InsideWeatherObserver& observerRef)
{
	m_observers.erase(&observerRef);
}

void CWeatherData::NotifyObservers()
{
	SWeatherInfo data = GetChangedData();

	auto observers(m_observers);

	for (auto& observer : observers)
	{
		observer->Update(data);
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