#include "InsideWeatherData.h"

signals::connection CInsideWeatherData::DoOnDataChange(const DataChangeSignal::slot_type& slot)
{
	return m_weatherChangeSignal.connect(slot);
}

SInsideWeatherInfo CInsideWeatherData::GetData() const
{
	SInsideWeatherInfo info;
	info.temperature = m_temperature;
	info.humidity = m_humidity;
	info.pressure = m_pressure;
	return info;
}

void CInsideWeatherData::MeasurementsChanged()
{
	SInsideWeatherInfo data = GetData();
	m_weatherChangeSignal(data);
}

void CInsideWeatherData::SetMeasurements(double temperature, double humidity, double pressure)
{
	m_temperature = temperature;
	m_humidity = humidity;
	m_pressure = pressure;

	MeasurementsChanged();
}
