#include "../../catch.hpp"
#include "../Editor/document/History.h"
#include "../Editor/document/paragraph/Paragraph.h"

using namespace std;

TEST_CASE("set paragraph text")
{
	CHistory history;
	CParagraph paragraph(history);

	CHECK(paragraph.GetText() == "");
	paragraph.SetText("some text");
	CHECK(paragraph.GetText() == "some text");
}

TEST_CASE("set paragraph text twice")
{
	CHistory history;
	CParagraph paragraph(history);

	paragraph.SetText("some text 1");
	CHECK(paragraph.GetText() == "some text 1");

	paragraph.SetText("some text 2");
	CHECK(paragraph.GetText() == "some text 2");
}