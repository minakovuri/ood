#include "InsideStatsDisplay.h"
#include <iostream>

CInsideStatsDisplay::CInsideStatsDisplay(Observable& cr)
{
	m_statsChangeConnection = cr.DoOnDataChange([this](SInsideWeatherInfo stats) {
		OnStatsChange(stats);
	});
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

void CInsideStatsDisplay::OnStatsChange(SInsideWeatherInfo stats)
{
	m_temperature.Update(stats.temperature);
	m_humidity.Update(stats.humidity);
	m_pressure.Update(stats.pressure);
	
	Display();
}