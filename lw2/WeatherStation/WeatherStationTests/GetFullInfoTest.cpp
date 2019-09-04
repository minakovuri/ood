#include "../WeatherStation/IObserver.h"
#include "../WeatherStation/WeatherData.h"
#include "catch.hpp"

class MockInfoDisplay : public IObserver<SWeatherInfo>
{
public:
	MockInfoDisplay(ISubject<SWeatherInfo>& weatherDataRef)
		: m_temperature(0)
		, m_humidity(0)
		, m_pressure(0)
	{
		weatherDataRef.RegisterObserver(*this);	
	}

	void Update(SWeatherInfo const& data)
	{
		m_temperature = data.temperature;
		m_humidity = data.humidity;
		m_pressure = data.pressure;
	}

	SWeatherInfo GetCurrentState()
	{
		SWeatherInfo info;
		info.temperature = m_temperature;
		info.humidity = m_humidity;
		info.pressure = m_pressure;
		return info;
	}

private:
	float m_temperature;
	float m_humidity;
	float m_pressure;
};

TEST_CASE("Get full info test")
{
	CWeatherData weatherData;

	MockInfoDisplay mockDisplay(weatherData);

	SWeatherInfo weatherInfo = mockDisplay.GetCurrentState();
	CHECK(weatherInfo.temperature == 0);
	CHECK(weatherInfo.humidity == 0);
	CHECK(weatherInfo.pressure == 0);

	weatherData.NotifyObservers();
	weatherInfo = mockDisplay.GetCurrentState();
	CHECK(weatherInfo.temperature == 0);
	CHECK(weatherInfo.humidity == 0);
	CHECK(weatherInfo.pressure == 0);

	weatherData.SetMeasurements(10, 20, 30);
	weatherInfo = mockDisplay.GetCurrentState();
	CHECK(weatherInfo.temperature == 10);
	CHECK(weatherInfo.humidity == 20);
	CHECK(weatherInfo.pressure == 30);
}