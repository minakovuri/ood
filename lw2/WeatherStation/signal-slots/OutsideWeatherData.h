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
	using DataChangeSignal = signals::signal<void(SOutsideWeatherInfo data)>;

	signals::connection DoOnDataChange(const DataChangeSignal::slot_type& slot);
	SOutsideWeatherInfo GetData() const;

	void MeasurementsChanged();
	void SetMeasurements(double temperature, double humidity, double pressure, double windSpeed, double windDirection);

private:
	double m_temperature = 0;
	double m_humidity = 0;
	double m_pressure = 0;
	double m_windSpeed = 0;
	double m_windDirection = 0;

	DataChangeSignal m_weatherChangeSignal;
};