#pragma once
#include "COutputStreamDecorator.h"
#include "CReplacementTable.h"

class CEncryptionOutputStream : public COutputStreamDecorator
{
public:
	CEncryptionOutputStream(IOutputDataStreamPtr&& stream, CReplacementTable& table);

	void WriteByte(uint8_t data) final;
	void WriteBlock(const void* srcData, std::streamsize size) final;

private:
	uint8_t EncryptByte(uint8_t byte) const;

	CReplacementTable& m_table;
};