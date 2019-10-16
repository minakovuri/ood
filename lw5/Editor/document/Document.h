#pragma once
#include "History.h"
#include "IDocument.h"

class CDocument : public IDocument
{
public:
	shared_ptr<IParagraph> InsertParagraph(const string& text, optional<size_t> position = std::nullopt) final;
	shared_ptr<IImage> InsertImage(const std::string& path, int width, int height, optional<size_t> position = std::nullopt) final;

	size_t GetItemsCount() const final;

	CConstDocumentItem GetItem(size_t index) const final;
	CDocumentItem GetItem(size_t index) final;

	void DeleteItem(size_t index) final;

	void SetTitle(const std::string& title) final;
	std::string GetTitle() const final;

	bool CanUndo() const final;
	void Undo() final;
	bool CanRedo() const final;
	void Redo() final;

private:
	std::string m_title;
	CHistory m_history;
};
