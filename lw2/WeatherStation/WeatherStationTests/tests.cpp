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

template <typename T>
bool IsVectorsEqual(std::vector<T>& const vec1, std::vector<T>& const vec2)
{
	return (vec1.size() == vec2.size()
		&& std::equal(vec1.begin(), vec1.end(), vec2.begin()));
}

TEST_CASE("Test IsStatsEqual function")
{
	CHECK(IsStatsEqual(Stats{ 0, 10, 5 }, Stats{ 0, 10, 5 }));
	CHECK_FALSE(IsStatsEqual(Stats{ -1, 2, 5 }, Stats{ 2, 2, 5 }));
	CHECK_FALSE(IsStatsEqual(Stats{ 0, 10, 5 }, Stats{ 0, 5, 2.5 }));
	CHECK_FALSE(IsStatsEqual(Stats{ 0, 10, 5 }, Stats{ 0, 10, 7 }));
}

TEST_CASE("Test IsVectorsEqual function")
{
	std::vector<std::string> vec1 = {
		"first",
		"second",
		"third",
	};

	std::vector<std::string> vec2 = {
		"first",
		"second",
		"third",
	};

	std::vector<std::string> vec3 = {
		"first",
		"second",
	};

	std::vector<std::string> vec4 = {
		"one",
		"two",
		"three",
	};

	CHECK(IsVectorsEqual(vec1, vec2));
	CHECK_FALSE(IsVectorsEqual(vec1, vec3));
	CHECK_FALSE(IsVectorsEqual(vec1, vec4));
}

TEST_CASE("Test stats display")
{
	CWeatherData weatherData;

	CStatsDisplay statsDisplay(weatherData);

	Stats stats = statsDisplay.GetTemperatureStats();
	CHECK(IsStatsEqual(stats, Stats{ -DBL_MAX, DBL_MAX, 0 }));

	stats = statsDisplay.GetHumodityStats();
	CHECK(IsStatsEqual(stats, Stats{ -DBL_MAX, DBL_MAX, 0 }));

	stats = statsDisplay.GetPressureStats();
	CHECK(IsStatsEqual(stats, Stats{ -DBL_MAX, DBL_MAX, 0 }));

	weatherData.SetMeasurements(10.2, 60, 700);

	stats = statsDisplay.GetTemperatureStats();
	CHECK(IsStatsEqual(stats, Stats{ 10.2, 10.2, 10.2 }));

	// TODO: добавить тесты для давления и влажности
}

TEST_CASE("Test subjects notify method when observer delete while updating")
{
	CWeatherData weatherData;

	MockDeleteDisplay mockObserver(weatherData);

	CHECK_NOTHROW(weatherData.NotifyObservers());
}

TEST_CASE("Test subject notify priority")
{
	CWeatherPrioritiesData weatherData;

	std::vector<std::string> priorities;

	MockPriorityObserver mockObserver1("first", &priorities);
	MockPriorityObserver mockObserver2("second", &priorities);
	MockPriorityObserver mockObserver3("third", &priorities);
	MockPriorityObserver mockObserver4("fourth", &priorities);

	weatherData.RegisterObserver(mockObserver1, 1);
	weatherData.RegisterObserver(mockObserver2, 2);
	weatherData.RegisterObserver(mockObserver3, 1);
	weatherData.RegisterObserver(mockObserver4, 3);

	weatherData.SetMeasurements(-10, 60, 700);

	std::vector<std::string> requredPriotities = {
		"first",
		"third",
		"second",
		"fourth",
	};

	CHECK(IsVectorsEqual(priorities, requredPriotities));

	weatherData.RemoveObserver(mockObserver1);
}