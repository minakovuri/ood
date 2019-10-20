#pragma once
#include <vector>
#include "History.h"
#include "IDocument.h"
#include "ConstDocumentItem.h"
#include "DocumentItem.h"

class CDocument : public IDocument
{
public:
	shared_ptr<IParagraph> InsertParagraph(const string& text, optional<size_t> position = std::nullopt) override;
	shared_ptr<IImage> InsertImage(const std::string& path, int width, int height, optional<size_t> position = std::nullopt) override;

	size_t GetItemsCount() const override;

	CConstDocumentItem GetItem(size_t index) const override;
	CDocumentItem GetItem(size_t index) override;

	void DeleteItem(size_t index) override;

	void SetTitle(const std::string& title) override;
	std::string GetTitle() const override;

	bool CanUndo() const override;
	void Undo() override;
	bool CanRedo() const override;
	void Redo() override;

	void Save(const std::string& path) const;

private:
	std::string m_title;
	std::vector<CDocumentItem> m_items;
	CHistory m_history;
};
