#pragma once
#include <filesystem>
#include <string>

class IImage
{
public:
	typedef std::filesystem::path Path;

	virtual Path GetPath() const = 0;
	virtual int GetWidth() const = 0;
	virtual int GetHeight() const = 0;

	virtual void Resize(int width, int height) = 0;

	virtual ~IImage() = default;
};
