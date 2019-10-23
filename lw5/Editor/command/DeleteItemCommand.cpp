#include "DeleteItemCommand.h"

CDeleteItemCommand::CDeleteItemCommand(vector<CDocumentItem>& items, size_t index)
	: m_items(items)
	, m_index(index)
{
}

void CDeleteItemCommand::DoExecute()
{
}

void CDeleteItemCommand::DoUnexecute()
{
}
