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

TEST_CASE("Test dual displays with signal-slots impl")
{
	CInsideWeatherData insideWeatherData;
	COutsideWeatherData outsideWeatherData;

	CMockInsideStatsDisplay insideStatsDisplay(insideWeatherData);
	CMockOutsideStatsDisplay outsideStatsDisplay(outsideWeatherData);

	insideWeatherData.SetMeasurements(10.2, 60, 700);
	insideWeatherData.SetMeasurements(5.5, 56, 630);

	outsideWeatherData.SetMeasurements(-12.5, 56, 631, 20, 92);
	outsideWeatherData.SetMeasurements(20.2, 63, 751, 5.6, 301);

	insideStatsDisplay.Display();
	outsideStatsDisplay.Display();

	CHECK(IsStatsEqual(insideStatsDisplay.GetTemperatureStats(), Stats{ 5.5, 10.2, (10.2 + 5.5) / 2 }));
	CHECK(IsStatsEqual(insideStatsDisplay.GetHumidityStats(), Stats{ 56, 60, (56.0 + 60.0) / 2 }));
	CHECK(IsStatsEqual(insideStatsDisplay.GetPressureStats(), Stats{ 630, 700, (630.0 + 700.0) / 2 }));

	CHECK(IsStatsEqual(outsideStatsDisplay.GetTemperatureStats(), Stats{ -12.5, 20.2, (20.2 - 12.5) / 2 }));
	CHECK(IsStatsEqual(outsideStatsDisplay.GetHumidityStats(), Stats{ 56, 63, (56.0 + 63.0) / 2 }));
	CHECK(IsStatsEqual(outsideStatsDisplay.GetPressureStats(), Stats{ 631, 751, (631.0 + 751.0) / 2 }));
	CHECK(IsStatsEqual(outsideStatsDisplay.GetWindSpeedStats(), Stats{ 5.6, 20, (20.0 + 5.6) / 2 }));
	CHECK(fabs(outsideStatsDisplay.GetAverageWindDirection() - 16.5) < FLT_EPSILON);
}