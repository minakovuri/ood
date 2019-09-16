#pragma once
#include "../WeatherStationProEvents/StatsDisplay.h"

class CMockStatsDisplay : public CStatsDisplay
{
public:
	CMockStatsDisplay(IObservable& observableRef)
		: CStatsDisplay(observableRef)
	{
	}

	Stats GetTemperatureStats() const
	{
		return m_temperature.GetStats();
	}

	Stats GetHumidityStats() const
	{
		return m_humidity.GetStats();
	}

	Stats GetPressureStats() const
	{
		return m_pressure.GetStats();
	}

	Stats GetWindSpeedStats() const
	{
		return m_windSpeed.GetStats();
	}

	double GetAverageWindDirection() const
	{
		return m_windDirection.GetAverage();
	}
};