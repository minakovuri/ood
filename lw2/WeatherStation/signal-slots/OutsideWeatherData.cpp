#include "OutsideWeatherData.h"

signals::connection COutsideWeatherData::DoOnDataChange(const DataChangeSignal::slot_type& slot)
{
	return m_weatherChangeSignal.connect(slot);
}

SOutsideWeatherInfo COutsideWeatherData::GetData() const
{
	SOutsideWeatherInfo info;
	info.temperature = m_temperature;
	info.humidity = m_humidity;
	info.pressure = m_pressure;
	info.windSpeed = m_windSpeed;
	info.windDirection = m_windDirection;
	return info;
}

void COutsideWeatherData::MeasurementsChanged()
{
	SOutsideWeatherInfo data = GetData();
	m_weatherChangeSignal(data);
}

void COutsideWeatherData::SetMeasurements(double temperature, double humidity, double pressure, double windSpeed, double windDirection)
{
	m_temperature = temperature;
	m_humidity = humidity;
	m_pressure = pressure;
	m_windSpeed = windSpeed;
	m_windDirection = windDirection;

	MeasurementsChanged();
}