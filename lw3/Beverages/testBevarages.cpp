#include "../../catch.hpp"
#include "Coffee.h"
#include "Tea.h"
#include "Milkshake.h"

TEST_CASE("Test latte")
{
	CLatte latteStandart(CoffeePortionType::Standart);
	CLatte doubleLatte(CoffeePortionType::Double);

	CHECK(latteStandart.GetCost() == 90);
	CHECK(latteStandart.GetDescription() == "Latte Standart");

	CHECK(doubleLatte.GetCost() == 130);
	CHECK(doubleLatte.GetDescription() == "Double Latte");
}

TEST_CASE("Test cappuccino")
{
	CCappuccino cappuccinoStandart(CoffeePortionType::Standart);
	CCappuccino doubleCappuccino(CoffeePortionType::Double);

	CHECK(cappuccinoStandart.GetCost() == 80);
	CHECK(cappuccinoStandart.GetDescription() == "Cappuccino Standart");

	CHECK(doubleCappuccino.GetCost() == 120);
	CHECK(doubleCappuccino.GetDescription() == "Double Cappuccino");
}

TEST_CASE("Test tea")
{
	CBlackTea blackTea;
	CGreenTea greenTea;
	CRedTea redTea;
	CYellowTea yellowTea;

	CHECK(blackTea.GetCost() == 30);
	CHECK(greenTea.GetCost() == 30);
	CHECK(redTea.GetCost() == 30);
	CHECK(yellowTea.GetCost() == 30);

	CHECK(blackTea.GetDescription() == "Black Tea");
	CHECK(greenTea.GetDescription() == "Green Tea");
	CHECK(redTea.GetDescription() == "Red Tea");
	CHECK(yellowTea.GetDescription() == "Yellow Tea");
}

TEST_CASE("Test milkshake")
{
	CMilkshake smallMilkshake(MilkshakePortionType::Small);
	CMilkshake mediumMilkshake(MilkshakePortionType::Medium);
	CMilkshake largeMilkshake(MilkshakePortionType::Large);

	CHECK(smallMilkshake.GetDescription() == "Small Milkshake");
	CHECK(smallMilkshake.GetCost() == 50);

	CHECK(mediumMilkshake.GetDescription() == "Medium Milkshake");
	CHECK(mediumMilkshake.GetCost() == 60);

	CHECK(largeMilkshake.GetDescription() == "Large Milkshake");
	CHECK(largeMilkshake.GetCost() == 80);
}