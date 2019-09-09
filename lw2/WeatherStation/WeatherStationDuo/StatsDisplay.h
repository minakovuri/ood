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
	double m_min = 0;
	double m_max = 0;
	double m_average = 0;
	double m_sum = 0;
	double m_counts = 0;
};

class CStatsDisplay
	: virtual public IObserver<SWeatherInfo>
	, virtual public IDisplayElement
{
public:
	CStatsDisplay(IObservable<SWeatherInfo>& in, IObservable<SWeatherInfo>& out);

	void Update(SWeatherInfo const& data, IObservable<SWeatherInfo>& subject) override;
	void Display() override;

	Stats GetInTemperatureStats() const;
	Stats GetInHumidityStats() const;
	Stats GetInPressureStats() const;

	Stats GetOutTemperatureStats() const;
	Stats GetOutHumidityStats() const;
	Stats GetOutPressureStats() const;

private:
	CStatsData m_inTemperature;
	CStatsData m_inHumidity;
	CStatsData m_inPressure;

	CStatsData m_outTemperature;
	CStatsData m_outHumidity;
	CStatsData m_outPressure;

	IObservable<SWeatherInfo>& m_in;
	IObservable<SWeatherInfo>& m_out;
};