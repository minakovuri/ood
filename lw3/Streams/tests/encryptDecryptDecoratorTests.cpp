#include "../../../catch.hpp"
#include "../decorators/CDecryptionInputStream.h"
#include "../decorators/CEncryptionOutputStream.h"
#include "../inputStream/CFileInputStream.h"
#include "../inputStream/CMemoryInputStream.h"
#include "../outputStream/CFileOutputStream.h"
#include "../outputStream/CMemoryOutputStream.h"
#include "GetFileContent.h"

#include <array>
#include <iostream>

using namespace std;

const string INPUT_FILE_NAME = "test_files/input.bin";
const string OUTPUT_FILE_NAME = "test_files/output.bin";

TEST_CASE("Test encryption and decryption bytes with memory")
{
	unsigned int key = rand();

	vector<uint8_t> memory;
	memory.reserve(3);

	auto memOutStream = make_unique<CMemoryOutputStream>(memory);
	auto encryptOutStream = make_unique<CEncryptionOutputStream>(move(memOutStream), key);

	encryptOutStream->WriteByte('A');
	encryptOutStream->WriteByte('B');
	encryptOutStream->WriteByte('C');

	auto memInStream = make_unique<CMemoryInputStream>(memory);
	auto decryptInStream = make_unique<CDecryptionInputStream>(move(memInStream), key);

	CHECK(decryptInStream->ReadByte() == 'A');
	CHECK(decryptInStream->ReadByte() == 'B');
	CHECK(decryptInStream->ReadByte() == 'C');
}

TEST_CASE("Test encryption and decryption block of bytes with decorators")
{
	unsigned int key = rand();

	vector<uint8_t> memory;
	memory.reserve(3);

	auto memOutStream = make_unique<CMemoryOutputStream>(memory);
	auto encryptOutStream = make_unique<CEncryptionOutputStream>(std::move(memOutStream), key);

	std::array<uint8_t, 3> inBlock{ 'A', 'B', 'C' };
	encryptOutStream->WriteBlock(inBlock.data(), 3);

	auto memInStream = make_unique<CMemoryInputStream>(memory);
	auto decryptInStream = make_unique<CDecryptionInputStream>(std::move(memInStream), key);

	std::array<uint8_t, 3> outBlock;
	decryptInStream->ReadBlock(outBlock.data(), 3);

	for (size_t i = 0; i < inBlock.size(); ++i)
	{
		CHECK(inBlock[i] == outBlock[i]);
	}
}

TEST_CASE("Test encryption and decryption bytes with files")
{
	unsigned int key = rand();

	unique_ptr<IOutputDataStream> outputFileStream = make_unique<CFileOutputStream>(OUTPUT_FILE_NAME);
	unique_ptr<IInputDataStream> inputFileStream = make_unique<CFileInputStream>(INPUT_FILE_NAME);

	outputFileStream = make_unique<CEncryptionOutputStream>(move(outputFileStream), key);
	inputFileStream = make_unique<CDecryptionInputStream>(move(inputFileStream), key);

	while (!inputFileStream->IsEOF())
	{
		try
		{
			outputFileStream->WriteByte(inputFileStream->ReadByte());
		}
		catch (const std::exception&)
		{
		}
	}

	CHECK(GetFileContent(INPUT_FILE_NAME) == GetFileContent(OUTPUT_FILE_NAME));
}

TEST_CASE("Test multiple encryption and decryption with memory")
{
	std::vector<uint8_t> memory;

	unique_ptr<IOutputDataStream> memOutStream = make_unique<CMemoryOutputStream>(memory);
	memOutStream = make_unique<CEncryptionOutputStream>(move(memOutStream), 100500);
	memOutStream = make_unique<CEncryptionOutputStream>(move(memOutStream), 3);

	std::array<uint8_t, 6> inBlock{ 'A', 'A', 'A', 'B', 'B', 'C' };
	memOutStream->WriteBlock(inBlock.data(), 6);

	unique_ptr<IInputDataStream> memInStream = make_unique<CMemoryInputStream>(memory);
	memInStream = make_unique<CDecryptionInputStream>(move(memInStream), 100500);
	memInStream = make_unique<CDecryptionInputStream>(move(memInStream), 3);

	std::array<uint8_t, 6> outBlock;
	memInStream->ReadBlock(outBlock.data(), 6);

	for (size_t i = 0; i < inBlock.size(); ++i)
	{
		CHECK(inBlock[i] == outBlock[i]);
	}
}