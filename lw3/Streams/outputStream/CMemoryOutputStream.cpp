#include "CMemoryOutputStream.h"

CMemoryOutputStream::CMemoryOutputStream(std::vector<uint8_t>& memoryStream)
	: m_memoryStream(memoryStream)
{
}

void CMemoryOutputStream::WriteByte(uint8_t data)
{
	if (m_pos >= m_memoryStream.capacity())
	{
		throw std::ios_base::failure("canno't write byte to stream");
	}

	m_memoryStream.push_back(data);
	m_pos++;
}

void CMemoryOutputStream::WriteBlock(const void* srcData, std::streamsize size)
{
	if (m_pos + size > m_memoryStream.capacity())
	{
		throw std::ios_base::failure("canno't write block of byte to stream");
	}

	auto buffPtr = static_cast<const uint8_t*>(srcData);

	for (std::streamsize i = 0; i < size; ++i)
	{
		m_memoryStream.push_back(*(buffPtr++));
		m_pos++;
	}
}
