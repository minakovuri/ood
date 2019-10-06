#include "Ellipse.h"
#include <stdexcept>

CEllipse::CEllipse(Color color, const Point& center, double horizontalRadius, double verticalRadius)
	: CShape(color)
{
	if (horizontalRadius < 0 || verticalRadius < 0)
		throw std::logic_error("cannot create ellipse with negative radius");

	m_center = center;
	m_horizontalRadius = horizontalRadius;
	m_verticalRadius = verticalRadius;
}

Point CEllipse::GetCenter() const
{
	return m_center;
}

double CEllipse::GetHorizontalRadius() const
{
	return m_horizontalRadius;
}

double CEllipse::GetVerticalRadius() const
{
	return m_verticalRadius;
}

void CEllipse::Draw(ICanvas& canvas) const
{
	canvas.SetColor(GetColor());

	canvas.DrawEllipse(m_center, m_horizontalRadius, m_verticalRadius);
}
