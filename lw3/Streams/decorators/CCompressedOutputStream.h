#pragma once
#include "COutputStreamDecorator.h"
#include "Chunk.h"

class CCompressedOutputStream : public COutputStreamDecorator
{
public:
	CCompressedOutputStream(IOutputDataStreamPtr&& stream);

	void WriteByte(uint8_t data) final;
	void WriteBlock(const void* srcData, std::streamsize size) final;

	~CCompressedOutputStream();

private:
	void InitChunk(uint8_t byte);
	void ResetChunk();
	void FlushChunk();

	std::unique_ptr<Chunk> m_chunk;
};