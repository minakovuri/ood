#pragma once
#include "Beverage.h"

enum class CoffeePortionType
{
	Standart,
	Double,
};

class CCoffee : public CBeverage
{
public:
	CCoffee(const std::string description = "Coffee")
		: CBeverage(description)
		, m_portionType(CoffeePortionType::Standart)
	{
	}

	double GetCost() const override
	{
		return 60;
	}

protected:
	CCoffee(const std::string description, CoffeePortionType portionType = CoffeePortionType::Standart)
		: CBeverage(description)
		, m_portionType(portionType)
	{
	}

	CoffeePortionType m_portionType;
};

class CCappuccino : public CCoffee
{
public:
	CCappuccino(CoffeePortionType portionType = CoffeePortionType::Standart)
		: CCoffee("Cappuccino Standart", portionType)
	{
		if (portionType == CoffeePortionType::Double)
		{
			m_description = "Double Cappuccino";
		}
	}

	double GetCost() const override
	{
		if (m_portionType == CoffeePortionType::Standart)
		{
			return 80;
		}
		
		return 120;
	}
};

class CLatte : public CCoffee
{
public:
	CLatte(CoffeePortionType portionType = CoffeePortionType::Standart)
		: CCoffee("Latte Standart", portionType)
	{
		if (portionType == CoffeePortionType::Double)
		{
			m_description = "Double Latte";
		}
	}

	double GetCost() const override
	{
		if (m_portionType == CoffeePortionType::Standart)
		{
			return 90;
		}
		
		return 130;
	}
};