#include "../WeatherStation/StatsDisplay.h"
#include "../WeatherStation/WeatherData.h"
#include "MockDisplays.h"
#include "catch.hpp"

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

TEST_CASE("Test IsStatsEqual function")
{
	Stats stats1 = Stats{ 0, 10, 5 };
	Stats stats2 = Stats{ 0, 10, 5 };
	Stats stats3 = Stats{ 0, 5, 2.5 };

	CHECK(IsStatsEqual(stats1, stats2));
	CHECK_FALSE(IsStatsEqual(stats1, stats3));
}

TEST_CASE("Test stats display")
{
	CWeatherData weatherData;

	CStatsDisplay statsDisplay(weatherData);

	Stats stats = statsDisplay.GetTemperatureStats();
	CHECK(IsStatsEqual(stats, Stats{ 0, 0, 0 }));

	stats = statsDisplay.GetHumodityStats();
	CHECK(IsStatsEqual(stats, Stats{ 0, 0, 0 }));

	stats = statsDisplay.GetPressureStats();
	CHECK(IsStatsEqual(stats, Stats{ 0, 0, 0 }));

	weatherData.SetMeasurements(10.2, 60, 700);

	stats = statsDisplay.GetTemperatureStats();
	CHECK(IsStatsEqual(stats, Stats{ 0, 10.2, 10.2 }));
}

TEST_CASE("Test subjects notify method when observer delete while updating")
{
	CWeatherData weatherData;

	MockDeleteDisplay mockObserver(weatherData);

	CHECK_NOTHROW(weatherData.NotifyObservers());
}