#pragma once
#include "Condiments.h"

// Добавка из сливок
class CCream : public CCondimentDecorator
{
public:
	CCream(IBeveragePtr&& bevarage)
		: CCondimentDecorator(move(bevarage))
	{
	}

protected:
	double GetCondimentCost() const override
	{
		return 25;
	}

	std::string GetCondimentDescription() const override
	{
		return "Cream";
	}
};