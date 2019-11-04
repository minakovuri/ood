#include <iostream>
#include "app.h"

void app::PaintPicture(shape_drawing_lib::CCanvasPainter& painter)
{
	using namespace shape_drawing_lib;

	CTriangle triangle({ 10, 15 }, { 100, 200 }, { 150, 250 });
	CRectangle rectangle({ 30, 40 }, 18, 24);

	painter.Draw(triangle);
	painter.Draw(rectangle);
}

void app::PaintPictureOnCanvas()
{
	graphics_lib::CCanvas simpleCanvas;
	shape_drawing_lib::CCanvasPainter painter(simpleCanvas);
	PaintPicture(painter);
}

void app::PaintPictureOnModernGraphicsRenderer()
{
	modern_graphics_lib::CModernGraphicsRenderer modernGraphicsRenderer(cout);
	CModernCanvasAdapter modernCanvasAdapter(modernGraphicsRenderer);
	shape_drawing_lib::CCanvasPainter painter(modernCanvasAdapter);

	modernCanvasAdapter.BeginDraw();
	PaintPicture(painter);
	modernCanvasAdapter.EndDraw();
}

app::CModernCanvasAdapter::CModernCanvasAdapter(modern_graphics_lib::CModernGraphicsRenderer& modernGraphicsRenderer)
	: m_modernGraphicsRenderer(modernGraphicsRenderer)
	, m_startPoint(0, 0)
	, m_color(0, 0, 0, 1)
{
}

void app::CModernCanvasAdapter::SetColor(uint32_t rgbColor)
{
	auto r = static_cast<float>(((rgbColor >> 16) & 0xFF) / 255.0);
	auto g = static_cast<float>((rgbColor >> 8 & 0xFF) / 255.0);
	auto b = static_cast<float>((rgbColor & 0xFF) / 255.0);
	float a = 1.0;
	
	m_color = modern_graphics_lib::CRGBAColor(r, g, b, a);
}

void app::CModernCanvasAdapter::MoveTo(int x, int y)
{
	m_startPoint = modern_graphics_lib::CPoint(x, y);
}

void app::CModernCanvasAdapter::LineTo(int x, int y)
{
	auto endPoint = modern_graphics_lib::CPoint(x, y);
	m_modernGraphicsRenderer.DrawLine(m_startPoint, endPoint, m_color);
}

void app::CModernCanvasAdapter::BeginDraw()
{
	m_modernGraphicsRenderer.BeginDraw();
}

void app::CModernCanvasAdapter::EndDraw()
{
	m_modernGraphicsRenderer.EndDraw();
}
