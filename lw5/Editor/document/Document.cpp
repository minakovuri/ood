#include "Document.h"
#include "../command/ChangeStringCommand.h"

using namespace std;

shared_ptr<IParagraph> CDocument::InsertParagraph(const string& text, optional<size_t> position)
{
	return shared_ptr<IParagraph>();
}

shared_ptr<IImage> CDocument::InsertImage(const std::string& path, int width, int height, optional<size_t> position)
{
	return shared_ptr<IImage>();
}

size_t CDocument::GetItemsCount() const
{
	return size_t();
}

CConstDocumentItem CDocument::GetItem(size_t index) const
{
	return CConstDocumentItem();
}

CDocumentItem CDocument::GetItem(size_t index)
{
	return CDocumentItem();
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