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
	using DataChangeSignal = signals::signal<void(SInsideWeatherInfo data)>;

	signals::connection DoOnDataChange(const DataChangeSignal::slot_type& slot);
	SInsideWeatherInfo GetData() const;

	void MeasurementsChanged();
	void SetMeasurements(double temperature, double humidity, double pressure);

private:
	double m_temperature = 0;
	double m_humidity = 0;
	double m_pressure = 0;

	DataChangeSignal m_weatherChangeSignal;
};