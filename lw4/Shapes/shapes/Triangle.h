#pragma once
#include "Shape.h"
#include "../Point.h"

class CTriangle : public CShape
{
public:
	CTriangle(Color color, const Point& vertex1, const Point& vertex2, const Point& vertex3);

	Point GetVertex1() const;
	Point GetVertex2() const;
	Point GetVertex3() const;

	void Draw(ICanvas& canvas) const final;

private:
	Point m_vertex1;
	Point m_vertex2;
	Point m_vertex3;
};