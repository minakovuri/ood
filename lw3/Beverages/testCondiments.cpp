#include "../../catch.hpp"
#include "Chocolate.h"
#include "Coffee.h"
#include "Cream.h"
#include "Liquor.h"

TEST_CASE("Test cream")
{
	auto latte = std::make_unique<CLatte>(CoffeePortionType::Standart);
	auto latteWithCream = std::make_unique<CCream>(std::move(latte));

	CHECK(latteWithCream->GetCost() == 90 + 25);
	CHECK(latteWithCream->GetDescription() == "Latte Standart, Cream");
}

TEST_CASE("Test choclate")
{
	auto latte = std::make_unique<CLatte>(CoffeePortionType::Standart);
	auto latteWithChoco = std::make_unique<CChocolate>(std::move(latte), 8);

	CHECK(latteWithChoco->GetCost() == 90 + 5 * 10);
	CHECK(latteWithChoco->GetDescription() == "Latte Standart, Chocolate 5 slices");
}

TEST_CASE("Test liquor")
{
	auto latte = std::make_unique<CLatte>(CoffeePortionType::Standart);
	auto latteWithChocoLiquor = std::make_unique<CLiquor>(std::move(latte), LiquorType::Chocolate);

	CHECK(latteWithChocoLiquor->GetCost() == 90 + 50);
	CHECK(latteWithChocoLiquor->GetDescription() == "Latte Standart, Chocolate Liquor");

	auto doubleLatte = std::make_unique<CLatte>(CoffeePortionType::Double);
	auto latteWithNutLiquor = std::make_unique<CLiquor>(std::move(doubleLatte), LiquorType::Nut);

	CHECK(latteWithNutLiquor->GetCost() == 130 + 50);
	CHECK(latteWithNutLiquor->GetDescription() == "Double Latte, Nut Liquor");
}