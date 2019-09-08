#include "StatsDisplay.h"
#include <iostream>

void CStatsData::Update(double value)
{
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
	std::cout << "min: " << m_min << ", "
			  << "max: " << m_max << ", "
			  << "average: " << m_average << "\n";
}

Stats CStatsData::GetStats() const
{
	Stats stats;
	stats.min = m_min;
	stats.max = m_max;
	stats.average = m_average;
	return stats;
}