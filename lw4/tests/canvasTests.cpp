#include "../../catch.hpp"
#include "../Shapes/canvas/StreamCanvas.h"
#include <sstream>

using namespace std;

TEST_CASE("Draw green line")
{
	stringstream stream;
	CStreamCanvas canvas(stream);

	canvas.SetColor(Color::Green);
	canvas.DrawLine(Point{ 1, 1 }, Point{ 2, 2 });
	CHECK(stream.str() == "Draw Green line from {1;1} to {2;2}\n");
}

TEST_CASE("Draw blue ellipse")
{
	stringstream stream;
	CStreamCanvas canvas(stream);

	canvas.SetColor(Color::Blue);
	canvas.DrawEllipse(Point{ 10.5, 10 }, 5, 10);
	CHECK(stream.str() == "Draw Blue ellipse with left top at {10.5;10}, width 5 and height 10\n");
}
