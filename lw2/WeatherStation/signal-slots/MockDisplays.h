#pragma once
#include "InsideStatsDisplay.h"
#include "OutsideStatsDisplay.h"

class CMockInsideStatsDisplay : public CInsideStatsDisplay
{
public:
	CMockInsideStatsDisplay(CInsideWeatherData& wd)
		: CInsideStatsDisplay(wd)
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
};

class CMockOutsideStatsDisplay : public COutsideStatsDisplay
{
public:
	CMockOutsideStatsDisplay(COutsideWeatherData& wd)
		: COutsideStatsDisplay(wd)
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