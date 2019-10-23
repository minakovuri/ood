#include <stdexcept>
#include "../document/paragraph/Paragraph.h"
#include "InsertParagraphCommand.h"

CInsertParagraphCommand::CInsertParagraphCommand(const string& text, vector<CDocumentItem>& items, optional<size_t> position)
	: m_text(text)
	, m_items(items)
	, m_position(position)
{
}

void CInsertParagraphCommand::DoExecute()
{
	if (m_position >= m_items.size())
	{
		throw logic_error("cannot insert paragraph to the position greater than number of items");
	}

	auto paragraph = make_shared<CParagraph>(m_text);
	auto documentItem = CDocumentItem(paragraph);

	if (m_position == nullopt)
	{
		m_items.emplace_back(documentItem);
	}
	else
	{
		m_items.emplace(m_items.begin() + *m_position, documentItem);
	}
}

void CInsertParagraphCommand::DoUnexecute()
{
	if (m_position == nullopt)
	{
		m_items.pop_back();
	}
	else
	{
		m_items.erase(m_items.begin() + *m_position);
	}
}
