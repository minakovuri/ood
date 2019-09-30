#pragma once
#include <vector>
#include "IOutputDataStream.h"

class CMemoryOutputStream : public IOutputDataStream
{
public:
	CMemoryOutputStream(std::vector<uint8_t>& memoryStream);

	void WriteByte(uint8_t data) override;
	void WriteBlock(const void* srcData, std::streamsize size) override;

private:
	std::vector<uint8_t>& m_memoryStream;
};