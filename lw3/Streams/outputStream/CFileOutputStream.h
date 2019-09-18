#pragma once
#include "IOutputDataStream.h"

class CFileOutputStream : public IOutputDataStream
{
public:
	CFileOutputStream() = default;

	void WriteByte(uint8_t data) override;
	void WriteBlock(const void* srcData, std::streamsize size) override;

	~CFileOutputStream() = default;
};