#include "CCompressedOutputStream.h"

CCompressedOutputStream::CCompressedOutputStream(IOutputDataStreamPtr&& stream)
	: COutputStreamDecorator(std::move(stream))
{
}

void CCompressedOutputStream::WriteByte(uint8_t data)
{
	if (!m_chunk)
	{
		InitChunk(data);
		return;
	}

	if ((data == m_chunk->byte) && (m_chunk->bytesConter < std::numeric_limits<uint8_t>::max()))
	{
		m_chunk->bytesConter++;
		return;
	}

	FlushChunk();
}

void CCompressedOutputStream::WriteBlock(const void* srcData, std::streamsize size)
{
	auto buffPtr = static_cast<const uint8_t*>(srcData);

	for (std::streamsize i = 0; i < size; ++i)
	{
		WriteByte((*buffPtr++));
	}
}

CCompressedOutputStream::~CCompressedOutputStream()
{
	FlushChunk();
}

void CCompressedOutputStream::InitChunk(uint8_t byte)
{
	m_chunk = std::make_unique<Chunk>();
	m_chunk->byte = byte;
	m_chunk->bytesConter = 1;
}

void CCompressedOutputStream::ResetChunk()
{
	m_chunk.reset();
}

void CCompressedOutputStream::FlushChunk()
{
	m_stream->WriteBlock(m_chunk.get(), 2);
	ResetChunk();
}
