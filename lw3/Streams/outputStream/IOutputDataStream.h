#pragma once
#include <ios>
#include <stdint.h>

class IOutputDataStream
{
public:
	// ���������� � ����� ������ ����
	// ����������� ���������� std::ios_base::failure � ������ ������
	virtual void WriteByte(uint8_t data) = 0;

	// ���������� � ����� ���� ������ �������� size ����,
	// ��������������� �� ������ srcData,
	// � ������ ������ ����������� ���������� std::ios_base::failure
	virtual void WriteBlock(const void* srcData, std::streamsize size) = 0;

	virtual ~IOutputDataStream() = default;
};
