#include "../../../catch.hpp"
#include "../outputStream/CFileOutputStream.h"
#include "GetFileContent.h"
#include <array>

const std::string OUTPUT_FILE_NAME = "test_files/output.bin";

TEST_CASE("Test writing byte to file stream")
{
	CFileOutputStream stream(OUTPUT_FILE_NAME);

	CHECK_NOTHROW(stream.WriteByte('1'));
	CHECK(GetFileContent(OUTPUT_FILE_NAME) == "1");

	CHECK_NOTHROW(stream.WriteByte('A'));
	CHECK_NOTHROW(stream.WriteByte('B'));

	CHECK(GetFileContent(OUTPUT_FILE_NAME) == "1AB");
}

TEST_CASE("Test writing block of bytes to file stream")
{
	CFileOutputStream stream(OUTPUT_FILE_NAME);

	std::array<char, 4> buff{ '1', '2', '3', '4' };
	
	CHECK_NOTHROW(stream.WriteBlock(buff.data(), 4));

	CHECK(GetFileContent(OUTPUT_FILE_NAME) == "1234");
}