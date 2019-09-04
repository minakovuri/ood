#pragma once
#include <list>
#include "ISubject.h"
#include "IObserver.h"

struct SWeatherInfo
{
	float temperature = 0;
	float humidity = 0;
	float pressure = 0;
};

class CWeatherData : public ISubject<SWeatherInfo>
{
public:
	typedef IObserver<SWeatherInfo> WeatherObserver;

	void RegisterObserver(WeatherObserver& observerRef) override;
	void RemoveObserver(WeatherObserver& observerRef) override;
	void NotifyObservers() override;

	void MeasurementsChanged();
	void SetMeasurements(float temperature, float humidity, float pressure);
private:
	std::list<WeatherObserver*> m_observers;

	float m_temperature;
	float m_humidity;
	float m_pressure;

	SWeatherInfo GetChangedData() const;
};