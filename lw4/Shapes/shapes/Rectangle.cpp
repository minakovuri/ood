#include "Rectangle.h"
#include <stdexcept>

CRectangle::CRectangle(Color color, const Point& leftTop, const Point& rightBottom)
	: CShape(color)
{
	if (leftTop.y > rightBottom.y)
	{
		throw std::logic_error("cannot create rectangle");
	}

	if (leftTop.x > rightBottom.x)
	{
		throw std::logic_error("cannot create rectangle");
	}

	m_leftTop = leftTop;
	m_rightBottom = rightBottom;
}

Point CRectangle::GetLeftTop() const
{
	return m_leftTop;
}

Point CRectangle::GetRightBottom() const
{
	return m_rightBottom;
}

void CRectangle::Draw(ICanvas& canvas) const
{
	canvas.SetColor(GetColor());

	Point leftBottom{ m_leftTop.x, m_rightBottom.y };
	Point rightTop{ m_rightBottom.x, m_leftTop.y };

	canvas.DrawLine(m_leftTop, leftBottom);
	canvas.DrawLine(leftBottom, m_rightBottom);
	canvas.DrawLine(m_rightBottom, rightTop);
	canvas.DrawLine(rightTop, m_leftTop);
}
