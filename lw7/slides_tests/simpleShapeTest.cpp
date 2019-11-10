#include "../../catch.hpp"
#include "../slides/shapes/SimpleShape.h"

using namespace std;

TEST_CASE("create simple shape and check is shape group operations is unavailable")
{
	RectD frame{ 10.56, 12.45 };
	CSimpleShape simpleShape(frame);

	CHECK_THROWS_AS(simpleShape.GetShapesCount(), runtime_error);
	CHECK_THROWS_AS(simpleShape.InsertShape(make_shared<CSimpleShape>(frame)), runtime_error);
	CHECK_THROWS_AS(simpleShape.GetShapeAtIndex(0), runtime_error);
	CHECK_THROWS_AS(simpleShape.RemoveShapeAtIndex(0), runtime_error);
}
