#include "../../../catch.hpp"
#include "GetFileContent.h"
#include <fstream>

const std::string INPUT_FILE_NAME = "test_files/input.bin";

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
	CHECK(GetFileContent(INPUT_FILE_NAME) == "ABC#");
}
