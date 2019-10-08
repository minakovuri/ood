#include "../../catch.hpp"
#include "../Shapes/draft/PictureDraft.h"
#include "../Shapes/shapes/Ellipse.h"
#include "../Shapes/shapes/Rectangle.h"
#include "../Shapes/shapes/RegularPolygon.h"
#include "../Shapes/shapes/Triangle.h"
#include "utils.h"

using namespace std;

TEST_CASE("Create empty draft")
{
	auto draft = make_unique<CPictureDraft>();
	CHECK(draft->IsEmpty());
	CHECK(draft->GetShapesCount() == 0);
	CHECK_THROWS_AS(draft->GetShape(0), invalid_argument);
}

TEST_CASE("Create draft with single shape")
{
	auto draft = make_unique<CPictureDraft>();
	auto rectangle = make_unique<CRectangle>(Color::Black, Point{ 1, 1 }, Point{ 5, 5 });
	draft->AddShape(move(rectangle));
	CHECK(draft->GetShapesCount() == 1);

	CShape& shape = draft->GetShape(0);
	CRectangle& castedRectangle = dynamic_cast<CRectangle&>(shape);
	CHECK(castedRectangle.GetColor() == Color::Black);
	CHECK(IsPointsEqual(castedRectangle.GetLeftTop(), Point{ 1, 1 }));
	CHECK(IsPointsEqual(castedRectangle.GetRightBottom(), Point{ 5, 5 }));
}

TEST_CASE("Create draft with multiple shapes")
{
	auto draft = make_unique<CPictureDraft>();

	auto triangle = make_unique<CTriangle>(Color::Blue, Point{ 10, 5 }, Point{ 15, 10 }, Point{ 5, 30 });
	auto ellipse = make_unique<CEllipse>(Color::Pink, Point{ 5, 6 }, 10.50, 6.7);

	draft->AddShape(move(triangle));
	draft->AddShape(move(ellipse));
	CHECK(draft->GetShapesCount() == 2);

	{
		CShape& shape = draft->GetShape(0);
		CTriangle& triangle = dynamic_cast<CTriangle&>(shape);
		CHECK(triangle.GetColor() == Color::Blue);
		CHECK(IsPointsEqual(triangle.GetVertex1(), Point{ 10, 5 }));
		CHECK(IsPointsEqual(triangle.GetVertex2(), Point{ 15, 10 }));
		CHECK(IsPointsEqual(triangle.GetVertex3(), Point{ 5, 30 }));
	}

	{
		CShape& shape = draft->GetShape(1);
		CEllipse& ellipse = dynamic_cast<CEllipse&>(shape);
		CHECK(ellipse.GetColor() == Color::Pink);
		CHECK(IsPointsEqual(ellipse.GetCenter(), Point{ 5, 6 }));
		CHECK(ellipse.GetHorizontalRadius() == 10.50);
		CHECK(ellipse.GetVerticalRadius() == 6.7);
	}
}
