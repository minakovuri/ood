#include "DocumentItem.h"

CDocumentItem::CDocumentItem(CConstDocumentItem::Item item)
	: CConstDocumentItem(item)
{
}

CDocumentItem::ImagePtr CDocumentItem::GetImage()
{
	try
	{
		return std::get<std::shared_ptr<IImage>>(m_item);
	}
	catch (std::bad_variant_access&)
	{
		return nullptr;
	}
}

CDocumentItem::ParagraphPtr CDocumentItem::GetParagraph()
{
	try
	{
		return std::get<std::shared_ptr<IParagraph>>(m_item);
	}
	catch (std::bad_variant_access&)
	{
		return nullptr;
	}
}
