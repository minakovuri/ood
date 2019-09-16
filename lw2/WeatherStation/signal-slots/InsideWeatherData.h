#pragma once
#include <boost/signals2.hpp>

namespace signals = boost::signals2;

struct SInsideWeatherInfo
{
	double temperature = 0;
	double humidity = 0;
	double pressure = 0;
};

class CInsideWeatherData
{
public:
	using TemperatureChangeSignal = signals::signal<void(double temperature)>;
	using HumidityChangeSignal = signals::signal<void(double humidity)>;
	using PressureChangeSignal = signals::signal<void(double pressure)>;

	signals::connection DoOnTemperatureChange(const TemperatureChangeSignal::slot_type& slot);
	signals::connection DoOnHumidityChange(const HumidityChangeSignal::slot_type& slot);
	signals::connection DoOnPressureChange(const PressureChangeSignal::slot_type& slot);

	void SetMeasurements(double temperature, double humidity, double pressure);

private:
	double m_temperature = 0;
	double m_humidity = 0;
	double m_pressure = 0;
	
	TemperatureChangeSignal m_temperatureChangeSignal;
	HumidityChangeSignal m_humidityChangeSignal;
	PressureChangeSignal m_pressureChangeSignal;
};