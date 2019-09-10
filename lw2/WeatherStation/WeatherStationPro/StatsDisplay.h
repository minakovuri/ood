#pragma once
#include <set>
#include "IDisplayElement.h"
#include "IObserver.h"
#include "IObservable.h"
#include "WeatherData.h"
#include "StatsData.h"

enum class EventType
{
	temperature,
	humidity,
	pressure, 
	windSpeed,
	windDirection,
};

class CStatsDisplay
	: virtual public IObserver<SWeatherInfo>
	, virtual public IDisplayElement
{
public:
	CStatsDisplay(IObservable<SWeatherInfo>& weatherDataRef);

	void Update(SWeatherInfo const& data) override;
	void Display() override;

	void SubscribeToUpdates(EventType eventType);
	void UnsubscribeFromUpdates(EventType eventType);

	Stats GetTemperatureStats() const;
	Stats GetHumidityStats() const;
	Stats GetPressureStats() const;
	Stats GetWindSpeedStats() const;
	double GetAverageWindDirection() const;

private:
	CStatsData m_temperature;
	CStatsData m_humidity;
	CStatsData m_pressure;
	CStatsData m_windSpeed;
	CWindDirectionData m_windDirection;

	std::set<EventType> m_eventTypes;
};