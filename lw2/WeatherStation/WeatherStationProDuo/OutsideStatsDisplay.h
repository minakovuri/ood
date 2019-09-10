#pragma once
#include "IDisplayElement.h"
#include "IObserver.h"
#include "IObservable.h"
#include "OutsideWeatherData.h"
#include "StatsData.h"

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

class COutsideStatsDisplay
	: virtual public IObserver<SOutsideWeatherInfo>
	, virtual public IDisplayElement
{
public:
	COutsideStatsDisplay(IObservable<SOutsideWeatherInfo>& weatherDataRef);

	void Update(SOutsideWeatherInfo const& data) override;
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