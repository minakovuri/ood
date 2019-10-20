#pragma once
#include "../document/DocumentItem.h"
#include "AbstractCommand.h"
#include <optional>

using namespace std;

class CInsertParagraphCommand : public CAbstractCommand
{
public:
	CInsertParagraphCommand(shared_ptr<IParagraph>&& paragraph, vector<CDocumentItem>& items, optional<size_t> position = nullopt);

protected:
	void DoExecute() override;
	void DoUnexecute() override;

private:
	shared_ptr<IParagraph> m_paragraph;
	vector<CDocumentItem>& m_items;
	optional<size_t> m_position;
};
