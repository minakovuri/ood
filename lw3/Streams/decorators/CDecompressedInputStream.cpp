#include "CDecompressedInputStream.h"

CDecompressedInputStream::CDecompressedInputStream(IInputDataStreamPtr&& stream)
	: CInputStreamDecorator(std::move(stream))
{
}

bool CDecompressedInputStream::IsEOF() const
{
	return m_stream->IsEOF() && m_bytesBuffer.empty();
}

uint8_t CDecompressedInputStream::ReadByte()
{
	ExpandBuffer(1);
	auto byte = m_bytesBuffer.front();
	m_bytesBuffer.pop();
	return byte;
}

std::streamsize CDecompressedInputStream::ReadBlock(void* dstBuffer, std::streamsize size)
{
	ExpandBuffer(size);

	auto buffPtr = static_cast<uint8_t*>(dstBuffer);

	std::streamsize realSize = 0;

	for (auto it = buffPtr; (it < buffPtr + size) && (m_bytesBuffer.size()); it++)
	{
		*it = m_bytesBuffer.front();
		m_bytesBuffer.pop();
		realSize++;
	}

	return realSize;
}

void CDecompressedInputStream::ExpandBuffer(std::streamsize size)
{
	while (m_bytesBuffer.size() < static_cast<size_t>(size))
	{
		uint8_t firstByte = m_stream->ReadByte();
		uint8_t secondByte = m_stream->ReadByte();

		for (size_t i = 0; i < firstByte; ++i)
		{
			m_bytesBuffer.push(secondByte);
		}
	}
}
