#pragma once
#include <boost/noncopyable.hpp>
#include "OutsideWeatherData.h"
#include "StatsData.h"

class CWindDirectionData
{	
public:
	void Update(double value);
	void Display() const;

	double GetAverage() const;

private:
	double m_average = 0;
	double m_x = 0;
	double m_y = 0;
};

class COutsideStatsDisplay : boost::noncopyable
{
public:
	COutsideStatsDisplay(COutsideWeatherData& cr);
	void Display();

protected:
	CStatsData m_temperature;
	CStatsData m_humidity;
	CStatsData m_pressure;
	CStatsData m_windSpeed;
	CWindDirectionData m_windDirection;

private:
	void OnTemperatureChange(double temperature);
	void OnHumidityChange(double humidity);
	void OnPressureChange(double pressure);
	void OnWindSpeedChange(double windSpeed);
	void OnWindDirectionChange(double windDirection);

	signals::scoped_connection m_temperatureChangeConnection;
	signals::scoped_connection m_humidityChangeConnection;
	signals::scoped_connection m_pressureChangeConnection;
	signals::scoped_connection m_windSpeedChangeConnection;
	signals::scoped_connection m_windDirectionChangeConnection;
};