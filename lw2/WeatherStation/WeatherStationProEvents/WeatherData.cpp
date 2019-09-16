#include "WeatherData.h"

CWeatherData::CWeatherData()
{
	std::multimap<unsigned int, IObserver*> emptyMap;
	m_observers.insert(std::pair<EventType, std::multimap<unsigned int, IObserver*>>(EventType::Temperature, emptyMap));
	m_observers.insert(std::pair<EventType, std::multimap<unsigned int, IObserver*>>(EventType::Humidity, emptyMap));
	m_observers.insert(std::pair<EventType, std::multimap<unsigned int, IObserver*>>(EventType::Pressure, emptyMap));
	m_observers.insert(std::pair<EventType, std::multimap<unsigned int, IObserver*>>(EventType::WindSpeed, emptyMap));
	m_observers.insert(std::pair<EventType, std::multimap<unsigned int, IObserver*>>(EventType::WindDirection, emptyMap));
}

void CWeatherData::SubscribeToEvent(IObserver& observerRef, EventType eventType, unsigned int priority)
{
	auto eventTypeKey = m_observers.find(eventType);

	for (auto& priorityKey : eventTypeKey->second)
	{
		if ((priorityKey.first == priority) && (priorityKey.second == &observerRef))
		{
			return;
		}
	}

	eventTypeKey->second.emplace(priority, &observerRef);
}

void CWeatherData::UnsubscribeFromEvent(IObserver& observerRef, EventType eventType)
{
	auto it = m_observers.find(eventType);
	for (auto priority : it->second)
	{
		if (priority.second == &observerRef)
		{
			it->second.erase(priority.first);
			break;
		}
	}
}

void CWeatherData::RemoveObserver(IObserver& observerRef)
{
	for (auto& eventTypeKey : m_observers)
	{
		auto priorityKeys(eventTypeKey.second);

		for (auto& priorityKey : priorityKeys)
		{
			if (priorityKey.second == &observerRef)
			{
				eventTypeKey.second.erase(priorityKey.first);
			}
		}
	}
}

void CWeatherData::TemperatureChanged()
{
	auto iter = m_observers.find(EventType::Temperature);
	for (auto priority : iter->second)
	{
		priority.second->UpdateTemperature(m_temperature);
	}
}

void CWeatherData::HumidityChanged()
{
	auto iter = m_observers.find(EventType::Humidity);
	for (auto priority : iter->second)
	{
		priority.second->UpdateHumidity(m_humidity);
	}
}

void CWeatherData::PressureChanged()
{
	auto iter = m_observers.find(EventType::Pressure);
	for (auto priority : iter->second)
	{
		priority.second->UpdatePressure(m_pressure);
	}
}

void CWeatherData::WindSpeedChanged()
{
	auto iter = m_observers.find(EventType::WindSpeed);
	for (auto priority : iter->second)
	{
		priority.second->UpdateWindSpeed(m_windSpeed);
	}
}

void CWeatherData::WindDirectionChanged()
{
	auto iter = m_observers.find(EventType::WindDirection);
	for (auto priority : iter->second)
	{
		priority.second->UpdateWindDirection(m_windDirection);
	}
}

void CWeatherData::SetMeasurements(double temperature, double humidity, double pressure, double windSpeed, double windDirection)
{
	if (m_temperature != temperature)
	{
		m_temperature = temperature;
		TemperatureChanged();
	}

	if (m_humidity != humidity)
	{
		m_humidity = humidity;
		HumidityChanged();
	}

	if (m_pressure != pressure)
	{
		m_pressure = pressure;
		PressureChanged();
	}

	if (m_windSpeed != windSpeed)
	{
		m_windSpeed = windSpeed;
		WindSpeedChanged();
	}

	if (m_windDirection != windDirection)
	{
		m_windDirection = windDirection;
		WindDirectionChanged();
	}
}
