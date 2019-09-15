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
	typedef COutsideWeatherData Observable;

	COutsideStatsDisplay(Observable& cr);
	void Display();

	Stats GetTemperatureStats() const;
	Stats GetHumodityStats() const;
	Stats GetPressureStats() const;
	Stats GetWindSpeedStats() const;
	double GetAverageWindDirection() const;

private:
	void OnStatsChange(SOutsideWeatherInfo stats);

	CStatsData m_temperature;
	CStatsData m_humidity;
	CStatsData m_pressure;
	CStatsData m_windSpeed;
	CWindDirectionData m_windDirection;

	signals::scoped_connection m_statsChangeConnection;
};