#pragma once
#include "graphics_lib.h"

// ������������ ���� ���������� ��� ��������� ����� (���������� graphics_lib)
// ��� ���������� ���������� ��� ���������
namespace shape_drawing_lib
{
struct Point
{
	int x;
	int y;
};

// ��������� ��������, ������� ����� ���� ���������� �� ������ �� graphics_lib
class ICanvasDrawable
{
public:
	virtual void Draw(graphics_lib::ICanvas& canvas) const = 0;
	virtual ~ICanvasDrawable() = default;
};

class CTriangle : public ICanvasDrawable
{
public:
	CTriangle(const Point& p1, const Point& p2, const Point& p3);
	void Draw(graphics_lib::ICanvas& canvas) const override;

private:
	Point m_p1;
	Point m_p2;
	Point m_p3;
};

class CRectangle : public ICanvasDrawable
{
public:
	CRectangle(const Point& leftTop, int width, int height);
	void Draw(graphics_lib::ICanvas& canvas) const override;

private:
	Point m_leftTop;
	int m_width;
	int m_height;
};

class CCanvasPainter
{
public:
	CCanvasPainter(graphics_lib::ICanvas& canvas);
	void Draw(const ICanvasDrawable& drawable);

private:
	graphics_lib::ICanvas& m_canvas;
};
} // namespace shape_drawing_lib
