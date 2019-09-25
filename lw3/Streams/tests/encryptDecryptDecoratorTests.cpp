#include "../../../catch.hpp"
#include "../decorators/CDecryptionInputStream.h"
#include "../decorators/CEncryptionOutputStream.h"
#include "../inputStream/CMemoryInputStream.h"
#include "../outputStream/CMemoryOutputStream.h"

#include <array>
#include <iostream>

using namespace std;

TEST_CASE("Test encryption and decryption byte with decorators")
{
	unsigned int key = rand();

	std::vector<uint8_t> memory;
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

	std::vector<uint8_t> memory;
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