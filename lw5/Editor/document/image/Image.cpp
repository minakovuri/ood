#include "Image.h"
#include "../../command/ResizeImageCommand.h"
#include <stdexcept>

const std::string JPG = ".jpg";
const std::string PNG = ".png";
const std::string GIF = ".gif";

CImage::CImage(Path path, int width, int height)
{
	if (!IsExtensionValid(path))
	{
		throw std::invalid_argument("image file extension is invalid");
	}

	if (width < 0 || height < 0)
	{
		throw std::invalid_argument("image size is negative");
	}

	m_path = path;
	m_width = width;
	m_height = height;
}

IImage::Path CImage::GetPath() const
{
	return m_path;
}

int CImage::GetWidth() const
{
	return m_width;
}

int CImage::GetHeight() const
{
	return m_height;
}

void CImage::Resize(int width, int height)
{
	if (width < 0 || height < 0)
	{
		throw std::invalid_argument("image size will be negative after resize");
	}

	m_width = width;
	m_height = height;
}

bool CImage::IsExtensionValid(Path path) const
{
	auto extension = path.extension();
	return (extension == JPG || extension == PNG || extension == GIF);
}
