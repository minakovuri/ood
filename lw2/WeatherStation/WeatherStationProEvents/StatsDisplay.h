#pragma once
#include <set>
#include "IObserver.h"
#include "WeatherData.h"
#include "StatsData.h"

class CStatsDisplay : virtual public IObserver
{
public:
	CStatsDisplay(IObserver& observerRef);

	void UpdateTemperature(double temperature); 
	void UpdateHumidity(double humidity);
	void UpdatePressure(double pressure);
	void UpdateWindSpeed(double windSpeed);
	void UpdateWindDirection(double windDirection);

	void DisplayTemperature();
	void DisplayHumidity();
	void DisplayPressure();
	void DisplayWindSpeed();
	void DisplayWindDirection();

	Stats GetTemperatureStats() const;
	Stats GetHumidityStats() const;
	Stats GetPressureStats() const;
	Stats GetWindSpeedStats() const;
	double GetAverageWindDirection() const;

	~CStatsDisplay();

private:
	CStatsData m_temperature;
	CStatsData m_humidity;
	CStatsData m_pressure;
	CStatsData m_windSpeed;
	CWindDirectionData m_windDirection;


	std::set<IObservable*> m_observables;
};