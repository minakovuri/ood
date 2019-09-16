#pragma once
#include "EventType.h"

class IObserver
{
public:
	virtual void UpdateTemperature(double temperature) = 0;
	virtual void UpdateHumidity(double humidity) = 0;
	virtual void UpdatePressure(double pressure) = 0;
	virtual void UpdateWindSpeed(double windSpeed) = 0;
	virtual void UpdateWindDirection(double windDirection) = 0;

	virtual ~IObserver() = default;
};