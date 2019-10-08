#include "SfmlCanvas.h"

const int LINE_THICKNESS = 5;
const int ELLIPSE_THICKNESS = 2;

CSfmlCanvas::CSfmlCanvas(sf::RenderWindow& renderWindow)
	: m_renderWindow(renderWindow)
{
}

void CSfmlCanvas::SetColor(Color color)
{
	if (color == Color::Black)
	{
		m_color = sf::Color::Black;
	}
	else if (color == Color::Blue)
	{
		m_color = sf::Color::Blue;
	}
	else if (color == Color::Green)
	{
		m_color = sf::Color::Green;
	}
	else if (color == Color::Pink)
	{
		m_color = sf::Color(255, 192, 203);
	}
	else if (color == Color::Red)
	{
		m_color = sf::Color::Red;
	}
	else if (color == Color::Yellow)
	{
		m_color = sf::Color::Yellow;
	}
}

void CSfmlCanvas::DrawLine(Point from, Point to)
{
	sf::Vertex line[2] = {
		sf::Vertex(sf::Vector2f(static_cast<float>(from.x), static_cast<float>(from.y)), m_color),
		sf::Vertex(sf::Vector2f(static_cast<float>(to.x), static_cast<float>(to.y)), m_color),
	};

	m_renderWindow.draw(line, LINE_THICKNESS, sf::Lines);
}

void CSfmlCanvas::DrawEllipse(Point leftTop, double width, double height)
{
	float horizontalRadius = static_cast<float>(width / 2);
	float verticalRadius = static_cast<float>(height / 2);

	sf::CircleShape ellipse(horizontalRadius);
	ellipse.setPosition(static_cast<float>(leftTop.x), static_cast<float>(leftTop.y));
	ellipse.setOutlineThickness(ELLIPSE_THICKNESS);
	ellipse.setFillColor(sf::Color::White);
	ellipse.setOutlineColor(m_color);
	ellipse.setScale(1.f, verticalRadius / horizontalRadius);

	m_renderWindow.draw(ellipse);
}
