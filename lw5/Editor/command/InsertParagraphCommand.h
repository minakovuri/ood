#pragma once
#include "../document/DocumentItem.h"
#include "AbstractCommand.h"
#include <optional>

using namespace std;

class CInsertParagraphCommand : public CAbstractCommand
{
public:
	CInsertParagraphCommand(const string& text, vector<CDocumentItem>& items, optional<size_t> position = nullopt);

protected:
	void DoExecute() override;
	void DoUnexecute() override;

private:
	string m_text;
	vector<CDocumentItem>& m_items;
	optional<size_t> m_position;
};
