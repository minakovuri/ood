#include "catch.hpp"
#include "../WeatherStationProDuo/InsideWeatherData.h"
#include "../WeatherStationProDuo/OutsideWeatherData.h"
#include "../WeatherStationProDuo/InsideStatsDisplay.h"
#include "../WeatherStationProDuo/OutsideStatsDisplay.h"

bool IsStatsEqual(Stats stats1, Stats stats2)
{
	if (stats1.min != stats2.min)
	{
		return false;
	}

	if (stats1.max != stats2.max)
	{
		return false;
	}

	if (stats1.average != stats2.average)
	{
		return false;
	}

	return true;
}

TEST_CASE("Test dual displays")
{
	CInsideWeatherData insideWeatherData;
	COutsideWeatherData outsideWeatherData;

	CInsideStatsDisplay insideStatsDisplay(insideWeatherData);
	COutsideStatsDisplay outsideStatsDisplay(outsideWeatherData);

	insideWeatherData.SetMeasurements(10.2, 60, 700);
	insideWeatherData.SetMeasurements(5.5, 56, 630);

	outsideWeatherData.SetMeasurements(-12.5, 56, 631, 20, 92);
	outsideWeatherData.SetMeasurements(20.2, 63, 751, 5.6, 301);
}