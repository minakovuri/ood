#include "DeleteItemCommand.h"
#include "../document/DocumentItem.h"

CDeleteItemCommand::CDeleteItemCommand(vector<CDocumentItem>& items, size_t index)
	: m_items(items)
	, m_index(index)
{
}

CDeleteItemCommand::~CDeleteItemCommand()
{
	if (!IsExecuted())
	{
		return;
	}

	auto image = CDocumentItem(m_items[m_index]).GetImage();

	if (image)
	{
		auto filePath = image->GetPath();
		filesystem::remove(filePath);
	}
}

void CDeleteItemCommand::DoExecute()
{
	if (m_index >= m_items.size())
	{
		throw logic_error("cannot delete unexisting item");
	}

	m_items.erase(m_items.begin() + m_index);
}

void CDeleteItemCommand::DoUnexecute()
{
	auto item = CDocumentItem(m_items[m_index]);
	m_items.emplace(m_items.begin() + m_index, item);
}
