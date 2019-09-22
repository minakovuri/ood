#pragma once
#include "../outputStream/IOutputDataStream.h"

class COutputStreamDecorator : public IOutputDataStream
{
protected:
	COutputStreamDecorator(IOutputDataStreamPtr&& stream)
		: m_stream(std::move(stream))
	{
	}

	IOutputDataStreamPtr m_stream;
};
