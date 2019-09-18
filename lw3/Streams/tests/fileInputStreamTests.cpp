#include "../../../catch.hpp"
#include "../inputStream/CFileInputStream.h"
#include <array>

const std::string INPUT_FILE_NAME = "input.dat";

TEST_CASE("Test creating input file streams")
{
	CHECK_THROWS_AS(CFileInputStream("not_exist.dat"), std::ios_base::failure);
	CHECK_NOTHROW(CFileInputStream(INPUT_FILE_NAME));
}

TEST_CASE("Test reading bytes from file input stream")
{
	CFileInputStream fileInputStream(INPUT_FILE_NAME);

	CHECK_FALSE(fileInputStream.IsEOF());

	CHECK(fileInputStream.ReadByte() == 'A');
	CHECK(fileInputStream.ReadByte() == 'B');
	CHECK(fileInputStream.ReadByte() == 'C');
	CHECK(fileInputStream.ReadByte() == '#');

	fileInputStream.ReadByte();
	CHECK(fileInputStream.IsEOF());
}

TEST_CASE("Test reading block of bytes from file input stream")
{
	CFileInputStream fileInputStream(INPUT_FILE_NAME);
	std::array<uint8_t, 4> buff;

	CHECK(fileInputStream.ReadBlock(buff.data(), 2) == 2);
	CHECK(fileInputStream.ReadBlock(buff.data() + 2, 2) == 2);

	CHECK(buff[0] == 'A');
	CHECK(buff[1] == 'B');
	CHECK(buff[2] == 'C');
	CHECK(buff[3] == '#');

	fileInputStream.ReadByte();
	CHECK(fileInputStream.IsEOF());
}
