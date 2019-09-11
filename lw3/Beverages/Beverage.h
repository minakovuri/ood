#pragma once
#include "IBeverage.h"

class CBeverage : public IBeverage
{
public:
	CBeverage()
	{
		m_description = "Unknown Beverage";
	}

	std::string GetDescription() const override final
	{
		return m_description;
	}

protected:
	std::string m_description;
};

