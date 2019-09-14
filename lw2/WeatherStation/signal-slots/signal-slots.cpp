#include <boost/chrono.hpp>
#include <iostream>

int main()
{
	std::cout << boost::chrono::steady_clock::now() << std::endl;
	return 0;
}
