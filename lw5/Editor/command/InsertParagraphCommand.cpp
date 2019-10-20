#include <stdexcept>
#include "InsertParagraphCommand.h"

CInsertParagraphCommand::CInsertParagraphCommand(shared_ptr<IParagraph>&& paragraph, vector<CDocumentItem>& items, optional<size_t> position)
	: m_paragraph(paragraph)
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

	auto documentItem = CDocumentItem(m_paragraph);

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
