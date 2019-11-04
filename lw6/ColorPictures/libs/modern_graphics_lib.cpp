#include "modern_graphics_lib.h"
#include <boost/format.hpp>

float RoundColorValue(float colorValue)
{
	return std::round(colorValue * 100) / 100;
}

modern_graphics_lib::CModernGraphicsRenderer::CModernGraphicsRenderer(ostream& strm)
	: m_out(strm)
{
}

void modern_graphics_lib::CModernGraphicsRenderer::BeginDraw()
{
	if (m_drawing)
	{
		throw logic_error("Drawing has already begun");
	}
	m_out << "<draw>" << endl;
	m_drawing = true;
}

void modern_graphics_lib::CModernGraphicsRenderer::DrawLine(const CPoint& start, const CPoint& end, const CRGBAColor& color)
{
	if (!m_drawing)
	{
		throw logic_error("DrawLine is allowed between BeginDraw()/EndDraw() only");
	}
	m_out << boost::format(R"(  <line fromX="%1%" fromY="%2%" toX="%3%" toY="%4%">)")
			% start.x % start.y % end.x % end.y
		  << endl
		  << boost::format(R"(    <color r="%1%" g="%2%" b="%3%" a="%4%" />)")
			% RoundColorValue(color.r) % RoundColorValue(color.g) % RoundColorValue(color.b) % color.a
		  << endl
		  << "  </line>" << endl;
}

void modern_graphics_lib::CModernGraphicsRenderer::EndDraw()
{
	if (!m_drawing)
	{
		throw logic_error("Drawing has not been started");
	}
	m_out << "</draw>" << endl;
	m_drawing = false;
}

modern_graphics_lib::CModernGraphicsRenderer::~CModernGraphicsRenderer()
{
	if (m_drawing)
	{
		EndDraw();
	}
}
