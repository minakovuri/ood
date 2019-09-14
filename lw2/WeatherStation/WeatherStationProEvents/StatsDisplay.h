#pragma once
#include <set>
#include "IDisplayElement.h"
#include "IObserver.h"
#include "WeatherData.h"
#include "StatsData.h"

class CStatsDisplay
	: virtual public IObserver
	, virtual public IDisplayElement
{
public:
	void UpdateTemperature(double temperature); 
	void UpdateHumidity(double humidity);
	void UpdatePressure(double pressure);
	void UpdateWindSpeed(double windSpeed);
	void UpdateWindDirection(double windDirection);

	void DisplayTemperature() override;
	void DisplayHumidity() override;
	void DisplayPressure() override;
	void DisplayWindSpeed() override;
	void DisplayWindDirection() override;

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
};