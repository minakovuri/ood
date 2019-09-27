#pragma once
#include "COutputStreamDecorator.h"

class CCompressedOutputStream : public COutputStreamDecorator
{
public:
	CCompressedOutputStream(IOutputDataStreamPtr&& stream);

	void WriteByte(uint8_t data) final;
	void WriteBlock(const void* srcData, std::streamsize size) final;

	~CCompressedOutputStream();

private:
	struct Chunk
	{
		size_t bytesConter;
		uint8_t byte;
	};

	void InitChunk(uint8_t byte);
	void ResetChunk();
	void FlushChunk();

	std::unique_ptr<Chunk> m_chunk;
};