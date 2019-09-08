#include "StatsDisplay.h"
#include <iostream>

CStatsDisplay::CStatsDisplay(ISubject<SWeatherInfo>& in, ISubject<SWeatherInfo>& out)
	: m_in(in)
	, m_out(out)
{
	in.RegisterObserver(*this);
	out.RegisterObserver(*this);
}

void CStatsDisplay::Update(SWeatherInfo const& data, ISubject<SWeatherInfo>& subject)
{
	if (&subject == &m_in)
	{
		m_inTemperature.Update(data.temperature);
		m_inHumidity.Update(data.humidity);
		m_inPressure.Update(data.pressure);
	}
	else if (&subject == &m_out)
	{
		m_outTemperature.Update(data.temperature);
		m_outHumidity.Update(data.humidity);
		m_outPressure.Update(data.pressure);
	}

	Display();
}

void CStatsDisplay::Display()
{
	std::cout << "Weather data: \n";

	std::cout << "\t inside: " << std::endl;
	std::cout << "\t\t temperature: ";
	m_inTemperature.Display();
	std::cout << "\t\t humidity: ";
	m_inHumidity.Display();
	std::cout << "\t\t pressure: ";
	m_inPressure.Display();

	std::cout << "\t outside: " << std::endl;
	std::cout << "\t\t temperature: ";
	m_outTemperature.Display();
	std::cout << "\t\t humidity: ";
	m_outHumidity.Display();
	std::cout << "\t\t pressure: ";
	m_outPressure.Display();
}

Stats CStatsDisplay::GetInTemperatureStats() const
{
	return m_inTemperature.GetStats();
}

Stats CStatsDisplay::GetInHumidityStats() const
{
	return m_inHumidity.GetStats();
}

Stats CStatsDisplay::GetInPressureStats() const
{
	return m_inPressure.GetStats();
}

Stats CStatsDisplay::GetOutTemperatureStats() const
{
	return m_outTemperature.GetStats();
}

Stats CStatsDisplay::GetOutHumidityStats() const
{
	return m_outHumidity.GetStats();
}

Stats CStatsDisplay::GetOutPressureStats() const
{
	return m_outPressure.GetStats();
}