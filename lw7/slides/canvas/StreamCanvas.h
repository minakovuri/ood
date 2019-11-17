#pragma once
#include "ICanvas.h"
#include <ostream>

class CStreamCanvas : public ICanvas
{
public:
	CStreamCanvas(std::ostream& stream);

	void DrawLine(const PointD& startPoint, const PointD& endPoint) override;
	void DrawEllipse(const PointD& leftTop, double width, double height) override;
	void SetFillColor(RGBAColor color) override;
	void SetLineColor(RGBAColor color) override;
	void SetLineThikness(double thickness) override;

private:
	std::ostream& m_stream;

	RGBAColor m_fillColor;
	RGBAColor m_lineColor;
	double m_lineThikness;
};
