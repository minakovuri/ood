#pragma once
#include <ostream>

using namespace std;

// ������������ ���� ����������� ����������� ���������� (���������� ��� ���������)
namespace modern_graphics_lib
{
class CPoint
{
public:
	CPoint(int x, int y)
		: x(x)
		, y(y)
	{
	}

	int x, y;
};

class CRGBAColor
{
public:
	CRGBAColor(float r, float g, float b, float a)
		: r(r)
		, g(g)
		, b(b)
		, a(a)
	{
	}

	float r, g, b, a;
};

class CModernGraphicsRenderer
{
public:
	CModernGraphicsRenderer(ostream& strm);

	// ���� ����� ������ ���� ������ � ������ ���������
	void BeginDraw();

	// ��������� ��������� �����
	void DrawLine(const CPoint& start, const CPoint& end, const CRGBAColor& color);

	// ���� ����� ������ ���� ������ � ����� ���������
	void EndDraw();

	~CModernGraphicsRenderer();

private:
	ostream& m_out;
	bool m_drawing = false;
};
} // namespace modern_graphics_lib