#pragma once
#include <float.h>

struct Stats
{
	double min;
	double max;
	double average;
};

class CStatsData
{
public:
	void Update(double value);
	void Display();

	Stats GetStats() const;

private:
	double m_min = -DBL_MAX;
	double m_max = DBL_MAX;
	double m_average = 0;
	double m_sum = 0;
	double m_counts = 0;
};

class CWindDirectionData
{
public:
	void Update(double value);
	void Display() const;

	double GetAverage() const;

private:
	double m_average = 0;
	double m_x = 0;
	double m_y = 0;
};