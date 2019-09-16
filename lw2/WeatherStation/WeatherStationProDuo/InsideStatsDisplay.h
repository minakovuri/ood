#pragma once
#include "IObserver.h"
#include "IObservable.h"
#include "InsideWeatherData.h"
#include "StatsData.h"

class CInsideStatsDisplay : public IObserver<SInsideWeatherInfo>
{
public:
	typedef IObservable<SInsideWeatherInfo> ObservableType;

	CInsideStatsDisplay(ObservableType& weatherDataRef);

	void Update(SInsideWeatherInfo const& data) override;
	void Display();

	Stats GetTemperatureStats() const;
	Stats GetHumodityStats() const;
	Stats GetPressureStats() const;

	~CInsideStatsDisplay();

private:
	CStatsData m_temperature;
	CStatsData m_humidity;
	CStatsData m_pressure;

	std::set<ObservableType*> m_observables;
};