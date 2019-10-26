#include "DeleteItemCommand.h"
#include "../document/DocumentItem.h"

CDeleteItemCommand::CDeleteItemCommand(vector<CDocumentItem>& items, size_t index)
	: m_items(items)
	, m_index(index)
{
	if (m_index >= m_items.size())
	{
		throw logic_error("cannot delete unexisting item");
	}

	auto image = CDocumentItem(m_items[m_index]).GetImage();

	if (image)
	{
		m_imageFilePath = image->GetPath();
	}
	else
	{
		m_imageFilePath = nullopt;
	}
}

CDeleteItemCommand::~CDeleteItemCommand()
{
	if (!IsExecuted())
	{
		return;
	}

	if (m_imageFilePath)
	{
		filesystem::remove(*m_imageFilePath);
	}
}

void CDeleteItemCommand::DoExecute()
{
	m_items.erase(m_items.begin() + m_index);
}

void CDeleteItemCommand::DoUnexecute()
{
	auto item = CDocumentItem(m_items[m_index]);
	m_items.emplace(m_items.begin() + m_index, item);
}
