#include "Triangle.h"
#include <stdexcept>

CTriangle::CTriangle(Color color, const Point& vertex1, const Point& vertex2, const Point& vertex3)
	: CShape(color)
{
	if (!IsValid(vertex1, vertex2, vertex3))
		throw std::logic_error("cannot create triangle");

	m_vertex1 = vertex1;
	m_vertex2 = vertex2;
	m_vertex3 = vertex3;
}

Point CTriangle::GetVertex1() const
{
	return m_vertex1;
}

Point CTriangle::GetVertex2() const
{
	return m_vertex2;
}

Point CTriangle::GetVertex3() const
{
	return m_vertex3;
}

void CTriangle::Draw(ICanvas& canvas) const
{
	canvas.SetColor(GetColor());

	canvas.DrawLine(m_vertex1, m_vertex2);
	canvas.DrawLine(m_vertex2, m_vertex3);
	canvas.DrawLine(m_vertex3, m_vertex1);
}

bool CTriangle::IsValid(const Point& vertex1, const Point& vertex2, const Point& vertex3)
{
	return (vertex2.x - vertex1.x) * (vertex3.y - vertex1.y) - (vertex2.y - vertex1.y) * (vertex3.x - vertex1.x);
}
