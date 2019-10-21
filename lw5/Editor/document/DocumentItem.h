#pragma once
#include "ConstDocumentItem.h"

class CDocumentItem : public CConstDocumentItem
{
public:
	typedef std::shared_ptr<IImage> ImagePtr;
	typedef std::shared_ptr<IParagraph> ParagraphPtr;

	CDocumentItem(CConstDocumentItem::Item item);

	ImagePtr GetImage();
	ParagraphPtr GetParagraph();
};
