#pragma once
#include "../inputStream/IInputDataStream.h"

class CInputStreamDecorator : public IInputDataStream
{
public:
	bool IsEOF() const override
	{
		return m_stream->IsEOF();
	}

protected:
	CInputStreamDecorator(IInputDataStreamPtr&& stream)
		: m_stream(std::move(stream))
	{
	}

	IInputDataStreamPtr m_stream;
};
