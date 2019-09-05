#include <iostream>
#include "ConditionDisplay.h"

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