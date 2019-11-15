#include "Ellipse.h"

CEllipse::CEllipse(const SPoint& center, double horizontalRadius, double verticalRadius)
	: m_center(center)
	, m_horizontalRadius(horizontalRadius)
	, m_verticalRadius(verticalRadius)
{
}

RectD CEllipse::GetFrame()
{
	return RectD{
		m_center.x - m_horizontalRadius,
		m_center.y - m_verticalRadius,
		m_horizontalRadius * 2,
		m_verticalRadius * 2
	};
}

void CEllipse::SetFrame(const RectD& rect)
{
	m_center = SPoint{ rect.left + rect.width / 2, rect.top + rect.height / 2 };
	m_horizontalRadius = rect.width / 2;
	m_verticalRadius = rect.height / 2;
}

void CEllipse::DrawBehaviour(const ICanvas& canvas) const
{
}
