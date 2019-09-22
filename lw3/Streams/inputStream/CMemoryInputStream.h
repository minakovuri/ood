#pragma once
#include <vector>
#include "IInputDataStream.h"

class CMemoryInputStream : public IInputDataStream
{
public:
	CMemoryInputStream(std::vector<uint8_t>& memoryStream);

	bool IsEOF() const override;
	uint8_t ReadByte() override;
	std::streamsize ReadBlock(void* dstBuffer, std::streamsize size) override;

private:
	std::vector<uint8_t>& m_memoryStream;
	size_t m_pos = 0;
};