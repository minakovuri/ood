#include "../../catch.hpp"
#include "../ClassAdapter/app.h"
#include <sstream>

using namespace std;

TEST_CASE("render line")
{
	stringstream stream;
	app::CModernCanvasAdapter adapter(stream);

	adapter.BeginDraw();
	adapter.MoveTo(50, 50);
	adapter.LineTo(100, 100);
	adapter.EndDraw();

	string expectedStr = "<draw>\n"
						 "  <line fromX=\"50\" fromY=\"50\" toX=\"100\" toY=\"100\"/>\n"
						 "</draw>\n";

	CHECK(stream.str() == expectedStr);
}

TEST_CASE("trying to render line without begin drawing")
{
	stringstream stream;
	app::CModernCanvasAdapter adapter(stream);

	CHECK_THROWS(adapter.LineTo(100, 100));
}

TEST_CASE("trying to begin drawing multiple times")
{
	stringstream stream;
	app::CModernCanvasAdapter adapter(stream);

	adapter.BeginDraw();
	CHECK_THROWS(adapter.BeginDraw());
}

TEST_CASE("trying to end drawing without starting")
{
	stringstream stream;
	app::CModernCanvasAdapter adapter(stream);

	CHECK_THROWS(adapter.EndDraw());
}