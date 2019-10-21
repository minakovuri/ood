#include "../../catch.hpp"
#include "../Editor/document/Document.h"
#include <filesystem>
#include <fstream>
#include <sstream>
#include <streambuf>

using namespace std;

TEST_CASE("insert paragraph to the end of document")
{
	CDocument document;
	auto paragraph = document.InsertParagraph("");
	CHECK(document.GetItemsCount() == 1);
	CHECK(document.GetItem(0).GetParagraph() == paragraph);
}

TEST_CASE("insert paragraph that changed document items oreder")
{
	CDocument document;

	auto paragraph1 = document.InsertParagraph("");
	auto paragraph2 = document.InsertParagraph("", 0);

	CHECK(document.GetItemsCount() == 2);
	CHECK(document.GetItem(0).GetParagraph() == paragraph2);
	CHECK(document.GetItem(1).GetParagraph() == paragraph1);
}

TEST_CASE("trying to insert paragraph into invalid position")
{
	CDocument document;
	CHECK_THROWS(document.InsertParagraph("", 1));
}

TEST_CASE("insert image to the end of document")
{
	CDocument document;
	auto image = document.InsertImage("image.jpg", 200, 250);
	CHECK(document.GetItemsCount() == 1);
	CHECK(document.GetItem(0).GetImage() == image);

	auto imagePath = image->GetPath();
	CHECK(filesystem::exists(imagePath));
}

TEST_CASE("undo inserting image")
{
	CDocument document;
	auto image = document.InsertImage("image.jpg", 200, 250);

	auto imagePath = image->GetPath();
	CHECK(filesystem::exists(imagePath));

	document.Undo();
	CHECK(!filesystem::exists(imagePath));
}

TEST_CASE("redo inserting image")
{
	CDocument document;
	auto image = document.InsertImage("image.jpg", 200, 250);
	auto imagePath = image->GetPath();

	document.Undo();
	CHECK(!filesystem::exists(imagePath));

	document.Redo();
	CHECK(filesystem::exists(imagePath));
}

/*TEST_CASE("insert image that changed document items order")
{
	CDocument document;
	auto image1 = document.InsertImage("image.jpg", 200, 250);
	auto image2 = document.InsertImage("image.jpg", 200, 250, 0);

	CHECK(document.GetItemsCount() == 2);
	CHECK(document.GetItem(0).GetImage() == image2);
	CHECK(document.GetItem(1).GetImage() == image1);
}

TEST_CASE("trying to insert image to invalid position")
{
	CDocument document;
	CHECK_THROWS(document.InsertImage("image.jpg", 200, 300, 1));
}

TEST_CASE("set title")
{
	CDocument document;
	document.SetTitle("Title");
	CHECK(document.GetTitle() == "Title");
}*/

/*TEST_CASE("delete paragraph")
{
	CDocument document;
	auto paragraph1 = document.InsertParagraph("");
	auto paragraph2 = document.InsertParagraph("");
	document.DeleteItem(0);

	CHECK(document.GetItemsCount() == 1);
	CHECK(document.GetItem(0).GetParagraph() == paragraph2);
}

TEST_CASE("delete image")
{
	CDocument document;
	auto image1 = document.InsertImage("image.jpg", 200, 250);
	auto image2 = document.InsertImage("image.jpg", 200, 250);
	document.DeleteItem(0);

	CHECK(document.GetItemsCount() == 1);
	CHECK(document.GetItem(0).GetImage() == image2);
	CHECK(!filesystem::exists(image1->GetPath()));
}

TEST_CASE("trying to delete unexisting item")
{
	CDocument document;
	CHECK_THROWS(document.DeleteItem(1));
}

TEST_CASE("undo and redo deleting image")
{
	CDocument document;
	auto image1 = document.InsertImage("image.jpg", 200, 250);
	auto image2 = document.InsertImage("image.jpg", 200, 250);

	document.DeleteItem(0);
	CHECK(!filesystem::exists(image1->GetPath()));
	CHECK(filesystem::exists(image2->GetPath()));

	document.Undo();
}*/

TEST_CASE("save document with title, paragraph and image to html file")
{
	string filePath = "index.html";

	CDocument document;

	document.SetTitle("My Page!");
	auto paragraph = document.InsertParagraph("My name is Yury!");
	auto image = document.InsertImage("image.jpg", 200, 250);

	document.Save(filePath);

	ifstream stream(filePath);
	string str((istreambuf_iterator<char>(stream)), istreambuf_iterator<char>());

	auto imgSrc = image->GetPath();
	auto width = image->GetWidth();
	auto height = image->GetHeight();

	std::ostringstream stringStream;
	stringStream << "<html>" << endl
				 << "<head>" << endl
				 << "<title>My Page!</title>" << endl
				 << "</head>" << endl
				 << "<body>" << endl
				 << "<p>My name is Yury!</p>" << endl
				 << "<img src=" << imgSrc << " width=\"" << width << "\" height=\"" << height << "\" />" << endl
				 << "</body>" << endl
				 << "</html>" << endl;

	CHECK(str == stringStream.str());
}

TEST_CASE("save paragraph with special symbols")
{

}
