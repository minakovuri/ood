#include "../../catch.hpp"
#include "../slides/shapes/ShapeGroup.h"
#include "Colors.h"
#include "mocks/MockSimpleShape.h"
#include "utils/IsRectsEqual.h"

using namespace std;

TEST_CASE("insert shape to group")
{
	CShapeGroup shapeGroup;
	CHECK(shapeGroup.GetShapesCount() == 0);

	RectD frame{ 10.56, 12.45 };
	shared_ptr<IShape> shape1 = make_shared<CMockSimpleShape>(frame);
	shared_ptr<IShape> shape2 = make_shared<CMockSimpleShape>(frame);

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
	shared_ptr<IShape> shape1 = make_shared<CMockSimpleShape>(frame);
	shared_ptr<IShape> shape2 = make_shared<CMockSimpleShape>(frame);

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
	shared_ptr<IShape> shape1 = make_shared<CMockSimpleShape>(frame);
	shapeGroup.InsertShape(shape1);

	CHECK_THROWS(shapeGroup.RemoveShapeAtIndex(1));
}

TEST_CASE("get undefined shape group fill style options")
{
	CShapeGroup shapeGroup;
	RectD frame{ 10.56, 12.45 };

	shared_ptr<IShape> shape1 = make_shared<CMockSimpleShape>(frame);
	shape1->GetFillStyle()->SetColor(Colors::Red);
	shape1->GetFillStyle()->SetEnabled(true);

	shared_ptr<IShape> shape2 = make_shared<CMockSimpleShape>(frame);
	shape2->GetFillStyle()->SetColor(Colors::Yellow);
	shape2->GetFillStyle()->SetEnabled(false);

	shapeGroup.InsertShape(shape1);
	shapeGroup.InsertShape(shape2);

	CHECK(shapeGroup.GetFillStyle()->GetColor() == nullopt);
	CHECK(shapeGroup.GetFillStyle()->IsEnabled() == nullopt);
}

TEST_CASE("get shape group fill style options")
{
	CShapeGroup shapeGroup;
	RectD frame{ 10.56, 12.45 };

	shared_ptr<IShape> shape1 = make_shared<CMockSimpleShape>(frame);
	shape1->GetFillStyle()->SetColor(Colors::Red);
	shape1->GetFillStyle()->SetEnabled(false);

	shared_ptr<IShape> shape2 = make_shared<CMockSimpleShape>(frame);
	shape2->GetFillStyle()->SetColor(Colors::Red);
	shape2->GetFillStyle()->SetEnabled(false);

	shapeGroup.InsertShape(shape1);
	shapeGroup.InsertShape(shape2);

	CHECK(shapeGroup.GetFillStyle()->GetColor() == Colors::Red);
	CHECK_FALSE(*shapeGroup.GetFillStyle()->IsEnabled());
}

TEST_CASE("get undefined shape group outline style options")
{
	CShapeGroup shapeGroup;
	RectD frame{ 10.56, 12.45 };

	shared_ptr<IShape> shape1 = make_shared<CMockSimpleShape>(frame);
	shape1->GetOutlineStyle()->SetColor(Colors::Red);
	shape1->GetOutlineStyle()->SetEnabled(true);
	shape1->GetOutlineStyle()->SetThickness(1.0);

	shared_ptr<IShape> shape2 = make_shared<CMockSimpleShape>(frame);
	shape2->GetOutlineStyle()->SetColor(Colors::Yellow);
	shape2->GetOutlineStyle()->SetEnabled(false);
	shape2->GetOutlineStyle()->SetThickness(5.0);

	shapeGroup.InsertShape(shape1);
	shapeGroup.InsertShape(shape2);

	CHECK(shapeGroup.GetOutlineStyle()->GetColor() == nullopt);
	CHECK(shapeGroup.GetOutlineStyle()->IsEnabled() == nullopt);
	CHECK(shapeGroup.GetOutlineStyle()->GetThickness() == nullopt);
}

TEST_CASE("get shape group outline style options")
{
	CShapeGroup shapeGroup;
	RectD frame{ 10.56, 12.45 };

	shared_ptr<IShape> shape1 = make_shared<CMockSimpleShape>(frame);
	shape1->GetOutlineStyle()->SetColor(Colors::Red);
	shape1->GetOutlineStyle()->SetEnabled(true);
	shape1->GetOutlineStyle()->SetThickness(1.0);

	shared_ptr<IShape> shape2 = make_shared<CMockSimpleShape>(frame);
	shape2->GetOutlineStyle()->SetColor(Colors::Red);
	shape2->GetOutlineStyle()->SetEnabled(true);
	shape2->GetOutlineStyle()->SetThickness(1.0);

	shapeGroup.InsertShape(shape1);
	shapeGroup.InsertShape(shape2);

	CHECK(shapeGroup.GetOutlineStyle()->GetColor() == Colors::Red);
	CHECK(*shapeGroup.GetOutlineStyle()->IsEnabled());
	CHECK(shapeGroup.GetOutlineStyle()->GetThickness() == 1.0);
}

TEST_CASE("get itself from try get group method")
{
	auto shape = make_shared<CShapeGroup>();
	CHECK(shape == shape->TryGetGroup());
}

TEST_CASE("modify shape group with interfaces")
{
	auto shape = make_shared<CShapeGroup>();

	auto shapeGroupInterface1 = shape->TryGetGroup();
	auto shaprGroupInterface2 = shape->TryGetGroup();

	RectD frame{ 10.56, 12.45 };

	shared_ptr<IShape> shape1 = make_shared<CMockSimpleShape>(frame);
	shapeGroupInterface1->InsertShape(shape1);

	CHECK(shape->GetShapesCount() == 1);
	CHECK(shape->GetShapeAtIndex(0) == shape1);

	shaprGroupInterface2->RemoveShapeAtIndex(0);

	CHECK(shape->GetShapesCount() == 0);
}

TEST_CASE("get shape group frame")
{
	CShapeGroup shapeGroup;

	CHECK(IsRectsEqual(shapeGroup.GetFrame(), RectD{ 0, 0, 0, 0 }));

	shared_ptr<IShape> shape1 = make_shared<CMockSimpleShape>(RectD{ 10, 10, 30, 20 });
	shared_ptr<IShape> shape2 = make_shared<CMockSimpleShape>(RectD{ 30, 20, 30, 20 });

	shapeGroup.InsertShape(shape1);
	shapeGroup.InsertShape(shape2);

	CHECK(IsRectsEqual(shapeGroup.GetFrame(), RectD{ 10, 10, 50, 30 }));
}

TEST_CASE("set shape group frame")
{

}
