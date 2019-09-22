#include "CMemoryInputStream.h"

CMemoryInputStream::CMemoryInputStream(std::vector<uint8_t>& memoryStream)
	: m_memoryStream(memoryStream)
{
}

bool CMemoryInputStream::IsEOF() const
{
	return m_pos == m_memoryStream.size();
}

uint8_t CMemoryInputStream::ReadByte()
{
	if (m_pos >= m_memoryStream.size())
	{
		throw std::ios_base::failure("canno't read byte from memory");
	}

	return m_memoryStream[m_pos++];
}

std::streamsize CMemoryInputStream::ReadBlock(void* dstBuffer, std::streamsize size)
{
	auto buffPtr = static_cast<uint8_t*>(dstBuffer);

	if (m_pos + size > m_memoryStream.size())
	{
		size = m_memoryStream.size() - m_pos;
	}

	for (std::streamsize i = 0; i < size; ++i)
	{
		*(buffPtr++) = m_memoryStream[m_pos++];
	}

	return size;
}
