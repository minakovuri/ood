#pragma once
#include "IDisplayElement.h"
#include "IObserver.h"
#include "ISubject.h"
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
	double m_min = 0;
	double m_max = 0;
	double m_average = 0;
	double m_sum = 0;
	double m_counts = 0;
};

class CWindDirectionData
{	
public:
	void Update(double value);
	void Display() const;

	double GetAverage() const;

private:
	double m_average = 0;
	double m_x = 0;
	double m_y = 0;
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
	Stats GetWindSpeedStats() const;
	double GetAverageWindDirection() const;

private:
	CStatsData m_temperature;
	CStatsData m_humidity;
	CStatsData m_pressure;
	CStatsData m_windSpeed;
	CWindDirectionData m_windDirection;
};