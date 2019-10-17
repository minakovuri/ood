#include "../../catch.hpp"
#include "../Editor/command/ChangeStringCommand.h"
#include "../Editor/command/ResizeImageCommand.h"

using namespace std;

TEST_CASE("change string with command")
{
	string str = "hello";
	CChangeStringCommand changeStringCommand(str, "world");

	changeStringCommand.Execute();
	CHECK(str == "world");

	changeStringCommand.Unexecute();
	CHECK(str == "hello");
}

TEST_CASE("resize image width command")
{
	int width = 300;
	int height = 400;
	CResizeImageCommand resizeImageCommand(width, height, 600, 800);

	resizeImageCommand.Execute();
	CHECK(width == 600);
	CHECK(height == 800);

	resizeImageCommand.Unexecute();
	CHECK(width == 300);
	CHECK(height == 400);
}