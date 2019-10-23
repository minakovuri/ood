#pragma once
#include "AbstractCommand.h"
#include "../document/DocumentItem.h"
#include <optional>
#include <filesystem>

using namespace std;

class CInsertImageCommand : public CAbstractCommand
{
public:
	CInsertImageCommand(filesystem::path path, int width, int height, filesystem::path dirPath, vector<CDocumentItem>& items, optional<size_t> position = nullopt);
	~CInsertImageCommand();

protected:
	void DoExecute() override;
	void DoUnexecute() override;

private:
	shared_ptr<IImage> SaveImage(filesystem::path originalFilePath, filesystem::path imagesDirPath, int width, int height);

	vector<CDocumentItem>& m_items;
	optional<size_t> m_position;
	shared_ptr<IImage> m_image;
};