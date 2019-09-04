#pragma once
#include "IDisplayElement.h"
#include "IObserver.h"
#include "ISubject.h"
#include "WeatherData.h"

class ConditionDisplay
	: virtual public IObserver<SWeatherInfo>
	, virtual public IDisplayElement
{
public:
	ConditionDisplay(ISubject<SWeatherInfo>& weatherDataRef);

	void Update(SWeatherInfo const& data) override;
	void Display() override;

private:
	float m_temperature;
	float m_humidity;
	float m_pressure;
};