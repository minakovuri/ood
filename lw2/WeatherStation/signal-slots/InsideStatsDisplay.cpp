#include "InsideStatsDisplay.h"
#include <iostream>

CInsideStatsDisplay::CInsideStatsDisplay(CInsideWeatherData& cr)
{
	m_temperatureChangeConnection = cr.DoOnTemperatureChange([this](double temperature) {
		OnTemperatureChange(temperature);
	});

	m_humidityChangeConnection = cr.DoOnHumidityChange([this](double humidity) {
		OnHumidityChange(humidity);
	});

	m_pressureChangeConnection = cr.DoOnPressureChange([this](double pressure) {
		OnPressureChange(pressure);
	});
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

void CInsideStatsDisplay::OnTemperatureChange(double temperature)
{
	m_temperature.Update(temperature);
}

void CInsideStatsDisplay::OnHumidityChange(double humidity)
{
	m_humidity.Update(humidity);
}

void CInsideStatsDisplay::OnPressureChange(double pressure)
{
	m_pressure.Update(pressure);
}
