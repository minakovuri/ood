#include "Paragraph.h"
#include "../../command/ChangeStringCommand.h"
#include <memory>

CParagraph::CParagraph(CHistory& history)
	: m_history(history)
{
}

std::string CParagraph::GetText() const
{
	return m_text;
}

void CParagraph::SetText(const std::string& text)
{
	m_history.AddAndExecuteCommand(std::make_unique<CChangeStringCommand>(m_text, text));
}
