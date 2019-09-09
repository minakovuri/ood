#pragma once
#include <set>
#include <map>
#include "IObservable.h"
#include "IObserver.h"

struct SWeatherInfo
{
	double temperature = 0;
	double humidity = 0;
	double pressure = 0;
};

typedef IObserver<SWeatherInfo> WeatherObserver;

class CWeatherData : public IObservable<SWeatherInfo>
{
public:
	void RegisterObserver(WeatherObserver& observerRef, unsigned int priority = 0) override;
	void RemoveObserver(WeatherObserver& observerRef) override;
	void NotifyObservers() override;

	void MeasurementsChanged();
	void SetMeasurements(double temperature, double humidity, double pressure);

private:
	std::multimap<unsigned int, WeatherObserver*> m_observersPriority;

	double m_temperature = 0;
	double m_humidity = 0;
	double m_pressure = 0;

	SWeatherInfo GetChangedData() const;
};