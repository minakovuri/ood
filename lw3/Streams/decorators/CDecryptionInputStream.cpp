#include "CDecryptionInputStream.h"
#include <numeric>
#include <random>

CDecryptionInputStream::CDecryptionInputStream(IInputDataStreamPtr&& stream, unsigned long key)
	: CInputStreamDecorator(std::move(stream))
	, m_decryptTable(256)
{
	GenerateDecryptTable(key);
}

uint8_t CDecryptionInputStream::ReadByte()
{
	return DecryptByte(m_stream->ReadByte());
}

std::streamsize CDecryptionInputStream::ReadBlock(void* dstBuffer, std::streamsize size)
{
	auto bytesRead = m_stream->ReadBlock(dstBuffer, size);

	auto buffPtr = static_cast<uint8_t*>(dstBuffer);

	for (auto it = buffPtr; it < buffPtr + bytesRead; ++it)
	{
		*it = DecryptByte(*it);
	}

	return bytesRead;
}

void CDecryptionInputStream::GenerateDecryptTable(unsigned long key)
{
	std::vector<uint8_t> m_encryptTable(256);
	std::iota(m_encryptTable.begin(), m_encryptTable.end(), 0);
	std::shuffle(m_encryptTable.begin(), m_encryptTable.end(), std::mt19937(key));

	for (size_t i = 0; i < 256; ++i)
	{
		m_decryptTable[m_encryptTable[i]] = static_cast<uint8_t>(i);
	}
}

uint8_t CDecryptionInputStream::DecryptByte(uint8_t byte) const
{
	return m_decryptTable.at(byte);
}
