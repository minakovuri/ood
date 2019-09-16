#include "InsideStatsDisplay.h"
#include <iostream>

CInsideStatsDisplay::CInsideStatsDisplay(ObservableType& weatherDataRef)
{
	weatherDataRef.RegisterObserver(*this);
	m_observable = &weatherDataRef;
}

void CInsideStatsDisplay::Update(SInsideWeatherInfo const& data)
{
	m_temperature.Update(data.temperature);
	m_humidity.Update(data.humidity);
	m_pressure.Update(data.pressure);

	Display();
}

void CInsideStatsDisplay::Display()
{
	std::cout << "Inside stats data: \n";
	std::cout << "\t temperature: ";
	m_temperature.Display();
	std::cout << "\t humidity: ";
	m_humidity.Display();
	std::cout << "\t pressure: ";
	m_pressure.Display();
}

CInsideStatsDisplay::~CInsideStatsDisplay()
{
	m_observable->RemoveObserver(*this);
}