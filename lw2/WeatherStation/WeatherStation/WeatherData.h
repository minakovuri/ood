#pragma once
#include <set>
#include <map>
#include "IObserver.h"
#include "ISubject.h"

struct SWeatherInfo
{
	float temperature = 0;
	float humidity = 0;
	float pressure = 0;
};

typedef IObserver<SWeatherInfo> WeatherObserver;

class CWeatherData : public ISubject<SWeatherInfo>
{
public:
	void RegisterObserver(WeatherObserver& observerRef) override;
	void RemoveObserver(WeatherObserver& observerRef) override;
	void NotifyObservers() override;

	void MeasurementsChanged();
	void SetMeasurements(float temperature, float humidity, float pressure);

private:
	std::set<WeatherObserver*> m_observers;

	float m_temperature = 0;
	float m_humidity = 0;
	float m_pressure = 0;

	SWeatherInfo GetChangedData() const;
};

class CWeatherPrioritiesData : public IPrioritySubject<SWeatherInfo>
{
	void RegisterObserver(WeatherObserver& observerRef, unsigned int priority = 0) override;
	void RemoveObserver(WeatherObserver& observerRef) override;
	void NotifyObservers() override;

	void MeasurementsChanged();
	void SetMeasurements(float temperature, float humidity, float pressure);

private:
	std::multimap<unsigned int, WeatherObserver*> m_observersPriority;

	float m_temperature = 0;
	float m_humidity = 0;
	float m_pressure = 0;

	SWeatherInfo GetChangedData() const;
};