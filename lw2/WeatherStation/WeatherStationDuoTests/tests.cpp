#include "catch.hpp"
#include "../WeatherStationDuo/WeatherData.h"
#include "../WeatherStationDuo/StatsDisplay.h"

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

TEST_CASE("Test observers that can handle data from inside and outside weather data")
{
	CWeatherData inWeatherData;
	CWeatherData outWeatherData;

	CStatsDisplay statsDisplay(inWeatherData, outWeatherData);

	inWeatherData.SetMeasurements(15.3, 70, 650);
	outWeatherData.SetMeasurements(20.7, 67, 600);

	inWeatherData.SetMeasurements(-8.4, 60, 613);
	outWeatherData.SetMeasurements(12.2, 56, 500);

	CHECK(IsStatsEqual(statsDisplay.GetInTemperatureStats(), Stats{ -8.4, 15.3, (15.3 - 8.4) / 2 }));
	CHECK(IsStatsEqual(statsDisplay.GetInHumidityStats(), Stats{ 0, 70.0, 65.0 }));
	CHECK(IsStatsEqual(statsDisplay.GetInPressureStats(), Stats{ 0, 650.0, (650.0 + 613.0) / 2}));

	CHECK(IsStatsEqual(statsDisplay.GetOutTemperatureStats(), Stats{ 0, 20.7, (20.7 + 12.2) / 2 }));
	CHECK(IsStatsEqual(statsDisplay.GetOutHumidityStats(), Stats{ 0, 67.0, (67.0 + 56.0) / 2 }));
	CHECK(IsStatsEqual(statsDisplay.GetOutPressureStats(), Stats{ 0, 600.0, (600.0 + 500.0) / 2 }));
}