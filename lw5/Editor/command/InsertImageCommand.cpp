#include <random>
#include "InsertImageCommand.h"
#include "../document/image/Image.h"

std::string GetRandomString(size_t length)
{
	const std::string characters = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

	std::random_device random_device;
	std::mt19937 generator(random_device());
	std::uniform_int_distribution<> distribution(0, characters.size() - 1);

	std::string random_string;

	for (std::size_t i = 0; i < length; ++i)
	{
		random_string += characters[distribution(generator)];
	}

	return random_string;
}

CInsertImageCommand::CInsertImageCommand(CHistory& history, filesystem::path path, int width, int height, filesystem::path dirPath, vector<CDocumentItem>& items, optional<size_t> position)
	: m_history(history)
	, m_path(path)
	, m_width(width)
	, m_height(height)
	, m_dirPath(dirPath)
	, m_items(items)
	, m_position(position)
{
	m_newFileName = GetRandomString(5);
}

void CInsertImageCommand::DoExecute()
{
	if (m_position >= m_items.size())
	{
		throw logic_error("cannot insert image to the position greater than number of items");
	}

	auto image = SaveImage();
	auto imageItem = CDocumentItem(image);

	if (m_position == nullopt)
	{
		m_items.emplace_back(imageItem);
	}
	else
	{
		m_items.emplace(m_items.begin() + *m_position, imageItem);
	}
}

void CInsertImageCommand::DoUnexecute()
{
	auto filePath = GetFilePath();

	filesystem::remove(filePath);

	if (m_position == nullopt)
	{
		m_items.pop_back();
	}
	else
	{
		m_items.erase(m_items.begin() + *m_position);
	}
}

shared_ptr<IImage> CInsertImageCommand::SaveImage()
{
	if (!filesystem::exists(m_dirPath) || !filesystem::is_directory(m_dirPath))
	{
		filesystem::create_directory(m_dirPath);
	}

	char tempFileName[L_tmpnam_s];
	tmpnam_s(tempFileName, L_tmpnam_s);

	auto filePath = GetFilePath();

	filesystem::copy_file(m_path, filePath);
	return make_shared<CImage>(m_history, filePath, m_width, m_height);
}

filesystem::path CInsertImageCommand::GetFilePath()
{
	auto fileExtension = m_path.extension();
	auto fileName = m_newFileName.string() + fileExtension.string();
	return m_dirPath.string() + "/" + fileName;
}
