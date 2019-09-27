#pragma once
#include "COutputStreamDecorator.h"

class CCompressedOutputStream : public COutputStreamDecorator
{
public:
	CCompressedOutputStream(IOutputDataStreamPtr&& stream)
};