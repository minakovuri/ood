#pragma once
#include <fstream>
#include "IOutputDataStream.h"

class CFileOutputStream : public IOutputDataStream
{
public:
	CFileOutputStream(const std::string& fileName);

	void WriteByte(uint8_t data) override;
	void WriteBlock(const void* srcData, std::streamsize size) override;

private:
	std::ofstream m_outputFileStream;
};