#include "../../catch.hpp"
#include "../slides/shapes/SimpleShape.h"

using namespace std;

TEST_CASE("create simple shape")
{
	RectD frame{ 10.56, 12.45 };
	CSimpleShape simpleShape(frame);
}
