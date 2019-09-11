#pragma once
#include "Beverage.h"

class CTea : public CBeverage
{
public:
	CTea()
	{
		m_description = "Tea";
	}

	double GetCost() const override
	{
		return 30;
	}
};

class CBlackTea : public CTea
{
public:
	CBlackTea()
	{
		m_description = "Black Tea";
	}
};

class CGreenTea : public CTea
{
public:
	CGreenTea()
	{
		m_description = "Green Tea";
	}
};

class CRedTea : public CTea
{
public:
	CRedTea()
	{
		m_description = "Red Tea";
	}
};

class CYellowTea : public CTea
{
public:
	CYellowTea()
	{
		m_description = "Yellow Tea";
	}
};