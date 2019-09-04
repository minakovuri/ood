#include "WeatherData.h"
#include "ConditionDisplay.h"

int main()
{
	CWeatherData weatherData;

	ConditionDisplay conditionDisplay(weatherData);

	weatherData.NotifyObservers();

	weatherData.SetMeasurements(10, 20, 30);

	return 0;
}
