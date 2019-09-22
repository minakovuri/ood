#pragma once
#include <ios>
#include <stdint.h>

class IOutputDataStream
{
public:
	virtual void WriteByte(uint8_t data) = 0;
	virtual void WriteBlock(const void* srcData, std::streamsize size) = 0;

	virtual ~IOutputDataStream() = default;
};

typedef std::unique_ptr<IOutputDataStream> IOutputDataStreamPtr;
