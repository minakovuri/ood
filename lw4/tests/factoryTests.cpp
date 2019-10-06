#include "../../catch.hpp"
#include "../Shapes/factory/ShapeFactory.h"
#include "../Shapes/shapes/Ellipse.h"
#include "../Shapes/shapes/Rectangle.h"
#include "../Shapes/shapes/RegularPolygon.h"
#include "../Shapes/shapes/Triangle.h"
#include "utils.h"

using namespace std;

typedef unique_ptr<CRectangle> RectanglePtr;
typedef unique_ptr<CTriangle> TrianglePtr;
typedef unique_ptr<CEllipse> EllipsePtr;
typedef unique_ptr<CRegularPolygon> RegularPolygonPtr;

TEST_CASE("Test factory")
{
	auto shapeFactory = make_unique<CShapeFactory>();

	CHECK_THROWS_AS(shapeFactory->CreateShape(""), invalid_argument);
	CHECK_THROWS_AS(shapeFactory->CreateShape("Square 1.0;1.0 2.0;1.0 2.0;2.0 1.0;2.0"), invalid_argument);

	auto shapePtr = shapeFactory->CreateShape("Rectangle Red 5.1;5.1 10.2;10.2");
	CHECK(shapePtr->GetColor() == Color::Red);
	{
		CShape* shape = shapePtr.get();
		CRectangle* rectangle = dynamic_cast<CRectangle*>(shape);
		CHECK(IsPointsEqual(rectangle->GetLeftTop(), Point{ 5.1, 5.1 }));
		CHECK(IsPointsEqual(rectangle->GetRightBottom(), Point{ 10.2, 10.2 }));
	}
	CHECK_THROWS_AS(shapeFactory->CreateShape("Rectangle 5.1;5.1 10.2;10.2"), invalid_argument);

	shapePtr = shapeFactory->CreateShape("Triangle Green 1.0;1.0 3.0;1.0 2.0;5.0");
	CHECK(shapePtr->GetColor() == Color::Green);
	{
		CShape* shape = shapePtr.get();
		CTriangle* triangle = dynamic_cast<CTriangle*>(shape);
		CHECK(IsPointsEqual(triangle->GetVertex1(), Point{ 1.0, 1.0 }));
		CHECK(IsPointsEqual(triangle->GetVertex2(), Point{ 3.0, 1.0 }));
		CHECK(IsPointsEqual(triangle->GetVertex3(), Point{ 2.0, 5.0 }));
	}
	CHECK_THROWS_AS(shapeFactory->CreateShape("Triangle Black"), invalid_argument);

	shapePtr = shapeFactory->CreateShape("Ellipse Blue 5.0;6.5 10.2 5.6");
	CHECK(shapePtr->GetColor() == Color::Blue);
	{
		CShape* shape = shapePtr.get();
		CEllipse* ellipse = dynamic_cast<CEllipse*>(shape);
		CHECK(IsPointsEqual(ellipse->GetCenter(), Point{ 5.0, 6.5 }));
		CHECK(ellipse->GetHorizontalRadius() == 10.2);
		CHECK(ellipse->GetVerticalRadius() == 5.6);
	}
	CHECK_THROWS_AS(shapeFactory->CreateShape("Ellipse 5.0;6.5 10.2 5.6"), invalid_argument);

	shapePtr = shapeFactory->CreateShape("Polygon Yellow 5.0;5.0 2.0 5");
	CHECK(shapePtr->GetColor() == Color::Yellow);
	{
		CShape* shape = shapePtr.get();
		CRegularPolygon* polygon = dynamic_cast<CRegularPolygon*>(shape);
		CHECK(IsPointsEqual(polygon->GetCenter(), Point{ 5.0, 5.0 }));
		CHECK(polygon->GetRadius() == 2.0);
		CHECK(polygon->GetVertexCount() == 5);
	}

	CHECK_THROWS_AS(shapeFactory->CreateShape("Polygon Yellow 5.0;5.0 2.0 -5"), invalid_argument);
}
