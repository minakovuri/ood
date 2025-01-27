#include "CFileOutputStream.h"

CFileOutputStream::CFileOutputStream(const std::string& fileName)
	: m_outputFileStream(fileName, std::ios::binary)
{
	if (!m_outputFileStream)
	{
		throw std::ios_base::failure("failed to create/open file " + fileName);
	}
}

void CFileOutputStream::WriteByte(uint8_t data)
{
	WriteBlock(&data, 1);
}

void CFileOutputStream::WriteBlock(const void* srcData, std::streamsize size)
{
	if (!m_outputFileStream.write(static_cast<const char*>(srcData), size * sizeof(uint8_t)))
	{
		throw std::ios_base::failure("failed to write data");
	}
	m_outputFileStream.flush();
}
