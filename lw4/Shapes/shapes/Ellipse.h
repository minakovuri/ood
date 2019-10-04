#pragma once
#include "../Point.h"
#include "Shape.h"

class CEllipse : public CShape
{
public:
	CEllipse(Color color, const Point& center, double horizontalRadius, double verticalRadius);

	Point GetCenter() const;
	double GetHorizontalRadius() const;
	double GetVerticalRadius() const;

	void Draw(ICanvas& canvas) const final;

private:
	Point m_center;
	double m_horizontalRadius;
	double m_verticalRadius;
};