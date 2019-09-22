#pragma once
#include <numeric>
#include <random>
#include <vector>

class CReplacementTable
{
public:
	CReplacementTable(unsigned int key)
		: m_encryptTable(256)
		, m_decryptTable(256)
	{
		std::mt19937 gen;
		gen.seed(key);

		for (size_t i = 0; i < 255; ++i)
		{
			m_encryptTable[i] = gen();
			m_decryptTable[m_encryptTable[i]] = static_cast<uint8_t>(i);
		}
	}

	uint8_t Encrypt(uint8_t byte) const
	{
		return m_encryptTable.at(byte);
	}

	uint8_t Decrypt(uint8_t byte) const
	{
		return m_decryptTable.at(byte);
	}

private:
	std::vector<uint8_t> m_encryptTable, m_decryptTable;
};
