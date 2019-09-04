#include <iostream>
#include "ConditionDisplay.h"

ConditionDisplay::ConditionDisplay(ISubject<SWeatherInfo>& weatherDataRef)
	: m_temperature(0)
	, m_humidity(0)
	, m_pressure(0)
{
	weatherDataRef.RegisterObserver(*this);
}

void ConditionDisplay::Update(SWeatherInfo const& data)
{
	m_temperature = data.temperature;
	m_humidity = data.humidity;
	m_pressure = data.pressure;

	Display();
}

void ConditionDisplay::Display()
{
	std::cout << "Current conditions: \n"
			  << "\t temperature: " << m_temperature << " degrees;\n"
			  << "\t humidity: " << m_humidity << ";\n"
			  << "\t pressure: " << m_pressure << ";\n";
}