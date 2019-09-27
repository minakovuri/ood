#include "../../../catch.hpp"
#include "../decorators/CCompressedOutputStream.h"
#include "../decorators/CDecompressedInputStream.h"
#include "../inputStream/CMemoryInputStream.h"
#include "../outputStream/CMemoryOutputStream.h"

#include <array>
#include <iostream>

using namespace std;

TEST_CASE("Test compress and decompress bytes with decorators")
{
	std::vector<uint8_t> memory;
	memory.reserve(6);

	auto memOutStream = make_unique<CMemoryOutputStream>(memory);
	auto compressOutStream = make_unique<CCompressedOutputStream>(move(memOutStream));

	compressOutStream->WriteByte('A');
	compressOutStream->WriteByte('A');
	compressOutStream->WriteByte('A');
	compressOutStream->WriteByte('B');
	compressOutStream->WriteByte('B');
	compressOutStream->WriteByte('C');

	auto memInStream = make_unique<CMemoryInputStream>(memory);
	auto decompressInStream = make_unique<CDecompressedInputStream>(move(memInStream));

	CHECK(decompressInStream->ReadByte() == 'A');
	CHECK(decompressInStream->ReadByte() == 'A');
	CHECK(decompressInStream->ReadByte() == 'A');
	CHECK(decompressInStream->ReadByte() == 'B');
	CHECK(decompressInStream->ReadByte() == 'B');
	CHECK(decompressInStream->ReadByte() == 'C');
}