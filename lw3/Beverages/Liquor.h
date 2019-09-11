#pragma once
#include "Condiments.h"

enum class LiquorType
{
	Nut,
	Chocolate,
};

class CLiquor : public CCondimentDecorator
{
public:
	CLiquor(IBeveragePtr&& beverage, LiquorType type)
		: CCondimentDecorator(move(beverage))
		, m_type(type)

	{
	}

protected:
	double GetCondimentCost() const override
	{
		return 50;
	}

	std::string GetCondimentDescription() const override
	{
		return std::string(m_type == LiquorType::Chocolate ? "Chocolate" : "Nut")
			+ " Liquor";
	}

private:
	LiquorType m_type;
};
