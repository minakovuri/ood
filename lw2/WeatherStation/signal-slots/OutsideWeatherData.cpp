#include "OutsideWeatherData.h"

signals::connection COutsideWeatherData::DoOnTemperatureChange(const TemperatureChangeSignal::slot_type& slot)
{
	return m_temperatureChangeSignal.connect(slot);
}

signals::connection COutsideWeatherData::DoOnHumidityChange(const HumidityChangeSignal::slot_type& slot)
{
	return m_humidityChangeSignal.connect(slot);
}

signals::connection COutsideWeatherData::DoOnPressureChange(const PressureChangeSignal::slot_type& slot)
{
	return m_pressureChangeSignal.connect(slot);
}

signals::connection COutsideWeatherData::DoOnWindSpeedChange(const WindSpeedChangeSignal::slot_type& slot)
{
	return m_windSpeedChangeSignal.connect(slot);
}

signals::connection COutsideWeatherData::DoOnWindDirectionChange(const WindDirectionChangeSignal::slot_type& slot)
{
	return m_windDirectionChangeSignal.connect(slot);
}

void COutsideWeatherData::SetMeasurements(double temperature, double humidity, double pressure, double windSpeed, double windDirection)
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

	if (m_windSpeed != windSpeed)
	{
		m_windSpeed = windSpeed;
		m_windSpeedChangeSignal(windSpeed);
	}

	if (m_windDirection != windDirection)
	{
		m_windDirection = windDirection;
		m_windDirectionChangeSignal(windDirection);
	}
}