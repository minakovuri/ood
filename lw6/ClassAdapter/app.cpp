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
	CModernCanvasAdapter modernCanvasAdapter(cout);
	shape_drawing_lib::CCanvasPainter painter(modernCanvasAdapter);

	modernCanvasAdapter.BeginDraw();
	PaintPicture(painter);
	modernCanvasAdapter.EndDraw();
}

app::CModernCanvasAdapter::CModernCanvasAdapter(ostream& strm)
	: CModernGraphicsRenderer(strm)
	, m_startPoint(0, 0)
{
}

void app::CModernCanvasAdapter::MoveTo(int x, int y)
{
	m_startPoint = modern_graphics_lib::CPoint(x, y);
}

void app::CModernCanvasAdapter::LineTo(int x, int y)
{
	auto endPoint = modern_graphics_lib::CPoint(x, y);
	DrawLine(m_startPoint, endPoint);
}
