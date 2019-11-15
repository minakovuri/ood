#include "Rectangle.h"
#include <cmath>

CRectangle::CRectangle(const SPoint& leftTop, const SPoint& rightBottom)
	: CSimpleShape()
	, m_leftTop(leftTop)
	, m_rightBottom(rightBottom)
{
}

RectD CRectangle::GetFrame()
{
	double width = std::abs(m_rightBottom.x - m_leftTop.x);
	double height = std::abs(m_rightBottom.y - m_leftTop.y);

	return RectD{ m_leftTop.x, m_leftTop.y, width, height };
}

void CRectangle::SetFrame(const RectD& rect)
{
	m_leftTop = SPoint{ rect.left, rect.top };
	m_rightBottom = SPoint{ rect.left + rect.width, rect.top + rect.height };
}

void CRectangle::DrawBehaviour(const ICanvas& canvas) const
{
}
