#include "StatsDisplay.h"
#include <iostream>

CStatsDisplay::CStatsDisplay(IObservable<SWeatherInfo>& weatherDataRef)
{
	m_eventTypes = {
		EventType::temperature,
		EventType::humidity,
		EventType::pressure,
		EventType::windSpeed,
		EventType::windDirection,
	};

	weatherDataRef.RegisterObserver(*this);
}

void CStatsDisplay::Update(SWeatherInfo const& data)
{
	if (m_eventTypes.count(EventType::temperature))
	{
		m_temperature.Update(data.temperature);
	}

	if (m_eventTypes.count(EventType::humidity))
	{
		m_humidity.Update(data.humidity);
	}

	if (m_eventTypes.count(EventType::pressure))
	{
		m_pressure.Update(data.pressure);
	}

	if (m_eventTypes.count(EventType::windSpeed))
	{
		m_windSpeed.Update(data.windSpeed);
	}

	if (m_eventTypes.count(EventType::windDirection))
	{
		m_windDirection.Update(data.windDirection);
	}

	Display();
}

void CStatsDisplay::Display()
{
	std::cout << "Stats data: \n";

	if (m_eventTypes.count(EventType::temperature))
	{
		std::cout << "\t temperature: ";
		m_temperature.Display();
	}

	if (m_eventTypes.count(EventType::humidity))
	{
		std::cout << "\t humidity: ";
		m_humidity.Display();
	}

	if (m_eventTypes.count(EventType::pressure))
	{
		std::cout << "\t pressure: ";
		m_pressure.Display();
	}

	if (m_eventTypes.count(EventType::windSpeed))
	{
		std::cout << "\t wind speed: ";
		m_windSpeed.Display();
	}

	if (m_eventTypes.count(EventType::windDirection))
	{
		std::cout << "\t wind direction: ";
		m_windDirection.Display();
	}
}

void CStatsDisplay::SubscribeToUpdates(EventType eventType)
{
	m_eventTypes.insert(eventType);
}

void CStatsDisplay::UnsubscribeFromUpdates(EventType eventType)
{
	m_eventTypes.erase(eventType);
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