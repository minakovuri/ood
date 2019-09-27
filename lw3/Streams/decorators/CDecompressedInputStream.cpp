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
	uint8_t byte;
	ReadBlock(&byte, 1);
	return byte;
}

std::streamsize CDecompressedInputStream::ReadBlock(void* dstBuffer, std::streamsize size)
{
	ExpandBuffer(size);

	auto buffPtr = static_cast<uint8_t*>(dstBuffer);

	for (auto it = buffPtr; it < buffPtr + size; it++)
	{
		*it = m_bytesBuffer.front();
		m_bytesBuffer.pop();
	}

	return size;
}

void CDecompressedInputStream::ExpandBuffer(std::streamsize size)
{
	while (m_bytesBuffer.size() < static_cast<size_t>(size))
	{
		uint8_t memory[2];
		m_stream->ReadBlock(&memory, 2);
		AddToBuffer(memory);
	}
}

void CDecompressedInputStream::AddToBuffer(uint8_t memory[2])
{
	uint8_t bytesCount = memory[0];
	uint8_t byte = memory[1];

	for (size_t i = 0; i < bytesCount; ++i)
	{
		m_bytesBuffer.push(byte);
	}
}
