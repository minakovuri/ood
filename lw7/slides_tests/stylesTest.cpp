#include "../../catch.hpp"
#include "../slides/shapes/styles/FillStyle.h"
#include "../slides/shapes/styles/OutlineStyle.h"
#include "Colors.h"

using namespace std;

TEST_CASE("create fill style with color")
{
	CFillStyle style(Colors::Red, true);
	CHECK(*style.IsEnabled());
	CHECK(*style.GetColor() == Colors::Red);
}

TEST_CASE("create fill style")
{
	CFillStyle style;
	CHECK_FALSE(*style.IsEnabled());
	CHECK(*style.GetColor() == Colors::White);
}

TEST_CASE("set fill style color")
{
	CFillStyle style;
	style.SetColor(Colors::Blue);
	CHECK(*style.GetColor() == Colors::Blue);
}

TEST_CASE("set fill style enable")
{
	CFillStyle style;
	style.SetEnabled(true);
	CHECK(*style.IsEnabled());
}

TEST_CASE("create enabled outline style with color and thikness")
{
	COutlineStyle style(Colors::Yellow, true, 2.0);
	CHECK(*style.IsEnabled());
	CHECK(*style.GetColor() == Colors::Yellow);
	CHECK(*style.GetThickness() == 2.0);
}

TEST_CASE("create outline style")
{
	COutlineStyle style;
	CHECK(*style.IsEnabled());
	CHECK(*style.GetColor() == Colors::Black);
	CHECK(*style.GetThickness() == 1.0);
}

TEST_CASE("set outline style color")
{
	COutlineStyle style;
	style.SetColor(Colors::Pink);
	CHECK(*style.GetColor() == Colors::Pink);
}

TEST_CASE("set outline style enable")
{
	COutlineStyle style;
	style.SetEnabled(false);
	CHECK_FALSE(*style.IsEnabled());
}

TEST_CASE("set outline style thickness")
{
	COutlineStyle style;
	style.SetThickness(5.5);
	CHECK(*style.GetThickness() == 5.5);
}
