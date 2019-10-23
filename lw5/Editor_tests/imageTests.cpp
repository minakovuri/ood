#include "../../catch.hpp"
#include "../Editor/document/image/Image.h"
#include <stdexcept>

using namespace std;

TEST_CASE("create image")
{
	CImage image("./image.jpg", 300, 400);

	CHECK(image.GetPath().compare("./image.jpg") == 0);
	CHECK(image.GetWidth() == 300);
	CHECK(image.GetHeight() == 400);
}

TEST_CASE("trying to create image with invalid extension")
{
	CHECK_THROWS_AS(CImage("./file.txt", 300, 400), invalid_argument);
}

TEST_CASE("trying to create image with negative size")
{
	CHECK_THROWS_AS(CImage("./image.png", -10, 400), invalid_argument);
	CHECK_THROWS_AS(CImage("./image.png", 300, -10), invalid_argument);
}

TEST_CASE("resize image")
{
	CImage image("./image.jpg", 300, 400);

	image.Resize(800, 600);
	CHECK(image.GetWidth() == 800);
	CHECK(image.GetHeight() == 600);
}

TEST_CASE("trying to resize image with negative values")
{
	CImage image("./image.jpg", 300, 400);
	CHECK_THROWS_AS(image.Resize(-100, 300), invalid_argument);
	CHECK_THROWS_AS(image.Resize(300, -100), invalid_argument);
}