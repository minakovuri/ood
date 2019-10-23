#include "../../catch.hpp"
#include "../Editor/document/paragraph/Paragraph.h"

using namespace std;

TEST_CASE("set paragraph text")
{
	CParagraph paragraph;
	CHECK(paragraph.GetText() == "");
	paragraph.SetText("some text");
	CHECK(paragraph.GetText() == "some text");
}

TEST_CASE("create paragraph with init text")
{
	CParagraph paragraph("some text");
	CHECK(paragraph.GetText() == "some text");
	paragraph.SetText("new text");
	CHECK(paragraph.GetText() == "new text");
}

TEST_CASE("set paragraph text twice")
{
	CParagraph paragraph;
	paragraph.SetText("some text 1");
	CHECK(paragraph.GetText() == "some text 1");
	paragraph.SetText("some text 2");
	CHECK(paragraph.GetText() == "some text 2");
}