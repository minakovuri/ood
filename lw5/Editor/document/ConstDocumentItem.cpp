#include "ConstDocumentItem.h"

CConstDocumentItem::CConstDocumentItem(Item item)
	: m_item(item)
{
}

CConstDocumentItem::ImagePtr CConstDocumentItem::GetImage() const
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

CConstDocumentItem::ParagraphPtr CConstDocumentItem::GetParagraph() const
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
