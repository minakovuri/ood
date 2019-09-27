#pragma once
#include "CInputStreamDecorator.h"
#include <vector>

class CDecryptionInputStream : public CInputStreamDecorator
{
public:
	CDecryptionInputStream(IInputDataStreamPtr&& stream, unsigned key);

	uint8_t ReadByte() final;
	std::streamsize ReadBlock(void* dstBuffer, std::streamsize size) final;

private:
	void GenerateDecryptTable(unsigned key);
	uint8_t DecryptByte(uint8_t byte) const;

	std::vector<uint8_t> m_decryptTable;
};