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

class CStatsDisplay
	: virtual public IObserver<SWeatherInfo>
	, virtual public IDisplayElement
{
public:
	CStatsDisplay(ISubject<SWeatherInfo>& in, ISubject<SWeatherInfo>& out);

	void Update(SWeatherInfo const& data, ISubject<SWeatherInfo>& subject) override;
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

	ISubject<SWeatherInfo>& m_in;
	ISubject<SWeatherInfo>& m_out;
};