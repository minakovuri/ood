#include "StatsDisplay.h"
#include <iostream>

CStatsDisplay::CStatsDisplay(IObservable<SWeatherInfo>& weatherDataRef)
{
	weatherDataRef.RegisterObserver(*this);
}

void CStatsDisplay::Update(SWeatherInfo const& data)
{
	m_temperature.Update(data.temperature);
	m_humidity.Update(data.humidity);
	m_pressure.Update(data.pressure);

	Display();
}

void CStatsDisplay::Display()
{
	std::cout << "Stats data: \n";
	std::cout << "\t temperature: ";
	m_temperature.Display();
	std::cout << "\t humidity: ";
	m_humidity.Display();
	std::cout << "\t pressure: ";
	m_pressure.Display();
}

Stats CStatsDisplay::GetTemperatureStats() const
{
	return m_temperature.GetStats();
}

Stats CStatsDisplay::GetHumodityStats() const
{
	return m_humidity.GetStats();
}

Stats CStatsDisplay::GetPressureStats() const
{
	return m_pressure.GetStats();
}