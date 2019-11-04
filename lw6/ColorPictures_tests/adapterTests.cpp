#include "../../catch.hpp"
#include "../ColorPictures/app.h"
#include <sstream>

using namespace std;

TEST_CASE("render line with color")
{
	stringstream stream;
	modern_graphics_lib::CModernGraphicsRenderer modernGraphicsRenderer(stream);
	app::CModernCanvasAdapter adapter(modernGraphicsRenderer);

	adapter.SetColor(0x00AABB);
	adapter.BeginDraw();
	adapter.MoveTo(50, 50);
	adapter.LineTo(100, 100);
	adapter.EndDraw();

	string expectedStr = "<draw>\n"
						 "  <line fromX=\"50\" fromY=\"50\" toX=\"100\" toY=\"100\">\n"
						 "    <color r=\"0\" g=\"0.67\" b=\"0.73\" a=\"1\" />\n"
						 "  </line>\n"
						 "</draw>\n";

	CHECK(stream.str() == expectedStr);
}

TEST_CASE("render color with default color")
{
	stringstream stream;
	modern_graphics_lib::CModernGraphicsRenderer modernGraphicsRenderer(stream);
	app::CModernCanvasAdapter adapter(modernGraphicsRenderer);

	adapter.BeginDraw();
	adapter.MoveTo(50, 50);
	adapter.LineTo(100, 100);
	adapter.EndDraw();

	string expectedStr = "<draw>\n"
						 "  <line fromX=\"50\" fromY=\"50\" toX=\"100\" toY=\"100\">\n"
						 "    <color r=\"0\" g=\"0\" b=\"0\" a=\"1\" />\n"
						 "  </line>\n"
						 "</draw>\n";

	CHECK(stream.str() == expectedStr);
}

TEST_CASE("trying to render line without begin drawing")
{
	stringstream stream;
	modern_graphics_lib::CModernGraphicsRenderer modernGraphicsRenderer(stream);
	app::CModernCanvasAdapter adapter(modernGraphicsRenderer);

	CHECK_THROWS(adapter.LineTo(100, 100));
}

TEST_CASE("trying to begin drawing multiple times")
{
	stringstream stream;
	modern_graphics_lib::CModernGraphicsRenderer modernGraphicsRenderer(stream);
	app::CModernCanvasAdapter adapter(modernGraphicsRenderer);

	adapter.BeginDraw();
	CHECK_THROWS(adapter.BeginDraw());
}

TEST_CASE("trying to end drawing without starting")
{
	stringstream stream;
	modern_graphics_lib::CModernGraphicsRenderer modernGraphicsRenderer(stream);
	app::CModernCanvasAdapter adapter(modernGraphicsRenderer);

	CHECK_THROWS(adapter.EndDraw());
}