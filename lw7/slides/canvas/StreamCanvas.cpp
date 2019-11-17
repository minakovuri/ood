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

void CStreamCanvas::FillPolygon(const std::vector<PointD>& vertices)
{
	m_stream << "Fill polygon with color #" << m_fillColor << std::endl;

	for (auto vertex : vertices)
	{
		m_stream << "Vertex {" << vertex.x << ";" << vertex.y << "}" << std::endl;
	}
}

void CStreamCanvas::SetFillColor(RGBAColor color)
{
	m_fillColor = color;
}

void CStreamCanvas::SetLineColor(RGBAColor color)
{
	m_lineColor = color;
}

void CStreamCanvas::SetLineThikness(double thickness)
{
	m_lineThikness = thickness;
}
