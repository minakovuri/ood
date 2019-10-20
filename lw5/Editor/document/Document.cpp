#include "Document.h"
#include "paragraph/Paragraph.h"
#include "image/Image.h"
#include "../command/ChangeStringCommand.h"
#include "../command/InsertParagraphCommand.h"
#include "../command/InsertImageCommand.h"

using namespace std;

shared_ptr<IParagraph> CDocument::InsertParagraph(const string& text, optional<size_t> position)
{
	auto paragraph = make_shared<CParagraph>(m_history);
	paragraph->SetText(text);

	m_history.AddAndExecuteCommand(make_unique<CInsertParagraphCommand>(paragraph, m_items, position));
	return paragraph;
}

shared_ptr<IImage> CDocument::InsertImage(const std::string& path, int width, int height, optional<size_t> position)
{
	m_history.AddAndExecuteCommand(make_unique<CInsertImageCommand>(m_history, path, width, height, "images", m_items, position));

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
}
