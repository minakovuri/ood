#include "../../catch.hpp"
#include "../slides/shapes/styles/GroupFillStyle.h"
#include "mocks/MockStyles.h"

using namespace std;

TEST_CASE("get undefined fill group color")
{
	shared_ptr<IStyle> style1 = make_shared<CMockStyle>(Colors::Red, false);
	shared_ptr<IStyle> style2 = make_shared<CMockStyle>(Colors::Yellow, false);

	FillStyleEnumerator enumerator = [style1, style2](function<void(IStyle&)> func) {
		func(*style1);
		func(*style2);
	};

	CGroupFillStyle groupStyle(enumerator);
	CHECK(groupStyle.GetColor() == nullopt);
}

TEST_CASE("get fill group color")
{
	shared_ptr<IStyle> style1 = make_shared<CMockStyle>(Colors::Red, false);
	shared_ptr<IStyle> style2 = make_shared<CMockStyle>(Colors::Red, false);

	FillStyleEnumerator enumerator = [style1, style2](function<void(IStyle&)> func) {
		func(*style1);
		func(*style2);
	};

	CGroupFillStyle groupStyle(enumerator);
	CHECK(groupStyle.GetColor() == Colors::Red);
}

TEST_CASE("get undefined fill group style enabled value")
{
	shared_ptr<IStyle> style1 = make_shared<CMockStyle>(Colors::Red, false);
	shared_ptr<IStyle> style2 = make_shared<CMockStyle>(Colors::Red, true);

	FillStyleEnumerator enumerator = [style1, style2](function<void(IStyle&)> func) {
		func(*style1);
		func(*style2);
	};

	CGroupFillStyle groupStyle(enumerator);
	CHECK(groupStyle.IsEnabled() == nullopt);
}

TEST_CASE("get fill group style enabled value")
{
	shared_ptr<IStyle> style1 = make_shared<CMockStyle>(Colors::Red, false);
	shared_ptr<IStyle> style2 = make_shared<CMockStyle>(Colors::Yellow, false);

	FillStyleEnumerator enumerator = [style1, style2](function<void(IStyle&)> func) {
		func(*style1);
		func(*style2);
	};

	CGroupFillStyle groupStyle(enumerator);
	CHECK_FALSE(*groupStyle.IsEnabled());
}

TEST_CASE("get fill styles options of empty group")
{
	FillStyleEnumerator enumerator = [](function<void(IStyle&)> func) {};
	CGroupFillStyle groupStyle(enumerator);

	CHECK(groupStyle.GetColor() == nullopt);
	CHECK(groupStyle.IsEnabled() == nullopt);
}

TEST_CASE("set fill styles group color")
{
	shared_ptr<IStyle> style1 = make_shared<CMockStyle>(Colors::Black, false);
	shared_ptr<IStyle> style2 = make_shared<CMockStyle>(Colors::Blue, false);

	FillStyleEnumerator enumerator = [style1, style2](function<void(IStyle&)> func) {
		func(*style1);
		func(*style2);
	};

	CGroupFillStyle groupStyle(enumerator);
	groupStyle.SetColor(Colors::White);

	CHECK(style1->GetColor() == Colors::White);
	CHECK(style2->GetColor() == Colors::White);
}

TEST_CASE("set fill styles group enable")
{
	shared_ptr<IStyle> style1 = make_shared<CMockStyle>(Colors::Black, false);
	shared_ptr<IStyle> style2 = make_shared<CMockStyle>(Colors::Blue, false);

	FillStyleEnumerator enumerator = [style1, style2](function<void(IStyle&)> func) {
		func(*style1);
		func(*style2);
	};

	CGroupFillStyle groupStyle(enumerator);
	groupStyle.SetEnabled(true);

	CHECK(*style1->IsEnabled());
	CHECK(*style2->IsEnabled());
}
