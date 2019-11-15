#include "../../catch.hpp"
#include "../slides/shapes/Triangle.h"
#include "utils/IsRectsEqual.h"

TEST_CASE("get triangle frame")
{
	CTriangle triangle(SPoint{ 30, 20 }, SPoint{ 20, 40 }, SPoint{ 40, 50 });
	CHECK(IsRectsEqual(triangle.GetFrame(), RectD{ 20, 20, 20, 30 }));
}

TEST_CASE("set triangle frame")
{
	CTriangle triangle(SPoint{ 0, 0 }, SPoint{ 10, 0 }, SPoint{ 5, 5 });
	RectD newFrame = RectD{ 15, 20, 10, 15 };

	triangle.SetFrame(newFrame);
	CHECK(IsRectsEqual(triangle.GetFrame(), newFrame));
}