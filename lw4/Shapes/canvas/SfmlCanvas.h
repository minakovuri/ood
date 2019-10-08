#pragma once
#include "ICanvas.h"
#include <SFML/Graphics.hpp>

class CSfmlCanvas : public ICanvas
{
public:
	CSfmlCanvas(sf::RenderWindow& renderWindow);

	void SetColor(Color color) override;
	void DrawLine(Point from, Point to) override;
	void DrawEllipse(Point leftTop, double width, double height) override;

private:
	sf::Color m_color;
	sf::RenderWindow& m_renderWindow;
};