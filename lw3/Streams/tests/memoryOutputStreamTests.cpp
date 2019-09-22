#include "../../../catch.hpp"
#include "../outputStream/CMemoryOutputStream.h"
#include <array>

TEST_CASE("Test writing byte to memory stream")
{
	std::vector<uint8_t> container;
	container.reserve(3);

	CMemoryOutputStream memOutputStream(container);

	CHECK(container.size() == 0);

	CHECK_NOTHROW(memOutputStream.WriteByte('A'));
	CHECK_NOTHROW(memOutputStream.WriteByte('B'));
	CHECK_NOTHROW(memOutputStream.WriteByte('C'));

	CHECK(container.size() == 3);

	CHECK(container[0] == 'A');
	CHECK(container[1] == 'B');
	CHECK(container[2] == 'C');

	CHECK_THROWS_AS(memOutputStream.WriteByte('#'), std::ios_base::failure);
}

TEST_CASE("Test writing block of bytes to memory stream")
{
	std::vector<uint8_t> container;
	container.reserve(4);

	CMemoryOutputStream memOutputStream(container);

	std::array<uint8_t, 5> block{'1', '2', '3', '4', '5'};

	CHECK_NOTHROW(memOutputStream.WriteBlock(block.data(), 2));
	CHECK_NOTHROW(memOutputStream.WriteBlock(block.data() + 2, 2));

	CHECK(container[0] == '1');
	CHECK(container[1] == '2');
	CHECK(container[2] == '3');
	CHECK(container[3] == '4');

	CHECK_THROWS_AS(memOutputStream.WriteBlock(block.data() + 3, 2), std::ios_base::failure);
}