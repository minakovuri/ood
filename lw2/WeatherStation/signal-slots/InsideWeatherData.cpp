#include "InsideWeatherData.h"

signals::connection CInsideWeatherData::DoOnTemperatureChange(const TemperatureChangeSignal::slot_type& slot)
{
	return m_temperatureChangeSignal.connect(slot);
}

signals::connection CInsideWeatherData::DoOnHumidityChange(const HumidityChangeSignal::slot_type& slot)
{
	return m_humidityChangeSignal.connect(slot);
}

signals::connection CInsideWeatherData::DoOnPressureChange(const PressureChangeSignal::slot_type& slot)
{
	return m_pressureChangeSignal.connect(slot);
}

void CInsideWeatherData::SetMeasurements(double temperature, double humidity, double pressure)
{
	if (m_temperature != temperature)
	{
		m_temperature = temperature;
		m_temperatureChangeSignal(temperature);
	}

	if (m_humidity != humidity)
	{
		m_humidity = humidity;
		m_humidityChangeSignal(humidity);
	}

	if (m_pressure != pressure)
	{
		m_pressure = pressure;
		m_pressureChangeSignal(pressure);
	}
}
