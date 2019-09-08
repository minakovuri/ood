#pragma once
#include <set>
#include <map>
#include "IObserver.h"
#include "ISubject.h"

struct SWeatherInfo
{
	double temperature = 0;
	double humidity = 0;
	double pressure = 0;
	double windSpeed = 0;
	double windDirection = 0;
};

typedef IObserver<SWeatherInfo> WeatherObserver;

class CWeatherData : public ISubject<SWeatherInfo>
{
public:
	void RegisterObserver(WeatherObserver& observerRef, unsigned int priority = 0) override;
	void RemoveObserver(WeatherObserver& observerRef) override;
	void NotifyObservers() override;

	void MeasurementsChanged();
	void SetMeasurements(double temperature, double humidity, double pressure, double windSpeed, double windDirection);

private:
	std::multimap<unsigned int, WeatherObserver*> m_observersPriority;

	double m_temperature = 0;
	double m_humidity = 0;
	double m_pressure = 0;
	double m_windSpeed = 0;
	double m_windDirection = 0;

	SWeatherInfo GetChangedData() const;
};