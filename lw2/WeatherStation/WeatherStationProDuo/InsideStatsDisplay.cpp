#include "InsideStatsDisplay.h"
#include <iostream>

CInsideStatsDisplay::CInsideStatsDisplay(IObservable<SInsideWeatherInfo>& weatherDataRef)
{
	weatherDataRef.RegisterObserver(*this);
}

void CInsideStatsDisplay::Update(SInsideWeatherInfo const& data)
{
	m_temperature.Update(data.temperature);
	m_humidity.Update(data.humidity);
	m_pressure.Update(data.pressure);

	Display();
}

void CInsideStatsDisplay::Display()
{
	std::cout << "Inside stats data: \n";
	std::cout << "\t temperature: ";
	m_temperature.Display();
	std::cout << "\t humidity: ";
	m_humidity.Display();
	std::cout << "\t pressure: ";
	m_pressure.Display();
}

Stats CInsideStatsDisplay::GetTemperatureStats() const
{
	return m_temperature.GetStats();
}

Stats CInsideStatsDisplay::GetHumodityStats() const
{
	return m_humidity.GetStats();
}

Stats CInsideStatsDisplay::GetPressureStats() const
{
	return m_pressure.GetStats();
}