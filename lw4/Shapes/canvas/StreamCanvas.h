#pragma once
#include "ICanvas.h"
#include <ostream>

class CStreamCanvas : public ICanvas
{
public:
	CStreamCanvas(std::ostream& stream, Color color = Color::Black);

	void SetColor(Color color) override;
	void DrawLine(Point from, Point to) override;
	void DrawEllipse(Point center, double horizontalRadius, double verticalRadius) override;

private:
	std::string GetColor();

	Color m_color;
	std::ostream& m_stream;
};
