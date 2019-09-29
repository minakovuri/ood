#pragma once
#include "CInputStreamDecorator.h"
#include <queue>

class CDecompressedInputStream : public CInputStreamDecorator
{
public:
	CDecompressedInputStream(IInputDataStreamPtr&& stream);

	bool IsEOF() const final;
	uint8_t ReadByte() final;
	std::streamsize ReadBlock(void* dstBuffer, std::streamsize size) final;

private:
	void ExpandBuffer(std::streamsize size);

	std::queue<uint8_t> m_bytesBuffer;
};