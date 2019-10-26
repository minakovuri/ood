#include <iostream>
#include "Editor.h"
#include "HtmlSaver.h"

using namespace std::placeholders;

CEditor::CEditor()
	: m_document(make_unique<CDocument>(SaveToHtmlFunction))
{
	AddMenuItem("insertParagraph", "Inserting paragraph. Args: <position>|end <text>", &CEditor::InsertParagraph);
	AddMenuItem("insertImage", "Inserting image. Args: <position>|end <width> <height> <path>", &CEditor::InsertImage);
	m_menu.AddItem("help", "Help", [this](istream&) { m_menu.ShowInstructions(); });
	m_menu.AddItem("exit", "Exit", [this](istream&) { m_menu.Exit(); });
	AddMenuItem("setTitle", "Changes title. Args: <new title>", &CEditor::SetTitle);
	AddMenuItem("list", "Show document", &CEditor::List);
	AddMenuItem("replaceText", "Replace paragraph text. Args: <position> <text>", &CEditor::ReplaceText);
	AddMenuItem("resizeImage", "Resize image. Args: <position> <width> <height>", &CEditor::ResizeImage);
	AddMenuItem("deleteItem", "Delete item. Args: <position>", &CEditor::DeleteItem);
	AddMenuItem("undo", "Undo command", &CEditor::Undo);
	AddMenuItem("redo", "Redo undone command", &CEditor::Redo);
	AddMenuItem("save", "Save to HTML file. Args: <path>", &CEditor::Save);
}

void CEditor::Start()
{
	m_menu.Run();
}

void CEditor::AddMenuItem(const string& shortcut, const string& description, MenuHandler handler)
{
	m_menu.AddItem(shortcut, description, bind(handler, this, _1));
}

void CEditor::InsertParagraph(istream& in)
{
	string positionStr;
	string text;

	if (!((in >> positionStr) && getline(in, text)))
	{
		cerr << "invalid arguments for command InsertParagraph <position>|end <text>" << endl;
		return;
	}

	optional<size_t> position = nullopt;
	if (positionStr != "end")
	{
		position = stoi(positionStr);
	}

	try
	{
		m_document->InsertParagraph(text, position);
	}
	catch (const std::exception& e)
	{
		cerr << e.what() << endl;
	}
}

void CEditor::InsertImage(istream& in)
{
	string positionStr;
	int width = 0;
	int height = 0;
	string path;

	if (!((in >> positionStr) && (in >> width) && (in >> height) && (in >> path)))
	{
		cerr << "invalid arguments for command InsertImage <position>|end <width> <height> <path>" << endl;
		return;
	}

	optional<size_t> position = nullopt;
	if (positionStr != "end")
	{
		position = stoi(positionStr);
	}

	try
	{
		m_document->InsertImage(path, width, height, position);
	}
	catch (const exception& e)
	{
		cerr << e.what() << endl;
	}
}

void CEditor::SetTitle(istream& in)
{
	string head;
	string tail;

	if (in >> head)
	{
		getline(in, tail);
	}
	string title = head + tail;

	m_document->SetTitle(title);
}

void CEditor::List(istream&)
{
	cout << "  Title: " << m_document->GetTitle() << endl;

	for (size_t i = 0; i < m_document->GetItemsCount(); i++)
	{
		cout << "  " << i << ". ";
		auto item = m_document->GetItem(i);
		if (auto paragraph = item.GetParagraph())
		{
			cout << "Paragraph: " << paragraph->GetText() << std::endl;
		}

		if (auto image = item.GetImage())
		{
			cout << "Image: " << image->GetWidth() << " " << image->GetHeight() << " " << image->GetPath() << std::endl;
		}
	}
}

void CEditor::ReplaceText(istream& in)
{
	size_t position;
	string text;

	if (!((in >> position) && getline(in, text)))
	{
		cerr << "invalid arguments for command ReplaceText <position> <text>" << endl;
		return;
	}

	try
	{
		m_document->ReplaceParagraphText(position, text);
	}
	catch (const exception& e)
	{
		cerr << e.what() << endl;
	}
}

void CEditor::ResizeImage(istream& in)
{
	size_t position;
	int width;
	int height;

	if (!((in >> position) && (in >> width) && (in >> height)))
	{
		cerr << "invalid arguments for command ResizeImage <position> <width> <height>" << endl;
		return;
	}

	try
	{
		m_document->ResizeImage(position, width, height);
	}
	catch (const exception& e)
	{
		cerr << e.what() << endl;
	}
}

void CEditor::DeleteItem(istream& in)
{
	size_t position;

	if (!(in >> position))
	{
		cerr << "invalid arguments for command DeleteItem <position>" << endl;
		return;
	}

	try
	{
		m_document->DeleteItem(position);
	}
	catch (const exception& e)
	{
		cerr << e.what() << endl;
	}
}

void CEditor::Undo(istream&)
{
	if (m_document->CanUndo())
	{
		m_document->Undo();
	}
	else
	{
		cerr << "Can't undo" << endl;
	}
}

void CEditor::Redo(istream&)
{
	if (m_document->CanRedo())
	{
		m_document->Redo();
	}
	else
	{
		cerr << "Can't redo" << endl;
	}
}

void CEditor::Save(istream& in)
{
	string path;
	in >> path;
	m_document->Save(path);
}
