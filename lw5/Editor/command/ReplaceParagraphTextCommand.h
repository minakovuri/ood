#pragma once
#include "../document/paragraph/IParagraph.h"
#include "AbstractCommand.h"

using namespace std;

class CReplaceParagraphTextCommand : public CAbstractCommand
{
public:
	CReplaceParagraphTextCommand(shared_ptr<IParagraph> paragraph, const string& text);

protected:
	void DoExecute() override;
	void DoUnexecute() override;

private:
	shared_ptr<IParagraph> m_paragraph;

	string m_text;
	string m_newText;
};
