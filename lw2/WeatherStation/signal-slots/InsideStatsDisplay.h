#pragma once
#include <boost/noncopyable.hpp>
#include "InsideWeatherData.h"
#include "StatsData.h"

class CInsideStatsDisplay : boost::noncopyable
{
public:
	CInsideStatsDisplay(CInsideWeatherData& cr);
	void Display();

protected:
	CStatsData m_temperature;
	CStatsData m_humidity;
	CStatsData m_pressure;

private:
	void OnTemperatureChange(double temperature);
	void OnHumidityChange(double humidity);
	void OnPressureChange(double pressure);

	signals::scoped_connection m_temperatureChangeConnection;
	signals::scoped_connection m_humidityChangeConnection;
	signals::scoped_connection m_pressureChangeConnection;
};