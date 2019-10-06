#include "../../catch.hpp"
#include "../Shapes/shapes/Ellipse.h"
#include "../Shapes/shapes/Rectangle.h"
#include "../Shapes/shapes/RegularPolygon.h"
#include "../Shapes/shapes/Triangle.h"
#include "utils.h"
#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;

typedef unique_ptr<CShape> ShapePtr;

class CMockCanvas : public ICanvas
{
public:
	CMockCanvas() = default;

	void SetColor(Color color) override
	{
		m_color = color;
	}

	void DrawLine(Point from, Point to) override
	{
		m_linesCount++;
	}

	void DrawEllipse(Point center, double horizontalRadius, double verticalRadius)
	{
		m_ellipsesCount++;
	}

	size_t GetLinesCount() const
	{
		return m_linesCount;
	}

	size_t GetEllipsesCount() const
	{
		return m_ellipsesCount;
	}

private:
	Color m_color;
	size_t m_linesCount = 0;
	size_t m_ellipsesCount = 0;
};

TEST_CASE("Test rectangle")
{
	CRectangle rectangle(Color::Red, Point{ 10, 10 }, Point{ 20, 20 });

	CHECK(rectangle.GetColor() == Color::Red);
	CHECK(IsPointsEqual(rectangle.GetLeftTop(), Point{ 10, 10 }));
	CHECK(IsPointsEqual(rectangle.GetRightBottom(), Point{ 20, 20 }));

	CMockCanvas canvas;
	rectangle.Draw(canvas);
	CHECK(canvas.GetLinesCount() == 4);
	CHECK(canvas.GetEllipsesCount() == 0);

	CHECK_THROWS_AS(CRectangle(Color::Blue, Point{ 10, 10 }, Point{ 5, 20 }), logic_error);
	CHECK_THROWS_AS(CRectangle(Color::Blue, Point{ 10, 10 }, Point{ 20, 5 }), logic_error);
}

TEST_CASE("Test triangle")
{
	CTriangle triangle(Color::Black, Point{ 10, 5 }, Point{ 15, 10 }, Point{ 5, 30 });

	CHECK(triangle.GetColor() == Color::Black);
	CHECK(IsPointsEqual(triangle.GetVertex1(), Point{ 10, 5 }));
	CHECK(IsPointsEqual(triangle.GetVertex2(), Point{ 15, 10 }));
	CHECK(IsPointsEqual(triangle.GetVertex3(), Point{ 5, 30 }));

	CMockCanvas canvas;
	triangle.Draw(canvas);
	CHECK(canvas.GetLinesCount() == 3);
	CHECK(canvas.GetEllipsesCount() == 0);

	CHECK_THROWS_AS(CTriangle(Color::Black, Point{ -2, 5 }, Point{ 4, 3 }, Point{ 16, -1 }), logic_error);
}

TEST_CASE("Test ellipse")
{
	CEllipse ellipse(Color::Pink, Point{ 5, 6 }, 10.50, 6.7);

	CHECK(ellipse.GetColor() == Color::Pink);
	CHECK(IsPointsEqual(ellipse.GetCenter(), Point{ 5, 6 }));
	CHECK(ellipse.GetHorizontalRadius() == 10.50);
	CHECK(ellipse.GetVerticalRadius() == 6.7);

	CMockCanvas canvas;
	ellipse.Draw(canvas);
	CHECK(canvas.GetLinesCount() == 0);
	CHECK(canvas.GetEllipsesCount() == 1);

	CHECK_THROWS_AS(CEllipse(Color::Green, Point{ 10, 5 }, -2.4, 2), logic_error);
	CHECK_THROWS_AS(CEllipse(Color::Green, Point{ 10, 5 }, 2.4, -2), logic_error);
}

TEST_CASE("Test regular polygon")
{
	CRegularPolygon polygon(Color::Green, Point{ 5, 5 }, 2, 5);

	CHECK(polygon.GetColor() == Color::Green);
	CHECK(IsPointsEqual(polygon.GetCenter(), Point{ 5, 5 }));
	CHECK(polygon.GetRadius() == 2);
	CHECK(polygon.GetVertexCount() == 5);

	auto vertexes = polygon.GetVertexes();

	CHECK(vertexes.size() == polygon.GetVertexCount());

	auto angle = 2 * M_PI / 5;

	for (size_t i = 0; i < 5; i++)
	{
		CHECK(IsPointsEqual(vertexes[i], Point{ 5 + 2 * cos(angle * i), 5 + 2 * sin(angle * i) }));
	}

	CMockCanvas canvas;
	polygon.Draw(canvas);
	CHECK(canvas.GetLinesCount() == 5);
	CHECK(canvas.GetEllipsesCount() == 0);

	CHECK_THROWS_AS(CRegularPolygon(Color::Blue, Point{ 10, 10 }, -4.5, 4), logic_error);
}
