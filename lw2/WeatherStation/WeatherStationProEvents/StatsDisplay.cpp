#include "StatsDisplay.h"

void CStatsDisplay::UpdateTemperature(double temperature)
{
	m_temperature.Update(temperature);
}

void CStatsDisplay::UpdateHumidity(double humidity)
{
	m_humidity.Update(humidity);
}

void CStatsDisplay::UpdatePressure(double pressure)
{
	m_pressure.Update(pressure);
}

void CStatsDisplay::UpdateWindSpeed(double windSpeed)
{
	m_windSpeed.Update(windSpeed);
}

void CStatsDisplay::UpdateWindDirection(double windDirection)
{
	m_windDirection.Update(windDirection);
}

void CStatsDisplay::DisplayTemperature()
{
	m_temperature.Display();
}

void CStatsDisplay::DisplayHumidity()
{
	m_humidity.Display();
}

void CStatsDisplay::DisplayPressure()
{
	m_pressure.Display();
}

void CStatsDisplay::DisplayWindSpeed()
{
	m_windSpeed.Display();
}

void CStatsDisplay::DisplayWindDirection()
{
	m_windDirection.Display();
}

Stats CStatsDisplay::GetTemperatureStats() const
{
	return m_temperature.GetStats();
}

Stats CStatsDisplay::GetHumidityStats() const
{
	return m_humidity.GetStats();
}

Stats CStatsDisplay::GetPressureStats() const
{
	return m_pressure.GetStats();
}

Stats CStatsDisplay::GetWindSpeedStats() const
{
	return m_windSpeed.GetStats();
}

double CStatsDisplay::GetAverageWindDirection() const
{
	return m_windDirection.GetAverage();
}