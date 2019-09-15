#include "StatsData.h"
#include <iostream>

void CStatsData::Update(double value)
{
	if (m_min == -DBL_MAX)
	{
		m_min = value;
	}

	if (m_max == DBL_MAX)
	{
		m_max = value;
	}

	if (value < m_min)
	{
		m_min = value;
	}

	if (value > m_max)
	{
		m_max = value;
	}

	m_average = (m_sum += value) / ++m_counts;
}

void CStatsData::Display()
{
	std::cout << "min: ";
	if (m_min == -DBL_MAX)
	{
		std::cout << "undefined, ";
	}
	else
	{
		std::cout << m_min << ", ";
	}

	std::cout << "max: ";
	if (m_max == DBL_MAX)
	{
		std::cout << "undefined, ";
	}
	else
	{
		std::cout << m_max << ", ";
	}

	std::cout << "average: " << m_average << "\n";
}

Stats CStatsData::GetStats() const
{
	Stats stats;
	stats.min = m_min;
	stats.max = m_max;
	stats.average = m_average;
	return stats;
}