#pragma once
#include "CInputStreamDecorator.h"

class CDecryptionInputStream : public CInputStreamDecorator
{
public:
	CDecryptionInputStream(IInputDataStreamPtr&& stream, unsigned int key);

	uint8_t ReadByte() final;
	std::streamsize ReadBlock(void* dstBuffer, std::streamsize size) final;

private:
	uint8_t DecryptByte(uint8_t byte) const;

	unsigned int m_key;
};