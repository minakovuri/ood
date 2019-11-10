#include "../../catch.hpp"
#include "../slides/shapes/ShapeGroup.h"
#include "../slides/shapes/SimpleShape.h"
#include "Colors.h"

using namespace std;

TEST_CASE("insert shape to group")
{
	CShapeGroup shapeGroup;
	CHECK(shapeGroup.GetShapesCount() == 0);

	RectD frame{ 10.56, 12.45 };
	shared_ptr<IShape> shape1 = make_shared<CSimpleShape>(frame);
	shared_ptr<IShape> shape2 = make_shared<CSimpleShape>(frame);

	shapeGroup.InsertShape(shape1);
	CHECK(shapeGroup.GetShapesCount() == 1);
	CHECK(shapeGroup.GetShapeAtIndex(0) == shape1);

	shapeGroup.InsertShape(shape2, 0);
	CHECK(shapeGroup.GetShapesCount() == 2);
	CHECK(shapeGroup.GetShapeAtIndex(0) == shape2);
	CHECK(shapeGroup.GetShapeAtIndex(1) == shape1);

	CHECK_THROWS(shapeGroup.InsertShape(shape1, 3));
}

TEST_CASE("trying to get shape by invalid index")
{
	CShapeGroup shapeGroup;
	CHECK_THROWS(shapeGroup.GetShapeAtIndex(1));
}

TEST_CASE("remove shape from group")
{
	CShapeGroup shapeGroup;

	RectD frame{ 10.56, 12.45 };
	shared_ptr<IShape> shape1 = make_shared<CSimpleShape>(frame);
	shared_ptr<IShape> shape2 = make_shared<CSimpleShape>(frame);

	shapeGroup.InsertShape(shape1);
	shapeGroup.InsertShape(shape2);

	shapeGroup.RemoveShapeAtIndex(0);
	CHECK(shapeGroup.GetShapesCount() == 1);
	CHECK(shapeGroup.GetShapeAtIndex(0) == shape2);
}

TEST_CASE("trying to remove shape by invalid index")
{
	CShapeGroup shapeGroup;

	RectD frame{ 10.56, 12.45 };
	shared_ptr<IShape> shape1 = make_shared<CSimpleShape>(frame);
	shapeGroup.InsertShape(shape1);

	CHECK_THROWS(shapeGroup.RemoveShapeAtIndex(1));
}

TEST_CASE("get shape group styles")
{
	CShapeGroup shapeGroup;

	RectD frame{ 10.56, 12.45 };

	shared_ptr<IShape> shape1 = make_shared<CSimpleShape>(frame);
	shape1->GetFillStyle()->SetColor(Colors::Red);
	shape1->GetFillStyle()->SetEnabled(false);
	shape1->GetOutlineStyle()->SetColor(Colors::Blue);
	shape1->GetOutlineStyle()->SetEnabled(true);
	shape1->GetOutlineStyle()->SetThickness(5.0);

	shared_ptr<IShape> shape2 = make_shared<CSimpleShape>(frame);
	shape2->GetFillStyle()->SetColor(Colors::Yellow);
	shape2->GetFillStyle()->SetEnabled(false);
	shape2->GetOutlineStyle()->SetColor(Colors::Blue);
	shape2->GetOutlineStyle()->SetEnabled(false);
	shape2->GetOutlineStyle()->SetThickness(5.0);

	shapeGroup.InsertShape(shape1);
	shapeGroup.InsertShape(shape2);

	CHECK(shapeGroup.GetFillStyle()->GetColor() == nullopt);
	CHECK(shapeGroup.GetFillStyle()->IsEnabled() == false);
	CHECK(shapeGroup.GetOutlineStyle()->GetColor() == Colors::Blue);
	CHECK(shapeGroup.GetOutlineStyle()->IsEnabled() == nullopt);
	CHECK(shapeGroup.GetOutlineStyle()->GetThickness() == 5.0);
}