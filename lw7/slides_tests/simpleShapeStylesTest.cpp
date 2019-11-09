#include "../../catch.hpp"
#include "../slides/shapes/styles/SimpleShapeFillStyle.h"
#include "../slides/shapes/styles/SimpleShapeOutlineStyle.h"
#include "Colors.h"

using namespace std;

TEST_CASE("create simple shape enabled fill style with color")
{
	CSimpleShapeFillStyle style(Colors::Red, true);
	CHECK(*style.IsEnabled());
	CHECK(*style.GetColor() == Colors::Red);
}

TEST_CASE("create simple shape fill style")
{
	CSimpleShapeFillStyle style;
	CHECK_FALSE(*style.IsEnabled());
	CHECK(*style.GetColor() == Colors::White);
}

TEST_CASE("set fill style color")
{
	CSimpleShapeFillStyle style;
	style.SetColor(Colors::Blue);
	CHECK(*style.GetColor() == Colors::Blue);
}

TEST_CASE("set fill style enable")
{
	CSimpleShapeFillStyle style;
	style.SetEnabled(true);
	CHECK(*style.IsEnabled());
}

TEST_CASE("create simple shape enabled outline style with color and thikness")
{
	CSimpleShapeOutlineStyle style(Colors::Yellow, true, 2.0);
	CHECK(*style.IsEnabled());
	CHECK(*style.GetColor() == Colors::Yellow);
	CHECK(*style.GetThickness() == 2.0);
}

TEST_CASE("create simple shape outline")
{
	CSimpleShapeOutlineStyle style;
	CHECK(*style.IsEnabled());
	CHECK(*style.GetColor() == Colors::Black);
	CHECK(*style.GetThickness() == 1.0);
}

TEST_CASE("set outline style color")
{
	CSimpleShapeOutlineStyle style;
	style.SetColor(Colors::Pink);
	CHECK(*style.GetColor() == Colors::Pink);
}

TEST_CASE("set outline style enable")
{
	CSimpleShapeOutlineStyle style;
	style.SetEnabled(false);
	CHECK_FALSE(*style.IsEnabled());
}

TEST_CASE("set outline style thickness")
{
	CSimpleShapeOutlineStyle style;
	style.SetThickness(5.5);
	CHECK(*style.GetThickness() == 5.5);
}
