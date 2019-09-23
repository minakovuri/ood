#include "CEncryptionOutputStream.h"
#include <cstdlib>

CEncryptionOutputStream::CEncryptionOutputStream(IOutputDataStreamPtr&& stream, CReplacementTable& table)
	: COutputStreamDecorator(std::move(stream))
	, m_table(table)
{
}

void CEncryptionOutputStream::WriteByte(uint8_t data)
{
	uint8_t encryptData = EncryptByte(data);
	m_stream->WriteByte(encryptData);
}

void CEncryptionOutputStream::WriteBlock(const void* srcData, std::streamsize size)
{
	auto allocMemPtr = static_cast<uint8_t*>(std::malloc(size));
	auto buffPtr = static_cast<const uint8_t*>(srcData);

	for (std::streamsize i = 0; i < size; ++i)
	{
		*(allocMemPtr + i) = EncryptByte(*(buffPtr++));
	}

	m_stream->WriteBlock(allocMemPtr, size);
	std::free(allocMemPtr);
}

uint8_t CEncryptionOutputStream::EncryptByte(uint8_t byte) const
{
	return m_table.Encrypt(byte);
}
