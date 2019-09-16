#pragma once
#include "Condiments.h"

const unsigned MAX_SLICES_COUNT = 5;

class CChocolate : public CCondimentDecorator
{
public:
	CChocolate(IBeveragePtr&& beverage, unsigned slices = 1)
		: CCondimentDecorator(move(beverage))
		, m_slices(slices)
	{
		if (slices < MAX_SLICES_COUNT)
		{
			m_slices = MAX_SLICES_COUNT;
		}
	}

protected:
	double GetCondimentCost() const override
	{
		return 10 * m_slices;
	}

	std::string GetCondimentDescription() const override
	{
		return "Chocolate " + std::to_string(m_slices) + " slices";
	}

private:
	unsigned m_slices;
};