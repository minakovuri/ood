#pragma once
#include "IInputDataStream.h"

class CMemoryInputStream : public IInputDataStream
{
	CMemoryInputStream() = default;

	bool IsEOF() const override;
	uint8_t ReadByte() override;
	std::streamsize ReadBlock(void* dstBuffer, std::streamsize size) override;

	~CMemoryInputStream() = default;
};