#include "../../catch.hpp"
#include "../slides/shapes/styles/GroupOutlineStyle.h"
#include "mocks/MockStyles.h"

using namespace std;

TEST_CASE("get undefined outline group color")
{
	shared_ptr<IOutlineStyle> style1 = make_shared<CMockOutlineStyle>(Colors::Red, false, 1.0);
	shared_ptr<IOutlineStyle> style2 = make_shared<CMockOutlineStyle>(Colors::Yellow, false, 1.0);

	OutlineStyleEnumerator enumerator = [style1, style2](function<void(IOutlineStyle&)> func) {
		func(*style1);
		func(*style2);
	};

	CGroupOutlineStyle groupStyle(enumerator);
	CHECK(groupStyle.GetColor() == nullopt);
}

TEST_CASE("get outline group color")
{
	shared_ptr<IOutlineStyle> style1 = make_shared<CMockOutlineStyle>(Colors::Red, false, 1.0);
	shared_ptr<IOutlineStyle> style2 = make_shared<CMockOutlineStyle>(Colors::Red, false, 2.0);

	OutlineStyleEnumerator enumerator = [style1, style2](function<void(IOutlineStyle&)> func) {
		func(*style1);
		func(*style2);
	};

	CGroupOutlineStyle groupStyle(enumerator);
	CHECK(groupStyle.GetColor() == Colors::Red);
}

TEST_CASE("get undefined outline group style enabled value")
{
	shared_ptr<IOutlineStyle> style1 = make_shared<CMockOutlineStyle>(Colors::Red, false, 1.0);
	shared_ptr<IOutlineStyle> style2 = make_shared<CMockOutlineStyle>(Colors::Red, true, 1.0);

	OutlineStyleEnumerator enumerator = [style1, style2](function<void(IOutlineStyle&)> func) {
		func(*style1);
		func(*style2);
	};

	CGroupOutlineStyle groupStyle(enumerator);
	CHECK(groupStyle.IsEnabled() == nullopt);
}

TEST_CASE("get outline group style enabled value")
{
	shared_ptr<IOutlineStyle> style1 = make_shared<CMockOutlineStyle>(Colors::Red, true, 1.0);
	shared_ptr<IOutlineStyle> style2 = make_shared<CMockOutlineStyle>(Colors::Red, true, 1.0);

	OutlineStyleEnumerator enumerator = [style1, style2](function<void(IOutlineStyle&)> func) {
		func(*style1);
		func(*style2);
	};

	CGroupOutlineStyle groupStyle(enumerator);
	CHECK(*groupStyle.IsEnabled());
}

TEST_CASE("get undefined outline group style thickness")
{
	shared_ptr<IOutlineStyle> style1 = make_shared<CMockOutlineStyle>(Colors::Red, true, 5.0);
	shared_ptr<IOutlineStyle> style2 = make_shared<CMockOutlineStyle>(Colors::Red, true, 7.5);

	OutlineStyleEnumerator enumerator = [style1, style2](function<void(IOutlineStyle&)> func) {
		func(*style1);
		func(*style2);
	};

	CGroupOutlineStyle groupStyle(enumerator);
	CHECK(groupStyle.GetThickness() == nullopt);
}

TEST_CASE("get outline group style thickness")
{
	shared_ptr<IOutlineStyle> style1 = make_shared<CMockOutlineStyle>(Colors::Red, true, 5.0);
	shared_ptr<IOutlineStyle> style2 = make_shared<CMockOutlineStyle>(Colors::Red, true, 5.0);

	OutlineStyleEnumerator enumerator = [style1, style2](function<void(IOutlineStyle&)> func) {
		func(*style1);
		func(*style2);
	};

	CGroupOutlineStyle groupStyle(enumerator);
	CHECK(groupStyle.GetThickness() == 5.0);
}

TEST_CASE("get outline styles options of empty group")
{
	OutlineStyleEnumerator enumerator = [](function<void(IOutlineStyle&)> func) {};
	CGroupOutlineStyle groupStyle(enumerator);

	CHECK(groupStyle.GetColor() == nullopt);
	CHECK(groupStyle.IsEnabled() == nullopt);
}

TEST_CASE("set outline styles group color")
{
	shared_ptr<IOutlineStyle> style1 = make_shared<CMockOutlineStyle>(Colors::Red, true, 1.0);
	shared_ptr<IOutlineStyle> style2 = make_shared<CMockOutlineStyle>(Colors::Red, true, 1.0);

	OutlineStyleEnumerator enumerator = [style1, style2](function<void(IOutlineStyle&)> func) {
		func(*style1);
		func(*style2);
	};

	CGroupOutlineStyle groupStyle(enumerator);
	groupStyle.SetColor(Colors::White);

	CHECK(style1->GetColor() == Colors::White);
	CHECK(style2->GetColor() == Colors::White);
}

TEST_CASE("set outline styles group enable")
{
	shared_ptr<IOutlineStyle> style1 = make_shared<CMockOutlineStyle>(Colors::Red, false, 1.0);
	shared_ptr<IOutlineStyle> style2 = make_shared<CMockOutlineStyle>(Colors::Red, false, 1.0);

	OutlineStyleEnumerator enumerator = [style1, style2](function<void(IOutlineStyle&)> func) {
		func(*style1);
		func(*style2);
	};

	CGroupOutlineStyle groupStyle(enumerator);
	groupStyle.SetEnabled(true);

	CHECK(*style1->IsEnabled());
	CHECK(*style2->IsEnabled());
}

TEST_CASE("set outline styles group thickness")
{
	shared_ptr<IOutlineStyle> style1 = make_shared<CMockOutlineStyle>(Colors::Red, false, 4.4);
	shared_ptr<IOutlineStyle> style2 = make_shared<CMockOutlineStyle>(Colors::Red, false, 2.3);

	OutlineStyleEnumerator enumerator = [style1, style2](function<void(IOutlineStyle&)> func) {
		func(*style1);
		func(*style2);
	};

	CGroupOutlineStyle groupStyle(enumerator);
	groupStyle.SetThickness(10.0);

	CHECK(style1->GetThickness() == 10.0);
	CHECK(style2->GetThickness() == 10.0);
}