#pragma once
#include <vector>
#include <functional>
#include "History.h"
#include "IDocument.h"
#include "ConstDocumentItem.h"
#include "DocumentItem.h"
#include "../HtmlSaver.h"

using namespace std;

class CDocument : public IDocument
{
public:
	typedef function<void(const string& path, const string& title, const vector<CDocumentItem>& items)> SaveFn;

	CDocument(SaveFn saveFn = SaveToHtmlFunction);

	shared_ptr<IParagraph> InsertParagraph(const string& text, optional<size_t> position = nullopt) override;
	shared_ptr<IImage> InsertImage(const string& path, int width, int height, optional<size_t> position = nullopt) override;

	size_t GetItemsCount() const override;

	CConstDocumentItem GetItem(size_t index) const override;
	CDocumentItem GetItem(size_t index) override;

	void DeleteItem(size_t index) override;

	void SetTitle(const string& title) override;
	string GetTitle() const override;

	bool CanUndo() const override;
	void Undo() override;
	bool CanRedo() const override;
	void Redo() override;

	void Save(const string& path) const;

private:
	string m_title;
	vector<CDocumentItem> m_items;
	CHistory m_history;
	SaveFn m_saveFn;
};
