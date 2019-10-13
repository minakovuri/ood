#pragma once
#include "document/Document.h"
#include "menu/Menu.h"

using namespace std;

class CEditor
{
public:
	CEditor()
		: m_document(make_unique<CDocument>())
	{
	}

	void Start()
	{
		m_menu.Run();
	}

private:
	CMenu m_menu;
	IDocumentPtr m_document;
};