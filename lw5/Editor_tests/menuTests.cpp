#include "../../catch.hpp"
#include "../Editor/menu/Menu.h"
#include <sstream>

using namespace std;

TEST_CASE("create and run simple menu")
{
	istringstream in;
	ostringstream out;
	CMenu menu(in, out);

	menu.Run();

	string expectedOut = "Commands list:\n"
						 ">";

	CHECK(out.str() == expectedOut);
}

TEST_CASE("add summ command")
{
	istringstream in("summ 1 2");
	ostringstream out;
	CMenu menu(in, out);

	ostringstream result;
	menu.AddItem("summ", "Summ <a> <b>", [&](istream& in) {
		int a, b;
		in >> a >> b;
		result << a + b << endl;
		out << endl;
	});

	menu.Run();

	string expectedOut = "Commands list:\n"
						 "  summ: Summ <a> <b>\n"
						 ">\n"
						 ">";

	CHECK(out.str() == expectedOut);
	CHECK(result.str() == "3\n");
}

TEST_CASE("trying to execute unknown command")
{
	istringstream in("summ 1 2\nexit\n");
	ostringstream out;
	CMenu menu(in, out);

	menu.AddItem("exit", "Exit", [&](istream& in) {
		menu.Exit();
	});
	menu.Run();

	string expectedOut = "Commands list:\n"
						 "  exit: Exit\n"
						 ">Unknown command\n"
						 ">";

	CHECK(out.str() == expectedOut);
}