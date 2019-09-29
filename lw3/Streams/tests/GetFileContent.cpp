#include "../../../catch.hpp"
#include "GetFileContent.h"
#include <fstream>

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
