#pragma once
#include <memory>
#include "image/IImage.h"
#include "paragraph/IParagraph.h"

class CConstDocumentItem
{
public:
	// ���������� ��������� �� ����������� �����������, ���� nullptr,
	// ���� ������� �� �������� ������������
	std::shared_ptr<const IImage> GetImage()const;
	// ���������� ��������� �� ����������� ��������, ���� nullptr, ���� ������� �� �������� ����������
	std::shared_ptr<const IParagraph> GetParagraph()const;

	virtual ~CConstDocumentItem() = default;
};
