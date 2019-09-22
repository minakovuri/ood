#include "CDecryptionInputStream.h"

CDecryptionInputStream::CDecryptionInputStream(IInputDataStreamPtr&& stream, CReplacementTable& table)
	: CInputStreamDecorator(std::move(stream))
	, m_table(table)
{
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

uint8_t CDecryptionInputStream::DecryptByte(uint8_t byte) const
{
	return m_table.Decrypt(byte);
}
