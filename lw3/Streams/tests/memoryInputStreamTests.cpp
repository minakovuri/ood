#include "../../../catch.hpp"
#include "../inputStream/CMemoryInputStream.h"
#include <array>

TEST_CASE("Test reading byte from memory stream")
{
	std::vector<uint8_t> container{ 0, 1, 2, 3, 4, 5, 6 };
	CMemoryInputStream memInputStream(container);
	
	CHECK(memInputStream.ReadByte() == 0);
	CHECK(memInputStream.ReadByte() == 1);
	CHECK(memInputStream.ReadByte() == 2);
	CHECK(memInputStream.ReadByte() == 3);
	CHECK(memInputStream.ReadByte() == 4);
	CHECK(memInputStream.ReadByte() == 5);
	CHECK(memInputStream.ReadByte() == 6);

	CHECK_THROWS_AS(memInputStream.ReadByte(), std::ios_base::failure);
}

TEST_CASE("Test reading block of bytes from memory stream")
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

	// TODO: спросить про ситуацию с исключением - выбрасывать исключение или возвращать size 
}