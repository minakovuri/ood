#pragma once
#include "ICanvas.h"
#include <SFML/Graphics.hpp>

class CSFMLCanvas : public ICanvas
{
public:
	CSFMLCanvas(sf::RenderWindow& renderWindow);

	void DrawLine(const PointD& startPoint, const PointD& endPoint) override;
	void DrawEllipse(const PointD& leftTop, double width, double height) override;
	void FillPolygon(const std::vector<PointD>& vertices) override;

	void SetFillColor(RGBAColor color) override;
	void SetLineColor(RGBAColor color) override;
	void SetLineThikness(double thickness) override;

private:
	sf::RenderWindow& m_renderWindow;

	sf::Color m_fillColor;
	sf::Color m_outlineColor;
	float m_lineThickness = 0;
};