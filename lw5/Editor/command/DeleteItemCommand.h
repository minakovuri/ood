#pragma once
#include<optional>
#include "../document/DocumentItem.h"
#include "AbstractCommand.h"

using namespace std;

class CDeleteItemCommand : public CAbstractCommand
{
public:
	CDeleteItemCommand(vector<CDocumentItem>& items, size_t index);
	~CDeleteItemCommand();

protected:
	void DoExecute() override;
	void DoUnexecute() override;

private:
	vector<CDocumentItem>& m_items;
	size_t m_index;
	optional<filesystem::path> m_imageFilePath;
};