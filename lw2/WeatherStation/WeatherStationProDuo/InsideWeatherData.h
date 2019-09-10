#pragma once
#include <set>
#include <map>
#include "IObservable.h"
#include "IObserver.h"

struct SInsideWeatherInfo
{
	double temperature = 0;
	double humidity = 0;
	double pressure = 0;
};

typedef IObserver<SInsideWeatherInfo> InsideWeatherObserver;

class CInsideWeatherData : public IObservable<SInsideWeatherInfo>
{
public:
	void RegisterObserver(InsideWeatherObserver& observerRef, unsigned int priority = 0) override;
	void RemoveObserver(InsideWeatherObserver& observerRef) override;
	void NotifyObservers() override;

	void MeasurementsChanged();
	void SetMeasurements(double temperature, double humidity, double pressure);

private:
	std::multimap<unsigned int, InsideWeatherObserver*> m_observers;

	double m_temperature = 0;
	double m_humidity = 0;
	double m_pressure = 0;

	SInsideWeatherInfo GetChangedData() const;
};