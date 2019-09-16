#include "OutsideStatsDisplay.h"
#include <iostream>

COutsideStatsDisplay::COutsideStatsDisplay(COutsideWeatherData& cr)
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

	m_windSpeedChangeConnection = cr.DoOnWindSpeedChange([this](double windSpeed) {
		OnWindSpeedChange(windSpeed);
	});

	m_windDirectionChangeConnection = cr.DoOnWindDirectionChange([this](double windDirection) {
		OnWindDirectionChange(windDirection);
	});
}

void COutsideStatsDisplay::Display()
{
	std::cout << "Outside stats data: \n";
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

void COutsideStatsDisplay::OnTemperatureChange(double temperature)
{
	m_temperature.Update(temperature);
}

void COutsideStatsDisplay::OnHumidityChange(double humidity)
{
	m_humidity.Update(humidity);
}

void COutsideStatsDisplay::OnPressureChange(double pressure)
{
	m_pressure.Update(pressure);
}

void COutsideStatsDisplay::OnWindSpeedChange(double windSpeed)
{
	m_windSpeed.Update(windSpeed);
}

void COutsideStatsDisplay::OnWindDirectionChange(double windDirection)
{
	m_windDirection.Update(windDirection);
}