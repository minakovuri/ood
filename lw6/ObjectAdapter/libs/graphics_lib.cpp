#include <iostream>
#include "graphics_lib.h"

using namespace std;

void graphics_lib::CCanvas::MoveTo(int x, int y)
{
	cout << "MoveTo (" << x << ", " << y << ")" << endl;
}

void graphics_lib::CCanvas::LineTo(int x, int y)
{
	cout << "MoveTo (" << x << ", " << y << ")" << endl;
}

graphics_lib::CModernCanvasAdapter::CModernCanvasAdapter(modern_graphics_lib::CModernGraphicsRenderer& modernGraphicsRenderer)
	: m_modernGraphicsRenderer(modernGraphicsRenderer)
	, m_startPoint(0, 0)
{
}

void graphics_lib::CModernCanvasAdapter::MoveTo(int x, int y)
{
	m_startPoint = modern_graphics_lib::CPoint(x, y);
}

void graphics_lib::CModernCanvasAdapter::LineTo(int x, int y)
{
	auto endPoint = modern_graphics_lib::CPoint(x, y);
	m_modernGraphicsRenderer.DrawLine(m_startPoint, endPoint);
}

void graphics_lib::CModernCanvasAdapter::BeginDraw()
{
	m_modernGraphicsRenderer.BeginDraw();
}

void graphics_lib::CModernCanvasAdapter::EndDraw()
{
	m_modernGraphicsRenderer.EndDraw();
}
