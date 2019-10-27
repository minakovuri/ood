#include <iostream>
#include "app.h"
#include "libs/modern_graphics_lib.h"

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
	graphics_lib::CModernCanvasAdapter modernCanvasAdapter(modernGraphicsRenderer);
	shape_drawing_lib::CCanvasPainter painter(modernCanvasAdapter);

	modernCanvasAdapter.BeginDraw();
	PaintPicture(painter);
	modernCanvasAdapter.EndDraw();
}
