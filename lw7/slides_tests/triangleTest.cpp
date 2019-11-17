#include "../../catch.hpp"
#include "../slides/canvas/StreamCanvas.h"
#include "../slides/shapes/Triangle.h"
#include "Colors.h"
#include "utils/IsRectsEqual.h"
#include <sstream>

using namespace std;

TEST_CASE("get triangle frame")
{
	CTriangle triangle(PointD{ 30, 20 }, PointD{ 20, 40 }, PointD{ 40, 50 });
	CHECK(IsRectsEqual(triangle.GetFrame(), RectD{ 20, 20, 20, 30 }));
}

TEST_CASE("set triangle frame")
{
	CTriangle triangle(PointD{ 0, 0 }, PointD{ 10, 0 }, PointD{ 5, 5 });
	RectD newFrame = RectD{ 15, 20, 10, 15 };

	triangle.SetFrame(newFrame);
	CHECK(IsRectsEqual(triangle.GetFrame(), newFrame));
}

TEST_CASE("draw triangle")
{
	CTriangle triangle(PointD{ 30, 20 }, PointD{ 20, 40 }, PointD{ 40, 50 });

	triangle.GetFillStyle()->SetEnabled(true);
	triangle.GetFillStyle()->SetColor(Colors::Red);

	triangle.GetOutlineStyle()->SetEnabled(true);
	triangle.GetOutlineStyle()->SetColor(Colors::Blue);
	triangle.GetOutlineStyle()->SetThickness(1.5);

	stringstream outputStream;
	CStreamCanvas canvas(outputStream);

	triangle.Draw(canvas);

	stringstream expectedResultStream;
	expectedResultStream << "Draw #" << Colors::Blue << " line with 1.5 thickness from {30;20} to {20;40}" << std::endl
						 << "Draw #" << Colors::Blue << " line with 1.5 thickness from {20;40} to {40;50}" << std::endl
						 << "Draw #" << Colors::Blue << " line with 1.5 thickness from {40;50} to {30;20}" << std::endl
						 << "Fill polygon with color #" << Colors::Red << std::endl
						 << "Vertex {30;20}" << std::endl
						 << "Vertex {20;40}" << std::endl
						 << "Vertex {40;50}" << std::endl;

	CHECK(outputStream.str() == expectedResultStream.str());
}
