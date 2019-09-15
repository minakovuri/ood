#pragma once
#include <boost/noncopyable.hpp>
#include "InsideWeatherData.h"
#include "StatsData.h"

class CInsideStatsDisplay : boost::noncopyable
{
public:
	typedef CInsideWeatherData Observable;

	CInsideStatsDisplay(Observable& cr);
	void Display();

	Stats GetTemperatureStats() const;
	Stats GetHumodityStats() const;
	Stats GetPressureStats() const;

private:
	void OnStatsChange(SInsideWeatherInfo stats);

	CStatsData m_temperature;
	CStatsData m_humidity;
	CStatsData m_pressure;

	signals::scoped_connection m_statsChangeConnection;
};