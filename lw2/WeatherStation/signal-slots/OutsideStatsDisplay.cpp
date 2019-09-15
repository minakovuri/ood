#include "OutsideStatsDisplay.h"
#include <iostream>

COutsideStatsDisplay::COutsideStatsDisplay(Observable& cr)
{
	m_statsChangeConnection = cr.DoOnDataChange([this](SOutsideWeatherInfo stats) {
		OnStatsChange(stats);
	});
}

void COutsideStatsDisplay::Display()
{
	std::cout << "Outside stats data: \n";
	std::cout << "\t temperature: ";
	m_temperature.Display();
	std::cout << "\t humidity: ";
	m_humidity.Display();
	std::cout << "\t pressure: ";
	m_pressure.Display();
	std::cout << "\t wind speed: ";
	m_windSpeed.Display();
	std::cout << "\t wind direction: ";
	m_windDirection.Display();
}

Stats COutsideStatsDisplay::GetTemperatureStats() const
{
	return m_temperature.GetStats();
}

Stats COutsideStatsDisplay::GetHumodityStats() const
{
	return m_humidity.GetStats();
}

Stats COutsideStatsDisplay::GetPressureStats() const
{
	return m_pressure.GetStats();
}

Stats COutsideStatsDisplay::GetWindSpeedStats() const
{
	return m_windSpeed.GetStats();
}

double COutsideStatsDisplay::GetAverageWindDirection() const
{
	return m_windDirection.GetAverage();
}

void COutsideStatsDisplay::OnStatsChange(SOutsideWeatherInfo stats)
{
	m_temperature.Update(stats.temperature);
	m_humidity.Update(stats.humidity);
	m_pressure.Update(stats.pressure);
	m_windSpeed.Update(stats.windSpeed);
	m_windDirection.Update(stats.windDirection);

	Display();
}