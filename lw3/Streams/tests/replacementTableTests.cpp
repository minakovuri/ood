#include "../../../catch.hpp"
#include "../decorators/CReplacementTable.h"

TEST_CASE("Test encryption and decryption with replacement table")
{
	unsigned key = std::rand();

	CReplacementTable table1(key);
	CReplacementTable table2(key);

	std::vector<uint8_t> input{ 'A', 'B', 'C' };

	for (auto byte : input)
	{
		uint8_t encryptByte = table1.Encrypt(byte);
		CHECK(encryptByte != byte);
		CHECK(table2.Decrypt(encryptByte) == byte);
	}
}