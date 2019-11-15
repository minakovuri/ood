#include "../../catch.hpp"
#include "../slides/shapes/Rectangle.h"
#include "utils/IsRectsEqual.h"

TEST_CASE("get rectangle frame")
{
	CRectangle rectangle(SPoint{ 10, 10 }, SPoint{ 100, 50 });
	CHECK(IsRectsEqual(rectangle.GetFrame(), RectD{ 10, 10, 90, 40 }));
}

TEST_CASE("set rectangle frame")
{
	CRectangle rectangle(SPoint{ 10, 10 }, SPoint{ 100, 50 });
	RectD newFrame = RectD{ 20, 20, 50, 50 };

	rectangle.SetFrame(newFrame);
	CHECK(IsRectsEqual(rectangle.GetFrame(), newFrame));
}