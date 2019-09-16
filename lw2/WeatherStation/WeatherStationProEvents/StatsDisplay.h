#pragma once
#include <set>
#include "IObserver.h"
#include "WeatherData.h"
#include "StatsData.h"

class CStatsDisplay : virtual public IObserver
{
public:
	CStatsDisplay(IObservable& observableRef);

	void UpdateTemperature(double temperature); 
	void UpdateHumidity(double humidity);
	void UpdatePressure(double pressure);
	void UpdateWindSpeed(double windSpeed);
	void UpdateWindDirection(double windDirection);

	void Display();

	~CStatsDisplay();

protected:
	CStatsData m_temperature;
	CStatsData m_humidity;
	CStatsData m_pressure;
	CStatsData m_windSpeed;
	CWindDirectionData m_windDirection;

private:
	IObservable* m_observable;
};