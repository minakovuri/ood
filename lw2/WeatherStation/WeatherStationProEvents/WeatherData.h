#pragma once
#include <map>
#include "IObservable.h"

class CWeatherData : public IObservable
{
public:
	CWeatherData();

	void SubscribeToEvent(IObserver& observerRef, EventType eventType, unsigned int priority = 0) override;
	void UnsubscribeFromEvent(IObserver& observerRef, EventType eventType) override;
	void RemoveObserver(IObserver& observerRef) override;

	void TemperatureChanged();
	void HumidityChanged();
	void PressureChanged();
	void WindSpeedChanged();
	void WindDirectionChanged();
	
	void SetMeasurements(double temperature, double humidity, double pressure, double windSpeed, double windDirection);

private:
	std::map<EventType, std::multimap<unsigned int, IObserver*>> m_observers;

	double m_temperature = 0;
	double m_humidity = 0;
	double m_pressure = 0;
	double m_windSpeed = 0;
	double m_windDirection = 0;
};