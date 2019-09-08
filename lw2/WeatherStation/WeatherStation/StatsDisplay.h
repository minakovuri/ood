#pragma once
#include "IDisplayElement.h"
#include "IObserver.h"
#include "ISubject.h"
#include "WeatherData.h"

struct Stats
{
	float min;
	float max;
	float average;
};

class CStatsData
{
public:
	void Update(float value);
	void Display();

	Stats GetStats() const;

private:
	float m_min = 0;
	float m_max = 0;
	float m_average = 0;
	float m_sum = 0;
	float m_counts = 0;
};

class CStatsDisplay
	: virtual public IObserver<SWeatherInfo>
	, virtual public IDisplayElement
{
public:
	CStatsDisplay(ISubject<SWeatherInfo>& weatherDataRef);

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