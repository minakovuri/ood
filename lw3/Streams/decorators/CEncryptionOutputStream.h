#pragma once
#include <vector>
#include "COutputStreamDecorator.h"

class CEncryptionOutputStream : public COutputStreamDecorator
{
public:
	CEncryptionOutputStream(IOutputDataStreamPtr&& stream, unsigned key);

	void WriteByte(uint8_t data) final;
	void WriteBlock(const void* srcData, std::streamsize size) final;

private:
	void GenerateEncryptTable(unsigned key);
	uint8_t EncryptByte(uint8_t byte) const;

	std::vector<uint8_t> m_encryptTable;
};