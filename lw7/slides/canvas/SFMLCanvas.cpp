#include "SFMLCanvas.h"
#include <math.h>

CSFMLCanvas::CSFMLCanvas(sf::RenderWindow& renderWindow)
	: m_renderWindow(renderWindow)
{
}

void CSFMLCanvas::DrawLine(const PointD& startPoint, const PointD& endPoint)
{
	sf::Vertex vertices[4];

	sf::Vector2f point1( static_cast<float>(startPoint.x), static_cast<float>(startPoint.y) );
	sf::Vector2f point2(static_cast<float>(endPoint.x), static_cast<float>(endPoint.y));

	sf::Vector2f direction = point2 - point1;

	sf::Vector2f unitDirection = direction / std::sqrt(direction.x * direction.x + direction.y * direction.y);
	sf::Vector2f unitPerpendicular(-unitDirection.y, unitDirection.x);

	sf::Vector2f offset = (m_lineThickness / 2.f) * unitPerpendicular;

	vertices[0].position = point1 + offset;
	vertices[1].position = point2 + offset;
	vertices[2].position = point2 - offset;
	vertices[3].position = point1 - offset;

	for (int i = 0; i < 4; ++i)
		vertices[i].color = m_outlineColor;

	m_renderWindow.draw(vertices, 4, sf::Quads);
}

void CSFMLCanvas::DrawEllipse(const PointD& leftTop, double width, double height)
{
	float horizontalRadius = static_cast<float>(width / 2);
	float verticalRadius = static_cast<float>(height / 2);

	sf::CircleShape ellipse(horizontalRadius);
	ellipse.setPosition(static_cast<float>(leftTop.x), static_cast<float>(leftTop.y));
	ellipse.setOutlineThickness(m_lineThickness);
	ellipse.setFillColor(m_fillColor);
	ellipse.setOutlineColor(m_outlineColor);
	ellipse.setScale(1.f, verticalRadius / horizontalRadius);

	m_renderWindow.draw(ellipse);
}

void CSFMLCanvas::FillPolygon(const std::vector<PointD>& vertices)
{
	sf::ConvexShape polygon;
	polygon.setPointCount(vertices.size());
	polygon.setFillColor(m_fillColor);

	for (size_t i = 0; i < vertices.size(); i++)
	{
		polygon.setPoint(i, sf::Vector2f(static_cast<float>(vertices[i].x), static_cast<float>(vertices[i].y)));
	}

	m_renderWindow.draw(polygon);
}

void CSFMLCanvas::SetFillColor(RGBAColor color)
{
	m_fillColor = sf::Color(color);
}

void CSFMLCanvas::SetLineColor(RGBAColor color)
{
	m_outlineColor = sf::Color(color);
}

void CSFMLCanvas::SetLineThikness(double thickness)
{
	m_lineThickness = static_cast<float>(thickness);
}
