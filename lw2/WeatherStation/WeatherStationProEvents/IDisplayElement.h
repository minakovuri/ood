#pragma once

class IDisplayElement
{
public:
	virtual void DisplayTemperature() = 0;
	virtual void DisplayHumidity() = 0;
	virtual void DisplayPressure() = 0;
	virtual void DisplayWindSpeed() = 0;
	virtual void DisplayWindDirection() = 0;
};