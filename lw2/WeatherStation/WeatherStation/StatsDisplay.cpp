#include "StatsDisplay.h"
#include <iostream>

void CStatsDisplay::CStatsHandler::Update(float value)
{
	if (value < m_min)
	{
		m_min = value;
	}

	if (value > m_max)
	{
		m_max = value;
	}

	m_average = (m_sum += value) / ++m_counts;
}

void CStatsDisplay::CStatsHandler::Display()
{
	std::cout << "min: " << m_min << ", "
			  << "max: " << m_max << ", "
			  << "average: " << m_average << "\n";
}

Stats CStatsDisplay::CStatsHandler::GetStats() const
{
	Stats stats;
	stats.min = m_min;
	stats.max = m_max;
	stats.average = m_average;
	return stats;
}

CStatsDisplay::CStatsDisplay(ISubject<SWeatherInfo>& weatherDataRef)
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