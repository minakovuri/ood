#pragma once
#include "../Point.h"
#include "Shape.h"

class CRectangle : public CShape
{
public:
	CRectangle(Color color, const Point& leftTop, const Point& rightBottom);

	Point GetLeftTop() const;
	Point GetRightBottom() const;

	void Draw(ICanvas& canvas) const final;

private:
	Point m_leftTop;
	Point m_rightBottom;
};