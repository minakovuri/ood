#pragma once
#include "ConstDocumentItem.h"
#include "DocumentItem.h"
#include "image/IImage.h"
#include "paragraph/IParagraph.h"
#include <memory>
#include <optional>
#include <string>

using namespace std;

class IDocument
{
public:
	// ��������� �������� ������ � ��������� ������� (������� ����������� ��������)
	// ���� �������� position �� ������, ������� ���������� � ����� ���������
	virtual shared_ptr<IParagraph> InsertParagraph(const string& text, optional<size_t> position = std::nullopt) = 0;

	//// ��������� ����������� � ��������� ������� (������� ����������� ��������)
	//// �������� path ������ ���� � ������������ �����������
	//// ��� ������� ����������� ������ ������������ � ���������� images
	//// ��� ������������� ��������������� ������
	virtual shared_ptr<IImage> InsertImage(const std::string& path, int width, int height, optional<size_t> position = std::nullopt) = 0;

	//// ���������� ���������� ��������� � ���������
	virtual size_t GetItemsCount() const = 0;

	//// ������ � ��������� �����������
	virtual CConstDocumentItem GetItem(size_t index) const = 0;
	virtual CDocumentItem GetItem(size_t index) = 0;

	//// ������� ������� �� ���������
	virtual void DeleteItem(size_t index) = 0;

	// ���������� ��������� ���������
	virtual std::string GetTitle() const = 0;
	// �������� ��������� ���������
	virtual void SetTitle(const std::string& title) = 0;

	// �������� � ����������� �������� Undo
	virtual bool CanUndo() const = 0;
	// �������� ������� ��������������
	virtual void Undo() = 0;

	// �������� � ����������� �������� Redo
	virtual bool CanRedo() const = 0;
	// ��������� ���������� ������� ��������������
	virtual void Redo() = 0;

	//// ��������� �������� � ������� html. ����������� ����������� � ���������� images.
	//// ���� � ������������ ����������� ������������ ���� � ������������ HTML �����
	virtual void Save(const std::string& path) const = 0;

	virtual ~IDocument() = default;
};

typedef std::unique_ptr<IDocument> IDocumentPtr;
