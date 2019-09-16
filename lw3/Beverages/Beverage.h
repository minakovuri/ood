#pragma once
#include "IBeverage.h"

class CBeverage : public IBeverage
{
public:
	CBeverage(const std::string description = "Unknown Beverage")
		: m_description(description)
	{
	}

	std::string GetDescription() const final
	{
		return m_description;
	}

protected:
	std::string m_description;
};

