#include "../../catch.hpp"
#include "../Editor/document/ConstDocumentItem.h"
#include "../Editor/document/DocumentItem.h"

using namespace std;

// надо вынести в отдельный файл - используется в нескольких тестах (commandTests)
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

// надо вынести в отдельный файл - используется в нескольких тестах (commandTests)
class CMockParagraph : public IParagraph
{
public:
	string GetText() const
	{
		return string();
	}

	void SetText(const string& text) {}
};

TEST_CASE("create const document image item")
{
	auto image = make_shared<CMockImage>();
	CConstDocumentItem::Item item{ image };

	CConstDocumentItem constDocumentItem(item);
	CHECK(constDocumentItem.GetImage() == image);
	CHECK(constDocumentItem.GetParagraph() == nullptr);
}

TEST_CASE("create const document paragraph item")
{
	auto paragraph = make_shared<CMockParagraph>();
	CConstDocumentItem::Item item{ paragraph };

	CConstDocumentItem constDocumentItem(item);
	CHECK(constDocumentItem.GetImage() == nullptr);
	CHECK(constDocumentItem.GetParagraph() == paragraph);
}

TEST_CASE("create document image item")
{
	auto image = make_shared<CMockImage>();
	CDocumentItem::Item item{ image };

	CDocumentItem documentItem(item);
	CHECK(documentItem.GetImage() == image);
	CHECK(documentItem.GetParagraph() == nullptr);
}

TEST_CASE("create document paragraph item")
{
	auto paragraph = make_shared<CMockParagraph>();
	CDocumentItem::Item item{ paragraph };

	CDocumentItem documentItem(item);
	CHECK(documentItem.GetImage() == nullptr);
	CHECK(documentItem.GetParagraph() == paragraph);
}
