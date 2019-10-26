#include "ReplaceParagraphTextCommand.h"

CReplaceParagraphTextCommand::CReplaceParagraphTextCommand(shared_ptr<IParagraph> paragraph, const string& text)
	: m_paragraph(paragraph)
	, m_newText(text)
{
	m_text = paragraph->GetText();
}

void CReplaceParagraphTextCommand::DoExecute()
{
	m_paragraph->SetText(m_newText);
}

void CReplaceParagraphTextCommand::DoUnexecute()
{
	m_paragraph->SetText(m_text);
}
