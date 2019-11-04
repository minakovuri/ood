#pragma once
#include "libs/modern_graphics_lib.h"
#include "libs/shape_drawing_lib.h"

// Пространство имен приложения (доступно для модификации)
namespace app
{
void PaintPicture(shape_drawing_lib::CCanvasPainter& painter);
void PaintPictureOnCanvas();
void PaintPictureOnModernGraphicsRenderer();

class CModernCanvasAdapter : public graphics_lib::ICanvas
{
public:
	CModernCanvasAdapter(modern_graphics_lib::CModernGraphicsRenderer& modernGraphicsRenderer);

	void SetColor(uint32_t rgbColor) override;
	void MoveTo(int x, int y) override;
	void LineTo(int x, int y) override;

	void BeginDraw();
	void EndDraw();

private:
	modern_graphics_lib::CPoint m_startPoint;
	modern_graphics_lib::CRGBAColor m_color;
	modern_graphics_lib::CModernGraphicsRenderer& m_modernGraphicsRenderer;
};
} // namespace app
