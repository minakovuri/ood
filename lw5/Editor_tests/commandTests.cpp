#include "../../catch.hpp"
#include "../Editor/command/ChangeStringCommand.h"
#include "../Editor/command/InsertParagraphCommand.h"
#include "../Editor/command/ResizeImageCommand.h"

using namespace std;

class CMockImage : public IImage
{
public:
	Path GetPath() const
	{
		return Path();
	}

	int GetWidth() const
	{
		return 0;
	}

	int GetHeight() const
	{
		return 0;
	}

	void Resize(int width, int height) {}
};

class CMockParagraph : public IParagraph
{
public:
	string GetText() const
	{
		return string();
	}

	void SetText(const string& text) {}
};

TEST_CASE("change string with command")
{
	string str = "hello";
	CChangeStringCommand changeStringCommand(str, "world");

	changeStringCommand.Execute();
	CHECK(str == "world");

	changeStringCommand.Unexecute();
	CHECK(str == "hello");
}

TEST_CASE("resize image with command")
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

TEST_CASE("insert paragraph at the end of items")
{
	auto paragraph = make_shared<CMockParagraph>();
	vector<CDocumentItem> items;

	CInsertParagraphCommand command(paragraph, items);
	command.Execute();

	CHECK(items[0].GetParagraph() == paragraph);
}

TEST_CASE("insert paragraph that changed items order")
{
	auto paragraph1 = make_shared<CMockParagraph>();
	auto paragraph2 = make_shared<CMockParagraph>();
	auto paragraph3 = make_shared<CMockParagraph>();

	vector<CDocumentItem> items;

	CInsertParagraphCommand command1(paragraph1, items);
	CInsertParagraphCommand command2(paragraph2, items);
	CInsertParagraphCommand command3(paragraph3, items, 1);

	command1.Execute();
	command2.Execute();
	command3.Execute();

	CHECK(items[0].GetParagraph() == paragraph1);
	CHECK(items[1].GetParagraph() == paragraph3);
	CHECK(items[2].GetParagraph() == paragraph2);
}

TEST_CASE("trying to insert paragraph to invalid position")
{
	auto paragraph = make_shared<CMockParagraph>();
	vector<CDocumentItem> items;
	CInsertParagraphCommand command(paragraph, items, 1);

	CHECK_THROWS(command.Execute());
}

TEST_CASE("undo inserting paragraph")
{
	auto paragraph1 = make_shared<CMockParagraph>();
	auto paragraph2 = make_shared<CMockParagraph>();

	vector<CDocumentItem> items;

	CInsertParagraphCommand command1(paragraph1, items);
	CInsertParagraphCommand command2(paragraph2, items, 0);

	command1.Execute();
	command2.Execute();

	command2.Unexecute();
	CHECK(items[0].GetParagraph() == paragraph1);

	command1.Unexecute();
	CHECK(items.size() == 0);
}