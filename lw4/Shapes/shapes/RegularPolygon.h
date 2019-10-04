#pragma once
#include "../Point.h"
#include "Shape.h"

class CRegularPolygon : public CShape
{
public:
	CRegularPolygon(Color color, Point center, double radius, unsigned vertexCount);

	Point GetCenter() const;
	double GetRadius() const;
	unsigned GetVertexCount() const;

	void Draw(ICanvas& canvas) const final;
private:
	Point m_center;
	double m_radius;
	unsigned m_vertexCount;
};