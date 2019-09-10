#pragma once
#include <set>
#include <map>
#include "IObserver.h"
#include "IObservable.h"

struct SOutsideWeatherInfo
{
	double temperature = 0;
	double humidity = 0;
	double pressure = 0;
	double windSpeed = 0;
	double windDirection = 0;
};

typedef IObserver<SOutsideWeatherInfo> OutsideWeatherObserver;

class COutsideWeatherData : public IObservable<SOutsideWeatherInfo>
{
public:
	void RegisterObserver(OutsideWeatherObserver& observerRef, unsigned int priority = 0) override;
	void RemoveObserver(OutsideWeatherObserver& observerRef) override;
	void NotifyObservers() override;

	void MeasurementsChanged();
	void SetMeasurements(double temperature, double humidity, double pressure, double windSpeed, double windDirection);

private:
	std::multimap<unsigned int, OutsideWeatherObserver*> m_observers;

	double m_temperature = 0;
	double m_humidity = 0;
	double m_pressure = 0;
	double m_windSpeed = 0;
	double m_windDirection = 0;

	SOutsideWeatherInfo GetChangedData() const;
};