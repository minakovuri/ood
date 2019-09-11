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
	CCoffee(CoffeePortionType portionType = CoffeePortionType::Standart)
		: m_portionType(portionType)
	{
		m_description = "Coffee";
	}

	double GetCost() const override
	{
		return 60;
	}

protected:
	CoffeePortionType m_portionType;
};

class CCappuccino : public CCoffee
{
public:
	CCappuccino(CoffeePortionType portionType = CoffeePortionType::Standart)
		: CCoffee(portionType)
	{
		if (portionType == CoffeePortionType::Standart)
		{
			m_description = "Cappuccino Standart";
		}
		else if (portionType == CoffeePortionType::Double)
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
		else if (m_portionType == CoffeePortionType::Double)
		{
			return 120;
		}
	}
};

class CLatte : public CCoffee
{
public:
	CLatte(CoffeePortionType portionType = CoffeePortionType::Standart)
		: CCoffee(portionType)
	{
		if (portionType == CoffeePortionType::Standart)
		{
			m_description = "Latte Standart";
		}
		else if (portionType == CoffeePortionType::Double)
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
		else if (m_portionType == CoffeePortionType::Double)
		{
			return 130;
		}
	}
};