#include "WeatherData.h"
#include "StatsDisplay.h"
#include "ConditionDisplay.h"

int main()
{
	CWeatherData weatherData;

	CStatsDisplay statsDisplay(weatherData);

	weatherData.SetMeasurements(10.2, 60, 700);

	return 0;
}
