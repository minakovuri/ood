#pragma once
#include "modern_graphics_lib.h"

// ѕространство имен графической библиотеки (недоступно дл€ изменени€)
namespace graphics_lib
{
class ICanvas
{
public:
	virtual void MoveTo(int x, int y) = 0;
	virtual void LineTo(int x, int y) = 0;

	virtual ~ICanvas() = default;
};

class CCanvas : public ICanvas
{
public:
	void MoveTo(int x, int y) override;
	void LineTo(int x, int y) override;
};

class CModernCanvasAdapter : public ICanvas
{
public:
	CModernCanvasAdapter(modern_graphics_lib::CModernGraphicsRenderer& modernGraphicsRenderer);

	void MoveTo(int x, int y) override;
	void LineTo(int x, int y) override;

	void BeginDraw();
	void EndDraw();

private:
	modern_graphics_lib::CPoint m_startPoint;
	modern_graphics_lib::CModernGraphicsRenderer& m_modernGraphicsRenderer;
};
} // namespace graphics_lib
