#pragma once
#include "CInputStreamDecorator.h"
#include "CReplacementTable.h"

class CDecryptionInputStream : public CInputStreamDecorator
{
public:
	CDecryptionInputStream(IInputDataStreamPtr&& stream, CReplacementTable& table);

	uint8_t ReadByte() final;
	std::streamsize ReadBlock(void* dstBuffer, std::streamsize size) final;

private:
	uint8_t DecryptByte(uint8_t byte) const;

	CReplacementTable& m_table;
};