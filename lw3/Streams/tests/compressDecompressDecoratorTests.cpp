#include "../../../catch.hpp"
#include "../decorators/CCompressedOutputStream.h"
#include "../decorators/CDecompressedInputStream.h"
#include "../inputStream/CFileInputStream.h"
#include "../inputStream/CMemoryInputStream.h"
#include "../outputStream/CFileOutputStream.h"
#include "../outputStream/CMemoryOutputStream.h"
#include "GetFileContent.h"

#include <array>
#include <iostream>

using namespace std;

/*const string INPUT_FILE_NAME = "input_compress.dat";
const string OUTPUT_FILE_NAME = "output_compress.dat";*/

TEST_CASE("Test compress and decompress bytes with decorators")
{
	std::vector<uint8_t> memory;

	{
		auto memOutStream = make_unique<CMemoryOutputStream>(memory);
		auto compressOutStream = make_unique<CCompressedOutputStream>(move(memOutStream));

		compressOutStream->WriteByte('A');
		compressOutStream->WriteByte('A');
		compressOutStream->WriteByte('A');
		compressOutStream->WriteByte(1);
		compressOutStream->WriteByte(1);
		compressOutStream->WriteByte('#');
	}

	CHECK(memory[0] == 3);
	CHECK(memory[1] == 'A');
	CHECK(memory[2] == 2);
	CHECK(memory[3] == 1);
	CHECK(memory[4] == 1);
	CHECK(memory[5] == '#');

	auto memInStream = make_unique<CMemoryInputStream>(memory);
	auto decompressInStream = make_unique<CDecompressedInputStream>(move(memInStream));

	CHECK(decompressInStream->ReadByte() == 'A');
	CHECK(decompressInStream->ReadByte() == 'A');
	CHECK(decompressInStream->ReadByte() == 'A');
	CHECK(decompressInStream->ReadByte() == 1);
	CHECK(decompressInStream->ReadByte() == 1);
	CHECK(decompressInStream->ReadByte() == '#');
}

TEST_CASE("Test compress and decompress block of bytes with decorators")
{
	std::vector<uint8_t> memory;
	std::array<uint8_t, 6> inBlock{ 'A', 'A', 'A', 1, 1, '#' };

	{
		auto memOutStream = make_unique<CMemoryOutputStream>(memory);
		auto compressOutStream = make_unique<CCompressedOutputStream>(move(memOutStream));

		compressOutStream->WriteBlock(inBlock.data(), 6);
	}

	auto memInStream = make_unique<CMemoryInputStream>(memory);
	auto decompressInStream = make_unique<CDecompressedInputStream>(move(memInStream));

	std::array<uint8_t, 6> outBlock;
	decompressInStream->ReadBlock(outBlock.data(), 6);

	for (size_t i = 0; i < inBlock.size(); ++i)
	{
		CHECK(inBlock[i] == outBlock[i]);
	}
}

/*TEST_CASE("Test compress and decompress with files")
{
	unique_ptr<IOutputDataStream> outputFileStream = make_unique<CFileOutputStream>(OUTPUT_FILE_NAME);
	unique_ptr<IInputDataStream> inputFileStream = make_unique<CFileInputStream>(INPUT_FILE_NAME);

	outputFileStream = make_unique<CCompressedOutputStream>(move(outputFileStream));
	inputFileStream = make_unique<CDecompressedInputStream>(move(inputFileStream));

	while (!inputFileStream->IsEOF())
	{
		outputFileStream->WriteByte(inputFileStream->ReadByte());
	}

	CHECK(GetFileContent(INPUT_FILE_NAME) == GetFileContent(OUTPUT_FILE_NAME));
}*/

TEST_CASE("Test multiple compress and decompress")
{
	std::vector<uint8_t> memory;
	std::array<uint8_t, 6> inBlock{ 'A', 'A', 'A', 1, 1, '#' };

	{
		unique_ptr<IOutputDataStream> memOutStream = make_unique<CMemoryOutputStream>(memory);
		memOutStream = make_unique<CCompressedOutputStream>(move(memOutStream));
		memOutStream = make_unique<CCompressedOutputStream>(move(memOutStream));

		memOutStream->WriteBlock(inBlock.data(), 6);
	}

	unique_ptr<IInputDataStream> memInStream = make_unique<CMemoryInputStream>(memory);
	memInStream = make_unique<CDecompressedInputStream>(move(memInStream));
	memInStream = make_unique<CDecompressedInputStream>(move(memInStream));

	std::array<uint8_t, 6> outBlock;
	memInStream->ReadBlock(outBlock.data(), 6);

	for (size_t i = 0; i < inBlock.size(); ++i)
	{
		CHECK(inBlock[i] == outBlock[i]);
	}
}