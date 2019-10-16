#include "Editor.h"

CEditor::CEditor()
	: m_document(make_unique<CDocument>())
{
}

void CEditor::Start()
{
	m_menu.Run();
}
