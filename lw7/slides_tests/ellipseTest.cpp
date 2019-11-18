#include "../../catch.hpp"
#include "../slides/shapes/Ellipse.h"
#include "../slides/canvas/StreamCanvas.h"
#include "utils/IsRectsEqual.h"
#include "Colors.h"
#include <sstream>

using namespace std;

TEST_CASE("get ellipse frame")
{
	CEllipse ellipse(PointD{ 50, 50 }, 20, 10);
	CHECK(IsRectsEqual(*ellipse.GetFrame(), RectD{ 30, 40, 40, 20 }));
}

TEST_CASE("set ellipse frame")
{
	CEllipse ellipse(PointD{ 50, 50 }, 20, 10);
	RectD newFrame = RectD{ 40, 80, 20, 30 };

	ellipse.SetFrame(newFrame);
	CHECK(IsRectsEqual(*ellipse.GetFrame(), newFrame));
}

TEST_CASE("draw ellipse")
{
	CEllipse ellipse(PointD{ 50, 50 }, 20, 10);

	ellipse.GetFillStyle()->SetEnabled(true);
	ellipse.GetFillStyle()->SetColor(Colors::Red);

	ellipse.GetOutlineStyle()->SetEnabled(true);
	ellipse.GetOutlineStyle()->SetColor(Colors::Blue);
	ellipse.GetOutlineStyle()->SetThickness(1.5);

	stringstream outputStream;
	CStreamCanvas canvas(outputStream);

	ellipse.Draw(canvas);

	stringstream expectedResultStream;
	expectedResultStream << "Draw #" << Colors::Red << " ellipse with " << Colors::Blue << " outline color and 1.5 thickness "
						 << "with left top at {30;40}, width 40 and height 20"
						 << endl;

	CHECK(outputStream.str() == expectedResultStream.str());
}