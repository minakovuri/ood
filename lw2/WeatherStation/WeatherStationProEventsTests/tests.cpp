#include "MockDisplay.h"
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

TEST_CASE("Test subscription and unsubscription from events")
{
	CWeatherData weatherData;
	CMockStatsDisplay statsDisplay(weatherData);

	weatherData.SubscribeToEvent(statsDisplay, EventType::Temperature);
	weatherData.SubscribeToEvent(statsDisplay, EventType::Humidity);
	weatherData.SubscribeToEvent(statsDisplay, EventType::Pressure);

	weatherData.SetMeasurements(-12.5, 56, 631, 20, 92);

	CHECK(IsStatsEqual(statsDisplay.GetTemperatureStats(), Stats{ -12.5, -12.5, -12.5 }));
	CHECK(IsStatsEqual(statsDisplay.GetHumidityStats(), Stats{ 56, 56, 56.0 }));
	CHECK(IsStatsEqual(statsDisplay.GetPressureStats(), Stats{ 631.0, 631.0, 631.0 }));
	CHECK(IsStatsEqual(statsDisplay.GetWindSpeedStats(), Stats{ -DBL_MAX, DBL_MAX, 0 }));
	CHECK(statsDisplay.GetAverageWindDirection() == 0);

	weatherData.UnsubscribeFromEvent(statsDisplay, EventType::Temperature);
	weatherData.UnsubscribeFromEvent(statsDisplay, EventType::Humidity);
	weatherData.SubscribeToEvent(statsDisplay, EventType::WindSpeed);
	weatherData.SubscribeToEvent(statsDisplay, EventType::WindDirection);

	weatherData.SetMeasurements(20.2, 63, 751, 5.6, 301);

	CHECK(IsStatsEqual(statsDisplay.GetTemperatureStats(), Stats{ -12.5, -12.5, -12.5 }));
	CHECK(IsStatsEqual(statsDisplay.GetHumidityStats(), Stats{ 56, 56, 56.0 }));
	CHECK(IsStatsEqual(statsDisplay.GetPressureStats(), Stats{ 631.0, 751, (631.0 + 751.0) / 2 }));
	CHECK(IsStatsEqual(statsDisplay.GetWindSpeedStats(), Stats{ 5.6, 5.6, 5.6 }));
	CHECK(fabs(statsDisplay.GetAverageWindDirection() - 301) < FLT_EPSILON);

	{
		CMockStatsDisplay statsDisplay2(weatherData);

		weatherData.SubscribeToEvent(statsDisplay2, EventType::Temperature);
		weatherData.SubscribeToEvent(statsDisplay2, EventType::Temperature);

		weatherData.SetMeasurements(15.1, 52, 744, 3.4, 145);

		CHECK(IsStatsEqual(statsDisplay2.GetTemperatureStats(), Stats{ 15.1, 15.1, 15.1 }));
	}

	weatherData.SetMeasurements(2.2, 61, 730, 4.4, 16);
}