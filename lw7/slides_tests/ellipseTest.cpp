#include "../../catch.hpp"
#include "../slides/shapes/Ellipse.h"
#include "utils/IsRectsEqual.h"

TEST_CASE("get ellipse frame")
{
	CEllipse ellipse(SPoint{ 50, 50 }, 20, 10);
	CHECK(IsRectsEqual(ellipse.GetFrame(), RectD{ 30, 40, 40, 20 }));
}

TEST_CASE("set ellipse frame")
{
	CEllipse ellipse(SPoint{ 50, 50 }, 20, 10);
	RectD newFrame = RectD{ 40, 80, 20, 30 };

	ellipse.SetFrame(newFrame);
	CHECK(IsRectsEqual(ellipse.GetFrame(), newFrame));
}