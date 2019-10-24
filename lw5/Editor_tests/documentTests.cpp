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

TEST_CASE("insert paragraph that changed document items order")
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

TEST_CASE("undo redo inserting image")
{
	CDocument document;
	auto image = document.InsertImage("image.jpg", 200, 250);
	auto imagePath = image->GetPath();

	document.Undo();
	CHECK(filesystem::exists(imagePath)); // удалили из документа, но не с диска
	CHECK(document.GetItemsCount() == 0);

	document.Redo();
	CHECK(filesystem::exists(imagePath));
	CHECK(document.GetItemsCount() == 1);
	CHECK(document.GetItem(0).GetImage() == image);
}

TEST_CASE("insert image that changed document items order")
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
}

TEST_CASE("delete paragraph")
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
	CHECK(filesystem::exists(image1->GetPath())); // удалили из документа, но не с диска
	CHECK(filesystem::exists(image2->GetPath()));
}

TEST_CASE("trying to delete unexisting item")
{
	CDocument document;
	CHECK_THROWS(document.DeleteItem(1));
}

TEST_CASE("save document with title, paragraph and image to html file")
{
	string filePath = "index.html";

	CDocument document;

	document.SetTitle("My Page!<script>console.log('title')</script>");
	auto paragraph = document.InsertParagraph("My name is Yury!");
	auto image = document.InsertImage("image.jpg", 200, 250);
	auto paragraphWithScript = document.InsertParagraph("<script>console.log('paragraph')</script>");

	document.Save(filePath);

	ifstream stream(filePath);
	string str((istreambuf_iterator<char>(stream)), istreambuf_iterator<char>());

	auto imgSrc = image->GetPath();

	std::ostringstream stringStream;
	stringStream << "<html>" << endl
				 << "<head>" << endl
				 << "<title>My Page!&lt;script&gt;console.log(&apos;title&apos;)&lt;/script&gt;</title>" << endl
				 << "</head>" << endl
				 << "<body>" << endl
				 << "<p>My name is Yury!</p>" << endl
				 << "<img src=" << imgSrc << " width=\"200\" height=\"250\" />" << endl
				 << "<p>&lt;script&gt;console.log(&apos;paragraph&apos;)&lt;/script&gt;</p>" << endl
				 << "</body>" << endl
				 << "</html>" << endl;

	CHECK(str == stringStream.str());
}

TEST_CASE("undo redo history test")
{
	CDocument document;
	
	auto image1 = document.InsertImage("image.jpg", 200, 250); // 1
	auto image1Path = image1->GetPath();

	document.SetTitle("Title"); // 2
	auto par1 = document.InsertParagraph("firsrt paragraph"); // 3
	auto par2 = document.InsertParagraph("second paragraph"); // 4

	auto image2 = document.InsertImage("image.jpg", 200, 250); // 5
	auto image2Path = image2->GetPath();

	document.DeleteItem(0); // 6

	document.Undo();
	CHECK(filesystem::exists(image1Path)); // удалили картинку из документа, но не с диска

	document.Undo();
	CHECK(filesystem::exists(image2Path)); // отменили вставку картинки из документа, но не с диска 

	document.SetTitle("New Title"); // 5` - команды 5 и 6 должны стереться из истории
	CHECK(filesystem::exists(image1Path)); // отмена 6 операции (удаления) не привело к удалению файла
	CHECK(!filesystem::exists(image2Path)); // отмена 5 команды (вставка) привело к удалению файла

}
