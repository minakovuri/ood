#include "StreamCanvas.h"
#include "../Colors.h"

CStreamCanvas::CStreamCanvas(std::ostream& stream)
	: m_stream(stream)
	, m_fillColor(Colors::White)
	, m_lineColor(Colors::Black)
	, m_lineThikness(1.0)
{
}

void CStreamCanvas::DrawLine(const PointD& startPoint, const PointD& endPoint)
{
	m_stream << "Draw #" << m_lineColor << " line with " << m_lineThikness << " thickness "
			 << "from {" << startPoint.x << ";" << startPoint.y << "} "
			 << "to {" << endPoint.x << ";" << endPoint.y << "}"
			 << std::endl;
}

void CStreamCanvas::DrawEllipse(const PointD& leftTop, double width, double height)
{
	m_stream << "Draw #" << m_fillColor << " ellipse with " << m_lineColor << " outline color and " << m_lineThikness << " thickness "
			 << "with left top at {" << leftTop.x << ";" << leftTop.y << "}, width " << width << " and height " << height
			 << std::endl;
}

void CStreamCanvas::SetFillColor(RGBAColor color)
{
	m_fillColor = color;
	m_stream << "Set fill color #" << color << std::endl;
}

void CStreamCanvas::SetLineColor(RGBAColor color)
{
	m_lineColor = color;
}

void CStreamCanvas::SetLineThikness(double thickness)
{
	m_lineThikness = thickness;
}
