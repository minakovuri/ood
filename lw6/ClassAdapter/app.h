#pragma once
#include "libs/shape_drawing_lib.h"
#include "libs/modern_graphics_lib.h"

// ������������ ���� ���������� (�������� ��� �����������)
namespace app
{
void PaintPicture(shape_drawing_lib::CCanvasPainter& painter);
void PaintPictureOnCanvas();
void PaintPictureOnModernGraphicsRenderer();

class CModernCanvasAdapter 
	: public graphics_lib::ICanvas
	, public modern_graphics_lib::CModernGraphicsRenderer
{
public:
	CModernCanvasAdapter(ostream& strm);

	void MoveTo(int x, int y) override;
	void LineTo(int x, int y) override;

private:
	modern_graphics_lib::CPoint m_startPoint;
};
} // namespace app
