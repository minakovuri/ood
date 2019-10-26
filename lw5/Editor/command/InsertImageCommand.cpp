#include "InsertImageCommand.h"
#include "../document/image/Image.h"
#include <random>

std::string GetRandomString(size_t length)
{
	const std::string characters = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

	std::random_device random_device;
	std::mt19937 generator(random_device());
	std::uniform_int_distribution<> distribution(0, (int)(characters.size() - 1));

	std::string random_string;

	for (std::size_t i = 0; i < length; ++i)
	{
		random_string += characters[distribution(generator)];
	}

	return random_string;
}

CInsertImageCommand::CInsertImageCommand(filesystem::path path, int width, int height, filesystem::path dirPath, vector<CDocumentItem>& items, optional<size_t> position)
	: m_items(items)
	, m_position(position)
{
	m_image = SaveImage(path, dirPath, width, height);
}

CInsertImageCommand::~CInsertImageCommand()
{
	if (!IsExecuted())
	{
		auto filePath = m_image->GetPath();
		filesystem::remove(filePath);
	}
}

void CInsertImageCommand::DoExecute()
{
	if (m_position >= m_items.size())
	{
		throw logic_error("cannot insert image to the position greater than number of items");
	}

	auto imageItem = CDocumentItem(m_image);

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
	if (m_position == nullopt)
	{
		m_items.pop_back();
	}
	else
	{
		m_items.erase(m_items.begin() + *m_position);
	}
}

shared_ptr<IImage> CInsertImageCommand::SaveImage(filesystem::path originalFilePath, filesystem::path imagesDirPath, int width, int height)
{
	if (!filesystem::exists(originalFilePath))
	{
		throw invalid_argument("invalid file path!");
	}

	if (!filesystem::exists(imagesDirPath) || !filesystem::is_directory(imagesDirPath))
	{
		filesystem::create_directory(imagesDirPath);
	}

	auto fileExtension = originalFilePath.extension();
	auto fileName = GetRandomString(5) + fileExtension.string();
	auto filePath = imagesDirPath.string() + "/" + fileName;

	filesystem::copy_file(originalFilePath, filePath);

	return make_shared<CImage>(filePath, width, height);
}
