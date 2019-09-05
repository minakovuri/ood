#pragma once
#include "../../WeatherStation/WeatherData.h"
#include <string>
#include <vector>

class MockWeatherPrioritiesData : public CWeatherPrioritiesData
{
public:
	void WriteObserverName(std::string& const name)
	{
		names.push_back(name);
	}

private:
	std::vector<std::string> names;
};