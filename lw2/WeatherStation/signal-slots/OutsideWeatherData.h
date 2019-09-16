#pragma once
#include <boost/signals2.hpp>

namespace signals = boost::signals2;

struct SOutsideWeatherInfo
{
	double temperature = 0;
	double humidity = 0;
	double pressure = 0;
	double windSpeed = 0;
	double windDirection = 0;
};

class COutsideWeatherData
{
public:
	using TemperatureChangeSignal = signals::signal<void(double temperature)>;
	using HumidityChangeSignal = signals::signal<void(double humidity)>;
	using PressureChangeSignal = signals::signal<void(double pressure)>;
	using WindSpeedChangeSignal = signals::signal<void(double windSpeed)>;
	using WindDirectionChangeSignal = signals::signal<void(double windDirection)>;

	signals::connection DoOnTemperatureChange(const TemperatureChangeSignal::slot_type& slot);
	signals::connection DoOnHumidityChange(const HumidityChangeSignal::slot_type& slot);
	signals::connection DoOnPressureChange(const PressureChangeSignal::slot_type& slot);
	signals::connection DoOnWindSpeedChange(const WindSpeedChangeSignal::slot_type& slot);
	signals::connection DoOnWindDirectionChange(const WindDirectionChangeSignal::slot_type& slot);
	
	void SetMeasurements(double temperature, double humidity, double pressure, double windSpeed, double windDirection);

private:
	double m_temperature = 0;
	double m_humidity = 0;
	double m_pressure = 0;
	double m_windSpeed = 0;
	double m_windDirection = 0;

	TemperatureChangeSignal m_temperatureChangeSignal;
	HumidityChangeSignal m_humidityChangeSignal;
	PressureChangeSignal m_pressureChangeSignal;
	WindSpeedChangeSignal m_windSpeedChangeSignal;
	WindDirectionChangeSignal m_windDirectionChangeSignal;
};