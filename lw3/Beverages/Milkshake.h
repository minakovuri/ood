#pragma once
#include "Beverage.h"

enum class MilkshakePortionType
{
	Small,
	Medium,
	Large,
};

class CMilkshake : public CBeverage
{
public:
	CMilkshake(MilkshakePortionType portionType)
		: m_portionType(portionType)
	{
		switch (portionType)
		{
		case MilkshakePortionType::Small:
			m_description = "Small Milkshake";
			break;
		case MilkshakePortionType::Medium:
			m_description = "Medium Milkshake";
			break;
		case MilkshakePortionType::Large:
			m_description = "Large Milkshake";
			break;
		default:
			break;
		}
	}

	double GetCost() const override
	{
		switch (m_portionType)
		{
		case MilkshakePortionType::Small:
			return 50;
		case MilkshakePortionType::Medium:
			return 60;
		default:
			break;
		}

		return 80;
	}

protected:
	MilkshakePortionType m_portionType;
};