#include "CEncryptionOutputStream.h"
#include <cstdlib>
#include <numeric>
#include <random>

CEncryptionOutputStream::CEncryptionOutputStream(IOutputDataStreamPtr&& stream, unsigned key)
	: COutputStreamDecorator(std::move(stream))
	, m_encryptTable(256)
{
	GenerateEncryptTable(key);
}

void CEncryptionOutputStream::WriteByte(uint8_t data)
{
	uint8_t encryptData = EncryptByte(data);
	m_stream->WriteByte(encryptData);
}

void CEncryptionOutputStream::WriteBlock(const void* srcData, std::streamsize size)
{
	auto allocMemPtr = static_cast<uint8_t*>(std::malloc((size_t)(size)));
	auto buffPtr = static_cast<const uint8_t*>(srcData);

	for (std::streamsize i = 0; i < size; ++i)
	{
		*(allocMemPtr + i) = EncryptByte(*(buffPtr++));
	}

	m_stream->WriteBlock(allocMemPtr, size);
	std::free(allocMemPtr);
}

void CEncryptionOutputStream::GenerateEncryptTable(unsigned key)
{
	std::iota(m_encryptTable.begin(), m_encryptTable.end(), 0);
	std::shuffle(m_encryptTable.begin(), m_encryptTable.end(), std::mt19937(key));
}

uint8_t CEncryptionOutputStream::EncryptByte(uint8_t byte) const
{
	return m_encryptTable.at(byte);
}
