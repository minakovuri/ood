#pragma once
#include "IDisplayElement.h"
#include "IObserver.h"
#include "IObservable.h"
#include "WeatherData.h"

struct Stats
{
	double min;
	double max;
	double average;
};

class CStatsData
{
public:
	void Update(double value);
	void Display();

	Stats GetStats() const;

private:
	double m_min = -DBL_MAX;
	double m_max = DBL_MAX;
	double m_average = 0;
	double m_sum = 0;
	double m_counts = 0;
};

class CStatsDisplay
	: private IObserver<SWeatherInfo>
	, public IDisplayElement
{
public:
	CStatsDisplay(IObservable<SWeatherInfo>& weatherDataRef);

	void Update(SWeatherInfo const& data) override;
	void Display() override;

	Stats GetTemperatureStats() const;
	Stats GetHumodityStats() const;
	Stats GetPressureStats() const;

private:
	CStatsData m_temperature;
	CStatsData m_humidity;
	CStatsData m_pressure;
};