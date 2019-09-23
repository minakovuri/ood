#include <iostream>
#include "StatsDisplay.h"

CStatsDisplay::CStatsDisplay(IObservable& observableRef)
	: m_observable(&observableRef)
{
}

void CStatsDisplay::UpdateTemperature(double temperature)
{
	m_temperature.Update(temperature);
}

void CStatsDisplay::UpdateHumidity(double humidity)
{
	m_humidity.Update(humidity);
}

void CStatsDisplay::UpdatePressure(double pressure)
{
	m_pressure.Update(pressure);
}

void CStatsDisplay::UpdateWindSpeed(double windSpeed)
{
	m_windSpeed.Update(windSpeed);
}

void CStatsDisplay::UpdateWindDirection(double windDirection)
{
	m_windDirection.Update(windDirection);
}

void CStatsDisplay::RemoveObservable()
{
	m_observable->RemoveObserver(*this);
}

void CStatsDisplay::Display()
{
	std::cout << "Stats data: \n";

	std::cout << "\t temperature: ";
	m_temperature.Display();
	
	std::cout << "\t humidity: ";
	m_humidity.Display();
	
	std::cout << "\t pressure: ";
	m_pressure.Display();
	
	std::cout << "\t wind speed: ";
	m_windSpeed.Display();
	
	std::cout << "\t wind direction: ";
	m_windDirection.Display();
	
}

CStatsDisplay::~CStatsDisplay()
{
	RemoveObservable();
}
