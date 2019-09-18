#include "CFileInputStream.h"

CFileInputStream::CFileInputStream(const std::string& fileName)
{
	m_inputFileStream.open(fileName.c_str(), std::ios::binary | std::ios::in);
	
	if (!m_inputFileStream.is_open())
	{
		throw std::ios_base::failure("failed to open file" + fileName);
	}
}

bool CFileInputStream::IsEOF() const
{
	return m_inputFileStream.eof();
}

uint8_t CFileInputStream::ReadByte()
{
	char x;
	m_inputFileStream.read(&x, 1);
	return (uint8_t)(x);
}

std::streamsize CFileInputStream::ReadBlock(void* dstBuffer, std::streamsize size)
{
	m_inputFileStream.read(static_cast<char*>(dstBuffer), size);
	return m_inputFileStream.gcount();
}
