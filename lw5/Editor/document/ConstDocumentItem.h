#pragma once
#include "image/IImage.h"
#include "paragraph/IParagraph.h"
#include <memory>
#include <variant>

class CConstDocumentItem
{
public:
	CConstDocumentItem() = default; // выпилить

	typedef std::shared_ptr<const IImage> ImagePtr;
	typedef std::shared_ptr<const IParagraph> ParagraphPtr;

	typedef std::variant<std::shared_ptr<IImage>, std::shared_ptr<IParagraph>> Item;

	CConstDocumentItem(Item item);

	ImagePtr GetImage() const;
	ParagraphPtr GetParagraph() const;

	virtual ~CConstDocumentItem() = default;

protected:
	Item m_item;
};
