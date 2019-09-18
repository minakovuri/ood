#pragma once
#include <fstream>
#include "IInputDataStream.h"

class CFileInputStream : public IInputDataStream
{
public:
	CFileInputStream(const std::string& fileName);

	bool IsEOF() const override;
	uint8_t ReadByte() override;
	std::streamsize ReadBlock(void* dstBuffer, std::streamsize size) override;

private:
	std::ifstream m_inputFileStream;
};