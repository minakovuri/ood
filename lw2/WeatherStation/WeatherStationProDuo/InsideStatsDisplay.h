#pragma once
#include "IDisplayElement.h"
#include "IObserver.h"
#include "IObservable.h"
#include "InsideWeatherData.h"
#include "StatsData.h"

class CInsideStatsDisplay
	: private IObserver<SInsideWeatherInfo>
	, public IDisplayElement
{
public:
	CInsideStatsDisplay(IObservable<SInsideWeatherInfo>& weatherDataRef);

	void Update(SInsideWeatherInfo const& data) override;
	void Display() override;

	Stats GetTemperatureStats() const;
	Stats GetHumodityStats() const;
	Stats GetPressureStats() const;

private:
	CStatsData m_temperature;
	CStatsData m_humidity;
	CStatsData m_pressure;
};