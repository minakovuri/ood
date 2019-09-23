#pragma once
#include <set>
#include "IObserver.h"
#include "WeatherData.h"
#include "StatsData.h"

class CStatsDisplay : virtual public IObserver
{
public:
	CStatsDisplay(IObservable& observableRef);

	void UpdateTemperature(double temperature) final; 
	void UpdateHumidity(double humidity) final;
	void UpdatePressure(double pressure) final;
	void UpdateWindSpeed(double windSpeed) final;
	void UpdateWindDirection(double windDirection) final;

	void RemoveObservable() final;

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