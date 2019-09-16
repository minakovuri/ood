#pragma once
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

class COutsideStatsDisplay : public IObserver<SOutsideWeatherInfo>
{
public:
	typedef IObservable<SOutsideWeatherInfo> ObservableType;

	COutsideStatsDisplay(ObservableType& weatherDataRef);

	void Update(SOutsideWeatherInfo const& data) override;
	void Display();

	Stats GetTemperatureStats() const;
	Stats GetHumodityStats() const;
	Stats GetPressureStats() const;
	Stats GetWindSpeedStats() const;
	double GetAverageWindDirection() const;

	~COutsideStatsDisplay();

private:
	CStatsData m_temperature;
	CStatsData m_humidity;
	CStatsData m_pressure;
	CStatsData m_windSpeed;
	CWindDirectionData m_windDirection;

	std::set<ObservableType*> m_observables;
};