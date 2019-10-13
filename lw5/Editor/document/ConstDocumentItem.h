#pragma once
#include <memory>
#include "image/IImage.h"
#include "paragraph/IParagraph.h"

class CConstDocumentItem
{
public:
	// Возвращает указатель на константное изображение, либо nullptr,
	// если элемент не является изображением
	std::shared_ptr<const IImage> GetImage()const;
	// Возвращает указатель на константный параграф, либо nullptr, если элемент не является параграфом
	std::shared_ptr<const IParagraph> GetParagraph()const;

	virtual ~CConstDocumentItem() = default;
};
