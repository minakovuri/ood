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
	// ��������� �� ����� ������ CEditor, ����������� istream& � ������������ void
	typedef void (CEditor::*MenuHandler)(istream& in);

	void AddMenuItem(const string& shortcut, const string& description, MenuHandler handler);

	void SetTitle(istream& in);
	void List(istream&);
	void Undo(istream&);
	void Redo(istream&);

	CMenu m_menu;
	IDocumentPtr m_document;
};
