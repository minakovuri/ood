#pragma once
#include "document/Document.h"
#include "menu/Menu.h"

using namespace std;

class CEditor
{
public:
	CEditor();

	void Start();

private:
	CMenu m_menu;
	IDocumentPtr m_document;
};
