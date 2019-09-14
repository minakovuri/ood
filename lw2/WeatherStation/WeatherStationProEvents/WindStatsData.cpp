#include "StatsData.h"
#define _USE_MATH_DEFINES
#include <iostream>
#include <math.h>

void CWindDirectionData::Update(double value)
{
	double x = cos(value * M_PI / 180);
	double y = sin(value * M_PI / 180);

	m_x += x;
	m_y += y;

	double angle = atan2(m_y, m_x) * 180 / M_PI;

	if (angle < 0)
	{
		angle = 360 + angle;
	}

	m_average = angle;
}

void CWindDirectionData::Display() const
{
	std::cout << "average: " << m_average << "\n";
}

double CWindDirectionData::GetAverage() const
{
	return m_average;
}