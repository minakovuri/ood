#include "../../../catch.hpp"
#include "../inputStream/CMemoryInputStream.h"
#include <array>

TEST_CASE("Test reading block of bytes from memory")
{
	std::vector<uint8_t> container{ 0, 1, 2, 3, 4, 5, 6 };
	CMemoryInputStream memInputStream(container);

	std::array<uint8_t, 4> buff;

	CHECK(memInputStream.ReadBlock(buff.data(), 4) == 4);

	CHECK(buff[0] == 0);
	CHECK(buff[1] == 1);
	CHECK(buff[2] == 2);
	CHECK(buff[3] == 3);

	CHECK(memInputStream.ReadBlock(buff.data(), 4) == 3);

	CHECK(buff[0] == 4);
	CHECK(buff[1] == 5);
	CHECK(buff[2] == 6);

	// TODO: спросить про ситуацию с исключением
}