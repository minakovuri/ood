#include "../../catch.hpp"
#include "../slides/shapes/SimpleShape.h"

TEST_CASE("create simple shape with frame")
{
	RectD frame{ 10.56, 12.45 };
	CSimpleShape simpleShape(frame);
}
