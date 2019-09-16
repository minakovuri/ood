#pragma once
#include "IObserver.h"
#include "IObservable.h"
#include "InsideWeatherData.h"
#include "StatsData.h"

class CInsideStatsDisplay : private IObserver<SInsideWeatherInfo>
{
public:
	typedef IObservable<SInsideWeatherInfo> ObservableType;

	CInsideStatsDisplay(ObservableType& weatherDataRef);

	void Update(SInsideWeatherInfo const& data) override;
	void Display();

	~CInsideStatsDisplay();

private:
	CStatsData m_temperature;
	CStatsData m_humidity;
	CStatsData m_pressure;

	ObservableType* m_observable;
};