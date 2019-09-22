#include "../../../catch.hpp"
#include "../decorators/CReplacementTable.h"

TEST_CASE("Test encryption and decryption with replacement table")
{
	CReplacementTable table(std::rand());

	std::vector<uint8_t> input{ 'A', 'B', 'C' };

	for (auto byte : input)
	{
		uint8_t encryptByte = table.Encrypt(byte);
		CHECK(encryptByte != byte);
		CHECK(table.Decrypt(encryptByte) == byte);
	}
}