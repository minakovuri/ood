#pragma once
#include "IOutputDataStream.h"

class CMemoryOutputStream : public IOutputDataStream
{
public:
	CMemoryOutputStream() = default;

	void WriteByte(uint8_t data) override;
	void WriteBlock(const void* srcData, std::streamsize size) override;

	~CMemoryOutputStream() = default;
};