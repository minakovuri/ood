#include "CMemoryOutputStream.h"

CMemoryOutputStream::CMemoryOutputStream(std::vector<uint8_t>& memoryStream)
	: m_memoryStream(memoryStream)
{
}

void CMemoryOutputStream::WriteByte(uint8_t data)
{
	try
	{
		m_memoryStream.push_back(data);
	}
	catch (const std::exception&)
	{
		throw std::ios_base::failure("canno't write byte to stream");
	}

	m_pos++;
}

void CMemoryOutputStream::WriteBlock(const void* srcData, std::streamsize size)
{
	auto buffPtr = static_cast<const uint8_t*>(srcData);

	for (std::streamsize i = 0; i < size; ++i)
	{
		try
		{
			WriteByte(static_cast<uint8_t>(*(buffPtr++)));
		}
		catch (const std::exception&)
		{
			throw std::ios_base::failure("canno't write block of bytes byte to stream");
		}
	}
}
