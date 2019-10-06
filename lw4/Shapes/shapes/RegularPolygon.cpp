#include "RegularPolygon.h"
#include <stdexcept>
#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;

CRegularPolygon::CRegularPolygon(Color color, Point center, double radius, unsigned vertexCount)
	: CShape(color)
{
	if (radius < 0)
		throw std::logic_error("cannot create regular polygon with negative radius");

	m_center = center;
	m_radius = radius;
	m_vertexCount = vertexCount;
}

Point CRegularPolygon::GetCenter() const
{
	return m_center;
}

double CRegularPolygon::GetRadius() const
{
	return m_radius;
}

unsigned CRegularPolygon::GetVertexCount() const
{
	return m_vertexCount;
}

void CRegularPolygon::Draw(ICanvas& canvas) const
{
	canvas.SetColor(GetColor());

	auto vertexes = GetVertexes();

	Point lastVertex = vertexes[m_vertexCount - 1];
	Point firstVertex = vertexes[0];

	canvas.DrawLine(lastVertex, firstVertex);

	for (size_t i = 0; i < m_vertexCount - 1; i++)
	{
		canvas.DrawLine(vertexes[i], vertexes[i + 1]);
	}
}

vector<Point> CRegularPolygon::GetVertexes() const
{
	auto offsetAngle = 2 * M_PI / m_vertexCount;

	vector<Point> vertexes;

	for (size_t i = 0; i < m_vertexCount; i++)
	{
		vertexes.push_back({
			m_center.x + m_radius * cos(offsetAngle * i),
			m_center.y + m_radius * sin(offsetAngle * i),
		});
	}

	return vertexes;
}
