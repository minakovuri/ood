#include "../../catch.hpp"
#include "../slides/shapes/Rectangle.h"
#include "../slides/canvas/StreamCanvas.h"
#include "utils/IsRectsEqual.h"
#include "Colors.h"
#include <sstream>

using namespace std;

TEST_CASE("get rectangle frame")
{
	CRectangle rectangle(PointD{ 10, 10 }, PointD{ 100, 50 });
	CHECK(IsRectsEqual(rectangle.GetFrame(), RectD{ 10, 10, 90, 40 }));
}

TEST_CASE("set rectangle frame")
{
	CRectangle rectangle(PointD{ 10, 10 }, PointD{ 100, 50 });
	RectD newFrame = RectD{ 20, 20, 50, 50 };

	rectangle.SetFrame(newFrame);
	CHECK(IsRectsEqual(rectangle.GetFrame(), newFrame));
}

TEST_CASE("draw rectangle")
{
	CRectangle rectangle(PointD{ 10, 10 }, PointD{ 60, 50 });

	rectangle.GetFillStyle()->SetEnabled(true);
	rectangle.GetFillStyle()->SetColor(Colors::Red);

	rectangle.GetOutlineStyle()->SetEnabled(true);
	rectangle.GetOutlineStyle()->SetColor(Colors::Blue);
	rectangle.GetOutlineStyle()->SetThickness(1.5);

	stringstream outputStream;
	CStreamCanvas canvas(outputStream);

	rectangle.Draw(canvas);

	stringstream expectedResultStream;
	expectedResultStream << "Set fill color #" << Colors::Red << std::endl
						 << "Draw #" << Colors::Blue << " line with 1.5 thickness from {10;10} to {60;10}" << std::endl
						 << "Draw #" << Colors::Blue << " line with 1.5 thickness from {60;10} to {60;50}" << std::endl
						 << "Draw #" << Colors::Blue << " line with 1.5 thickness from {60;50} to {10;50}" << std::endl
						 << "Draw #" << Colors::Blue << " line with 1.5 thickness from {10;50} to {10;10}" << std::endl;

	CHECK(outputStream.str() == expectedResultStream.str());
}