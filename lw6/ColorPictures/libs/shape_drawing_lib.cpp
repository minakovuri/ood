#include "shape_drawing_lib.h"

shape_drawing_lib::CTriangle::CTriangle(const Point& p1, const Point& p2, const Point& p3, uint32_t color)
	: m_p1(p1)
	, m_p2(p2)
	, m_p3(p3)
	, m_color(color)
{
}

void shape_drawing_lib::CTriangle::Draw(graphics_lib::ICanvas& canvas) const
{
	canvas.MoveTo(m_p1.x, m_p1.y);
	canvas.LineTo(m_p2.x, m_p2.y);
	canvas.LineTo(m_p3.x, m_p3.y);
	canvas.LineTo(m_p1.x, m_p1.y);
}

shape_drawing_lib::CRectangle::CRectangle(const Point& leftTop, int width, int height, uint32_t color)
	: m_leftTop(leftTop)
	, m_width(width)
	, m_height(height)
	, m_color(color)
{
}

void shape_drawing_lib::CRectangle::Draw(graphics_lib::ICanvas& canvas) const
{
	canvas.SetColor(m_color);
	canvas.MoveTo(m_leftTop.x, m_leftTop.y);

	canvas.LineTo(m_leftTop.x + m_width, m_leftTop.y);
	canvas.LineTo(m_leftTop.x + m_width, m_leftTop.y + m_height);
	canvas.LineTo(m_leftTop.x, m_leftTop.y + m_height);
	canvas.LineTo(m_leftTop.x, m_leftTop.y);
}

shape_drawing_lib::CCanvasPainter::CCanvasPainter(graphics_lib::ICanvas& canvas)
	: m_canvas(canvas)
{
}

void shape_drawing_lib::CCanvasPainter::Draw(const ICanvasDrawable& drawable)
{
	drawable.Draw(m_canvas);
}
