#include "../../catch.hpp"
#include "../Shapes/canvas/StreamCanvas.h"
#include <sstream>

using namespace std;

TEST_CASE("Test stream canvas")
{
	stringstream stream;

	CStreamCanvas canvas(stream);

	canvas.SetColor(Color::Green);
	canvas.DrawLine(Point{ 1, 1 }, Point{ 2, 2 });
	CHECK(stream.str() == "Draw Green line from {1;1} to {2;2}\n");

	stream = stringstream();
	canvas.SetColor(Color::Blue);
	canvas.DrawEllipse(Point{ 10.5, 10 }, 5, 10);
	CHECK(stream.str() == "Draw Blue ellipse with center in {10.5;10}, horizontal radius 5 and vertical radius 10\n");
}