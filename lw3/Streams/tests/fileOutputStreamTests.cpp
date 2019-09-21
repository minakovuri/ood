#include "../../../catch.hpp"
#include "../outputStream/CFileOutputStream.h"
#include <array>

const std::string OUTPUT_FILE_NAME = "output.dat";

std::string GetFileContent(const std::string& fileName)
{
	std::ifstream file(fileName, std::ios::binary);

	if (!file.is_open())
	{
		throw std::ios_base::failure("failed to open file" + fileName);
	}

	return std::string((std::istreambuf_iterator<char>(file)), (std::istreambuf_iterator<char>()));
}

TEST_CASE("Test GetFileContent function")
{
	CHECK(GetFileContent("input.dat") == "ABC#");
}

TEST_CASE("Test writing byte to stream")
{
	CFileOutputStream stream(OUTPUT_FILE_NAME);

	CHECK_NOTHROW(stream.WriteByte('1'));
	CHECK(GetFileContent(OUTPUT_FILE_NAME) == "1");

	CHECK_NOTHROW(stream.WriteByte('A'));
	CHECK_NOTHROW(stream.WriteByte('B'));

	CHECK(GetFileContent(OUTPUT_FILE_NAME) == "1AB");
}

TEST_CASE("Test writing block of bytes to stream")
{
	CFileOutputStream stream(OUTPUT_FILE_NAME);

	std::array<char, 4> buff{ '1', '2', '3', '4' };
	
	CHECK_NOTHROW(stream.WriteBlock(buff.data(), 4));

	CHECK(GetFileContent(OUTPUT_FILE_NAME) == "1234");

	// TODO подумать про ситуацию с исключением
}