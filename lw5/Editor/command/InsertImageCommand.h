#pragma once
#include "AbstractCommand.h"
#include "../document/DocumentItem.h"
#include "../document/History.h"
#include <optional>
#include <filesystem>

using namespace std;

class CInsertImageCommand : public CAbstractCommand
{
public:
	CInsertImageCommand(CHistory& history, filesystem::path path, int width, int height, filesystem::path dirPath, vector<CDocumentItem>& items, optional<size_t> position = nullopt);

protected:
	void DoExecute() override;
	void DoUnexecute() override;

private:
	shared_ptr<IImage> SaveImage();
	filesystem::path GetFilePath();

	vector<CDocumentItem>& m_items;
	optional<size_t> m_position;
	CHistory& m_history;

	filesystem::path m_path;
	int m_width;
	int m_height;
	filesystem::path m_dirPath;
	filesystem::path m_newFileName;
};