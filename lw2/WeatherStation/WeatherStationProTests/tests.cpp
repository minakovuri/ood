#include "catch.hpp"
#include "../WeatherStationPro/StatsDisplay.h"
#include "../WeatherStationPro/WeatherData.h"

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

TEST_CASE("Test station work with wind speed and direction info")
{
	CWeatherData weatherData;

	CStatsDisplay statsDisplay(weatherData);

	weatherData.SetMeasurements(-12.5, 56, 631, 20, 92);
	weatherData.SetMeasurements(20.2, 63, 751, 5.6, 301);

	CHECK(IsStatsEqual(statsDisplay.GetTemperatureStats(), Stats{ -12.5, 20.2, (20.2 - 12.5) / 2 }));
	CHECK(IsStatsEqual(statsDisplay.GetHumodityStats(), Stats{ 0, 63, (56.0 + 63.0) / 2 }));
	CHECK(IsStatsEqual(statsDisplay.GetPressureStats(), Stats{ 0, 751, (631.0 + 751.0) / 2 }));
	CHECK(IsStatsEqual(statsDisplay.GetWindSpeedStats(), Stats{ 0, 20, (20.0 + 5.6) / 2 }));
	CHECK(fabs(statsDisplay.GetAverageWindDirection() - 16.5) < FLT_EPSILON);
}