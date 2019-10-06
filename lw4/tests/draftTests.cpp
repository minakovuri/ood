#include "../../catch.hpp"
#include "../Shapes/draft/PictureDraft.h"
#include "../Shapes/shapes/Ellipse.h"
#include "../Shapes/shapes/Rectangle.h"
#include "../Shapes/shapes/RegularPolygon.h"
#include "../Shapes/shapes/Triangle.h"
#include "utils.h"

using namespace std;

TEST_CASE("Test picture draft")
{
	auto draft = make_unique<CPictureDraft>();

	CHECK(draft->IsEmpty());

	auto rectangle = make_unique<CRectangle>(Color::Black, Point{ 1, 1 }, Point{ 5, 5 });
	auto triangle = make_unique<CTriangle>(Color::Blue, Point{ 10, 5 }, Point{ 15, 10 }, Point{ 5, 30 });
	auto ellipse = make_unique<CEllipse>(Color::Pink, Point{ 5, 6 }, 10.50, 6.7);
	auto polygon = make_unique<CRegularPolygon>(Color::Green, Point{ 5, 5 }, 2, 5);

	draft->AddShape(move(rectangle));
	draft->AddShape(move(triangle));
	draft->AddShape(move(ellipse));
	draft->AddShape(move(polygon));

	CHECK(draft->GetShapesCount() == 4);

	{
		CShape& shape = draft->GetShape(0);
		CRectangle& rectangle = dynamic_cast<CRectangle&>(shape);
		CHECK(rectangle.GetColor() == Color::Black);
		CHECK(IsPointsEqual(rectangle.GetLeftTop(), Point{ 1, 1 }));
		CHECK(IsPointsEqual(rectangle.GetRightBottom(), Point{ 5, 5 }));
	}

	{
		CShape& shape = draft->GetShape(1);
		CTriangle& triangle = dynamic_cast<CTriangle&>(shape);
		CHECK(triangle.GetColor() == Color::Blue);
		CHECK(IsPointsEqual(triangle.GetVertex1(), Point{ 10, 5 }));
		CHECK(IsPointsEqual(triangle.GetVertex2(), Point{ 15, 10 }));
		CHECK(IsPointsEqual(triangle.GetVertex3(), Point{ 5, 30 }));
	}

	{
		CShape& shape = draft->GetShape(2);
		CEllipse& ellipse = dynamic_cast<CEllipse&>(shape);
		CHECK(ellipse.GetColor() == Color::Pink);
		CHECK(IsPointsEqual(ellipse.GetCenter(), Point{ 5, 6 }));
		CHECK(ellipse.GetHorizontalRadius() == 10.50);
		CHECK(ellipse.GetVerticalRadius() == 6.7);
	}

	{
		CShape& shape = draft->GetShape(3);
		CRegularPolygon& polygon = dynamic_cast<CRegularPolygon&>(shape);
		CHECK(polygon.GetColor() == Color::Green);
		CHECK(IsPointsEqual(polygon.GetCenter(), Point{ 5, 5 }));
		CHECK(polygon.GetRadius() == 2);
		CHECK(polygon.GetVertexCount() == 5);
	}

	CHECK_THROWS_AS(draft->GetShape(4), invalid_argument);
}
