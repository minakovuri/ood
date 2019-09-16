#include "OutsideStatsDisplay.h"
#include <iostream>

COutsideStatsDisplay::COutsideStatsDisplay(ObservableType& weatherDataRef)
{
	weatherDataRef.RegisterObserver(*this);
	m_observables.insert(&weatherDataRef);
}

void COutsideStatsDisplay::Update(SOutsideWeatherInfo const& data)
{
	m_temperature.Update(data.temperature);
	m_humidity.Update(data.humidity);
	m_pressure.Update(data.pressure);
	m_windSpeed.Update(data.windSpeed);
	m_windDirection.Update(data.windDirection);

	Display();
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

Stats COutsideStatsDisplay::GetTemperatureStats() const
{
	return m_temperature.GetStats();
}

Stats COutsideStatsDisplay::GetHumodityStats() const
{
	return m_humidity.GetStats();
}

Stats COutsideStatsDisplay::GetPressureStats() const
{
	return m_pressure.GetStats();
}

Stats COutsideStatsDisplay::GetWindSpeedStats() const
{
	return m_windSpeed.GetStats();
}

double COutsideStatsDisplay::GetAverageWindDirection() const
{
	return m_windDirection.GetAverage();
}

COutsideStatsDisplay::~COutsideStatsDisplay()
{
	for (auto& observable : m_observables)
	{
		observable->RemoveObserver(*this);
	}
}