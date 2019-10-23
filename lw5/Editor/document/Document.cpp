#include <fstream>
#include <boost/format.hpp>
#include "Document.h"
#include "paragraph/Paragraph.h"
#include "image/Image.h"
#include "../command/ChangeStringCommand.h"
#include "../command/InsertParagraphCommand.h"
#include "../command/InsertImageCommand.h"
#include "../command/DeleteItemCommand.h"

using namespace std;

const string IMAGES_DIR = "images";

shared_ptr<IParagraph> CDocument::InsertParagraph(const string& text, optional<size_t> position)
{
	m_history.AddAndExecuteCommand(make_unique<CInsertParagraphCommand>(text, m_items, position));

	size_t index = m_items.size() - 1;
	if (position != nullopt)
	{
		index = *position;
	}

	return m_items[index].GetParagraph();
}

shared_ptr<IImage> CDocument::InsertImage(const std::string& path, int width, int height, optional<size_t> position)
{
	m_history.AddAndExecuteCommand(make_unique<CInsertImageCommand>(path, width, height, IMAGES_DIR, m_items, position));

	size_t index = m_items.size() - 1;
	if (position != nullopt)
	{
		index = *position;
	}

	return m_items[index].GetImage();
}

size_t CDocument::GetItemsCount() const
{
	return m_items.size();
}

CConstDocumentItem CDocument::GetItem(size_t index) const
{
	return m_items[index];
}

CDocumentItem CDocument::GetItem(size_t index)
{
	return m_items[index];
}

void CDocument::DeleteItem(size_t index)
{
	m_history.AddAndExecuteCommand(make_unique<CDeleteItemCommand>(m_items, index));
}

void CDocument::SetTitle(const std::string& title)
{
	m_history.AddAndExecuteCommand(make_unique<CChangeStringCommand>(m_title, title));
}

std::string CDocument::GetTitle() const
{
	return m_title;
}

bool CDocument::CanUndo() const
{
	return m_history.CanUndo();
}

void CDocument::Undo()
{
	m_history.Undo();
}

bool CDocument::CanRedo() const
{
	return m_history.CanRedo();
}

void CDocument::Redo()
{
	m_history.Redo();
}

void CDocument::Save(const std::string& path) const
{
	std::ofstream html(path);

	html << "<html>" << std::endl;
	html << "<head>" << std::endl;
	html << "<title>" << m_title << "</title>" << std::endl;
	html << "</head>" << std::endl;
	html << "<body>" << std::endl;

	for (size_t i = 0; i < m_items.size(); ++i)
	{
		auto item = m_items[i];

		if (auto image = item.GetImage())
		{
			auto src = image->GetPath();
			auto width = image->GetWidth();
			auto height = image->GetHeight();

			html << boost::format(R"(<img src=%1% width="%2%" height="%3%" />)") % src % width % height << std::endl;
		}
		else
		{
			auto paragraph = item.GetParagraph();
			std::string text = paragraph->GetText();
			html << boost::format(R"(<p>%1%</p>)") % text << std::endl;
		}
	}

	html << "</body>" << std::endl;
	html << "</html>" << std::endl;
}
