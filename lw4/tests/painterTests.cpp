#include "../../catch.hpp"
#include "../Shapes/painter/Painter.h"
#include "../Shapes/draft/PictureDraft.h"
#include "../Shapes/shapes/Rectangle.h"
#include "../Shapes/canvas/StreamCanvas.h"
#include <sstream>

using namespace std;

TEST_CASE("Draw single shape")
{
	CPainter painter;

	CPictureDraft draft;
	auto rectangle = make_unique<CRectangle>(Color::Yellow, Point{ 1, 1 }, Point{ 5, 5 });
	draft.AddShape(move(rectangle));

	stringstream stream;
	CStreamCanvas streamCanvas(stream);
	painter.DrawPicture(draft, streamCanvas);

	string expectedOutput = "Draw Yellow line from {1;1} to {1;5}\n"; 
	expectedOutput += "Draw Yellow line from {1;5} to {5;5}\n";
	expectedOutput += "Draw Yellow line from {5;5} to {5;1}\n";
	expectedOutput += "Draw Yellow line from {5;1} to {1;1}\n";

	CHECK(stream.str() == expectedOutput);
}