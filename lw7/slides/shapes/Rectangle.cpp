#include "Rectangle.h"
#include <cmath>

CRectangle::CRectangle(const PointD& leftTop, const PointD& rightBottom)
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
	m_leftTop = PointD{ rect.left, rect.top };
	m_rightBottom = PointD{ rect.left + rect.width, rect.top + rect.height };
}

void CRectangle::DrawBehaviour(ICanvas& canvas) const
{
	PointD rightTop{ m_rightBottom.x, m_leftTop.y };
	PointD leftBottom{ m_leftTop.x, m_rightBottom.y };

	if (*GetOutlineStyle()->IsEnabled())
	{
		canvas.DrawLine(m_leftTop, rightTop);
		canvas.DrawLine(rightTop, m_rightBottom);
		canvas.DrawLine(m_rightBottom, leftBottom);
		canvas.DrawLine(leftBottom, m_leftTop);
	}

	if (*GetFillStyle()->IsEnabled())
	{
		canvas.FillPolygon(std::vector<PointD>{ m_leftTop, rightTop, m_rightBottom, leftBottom });
	}
}
