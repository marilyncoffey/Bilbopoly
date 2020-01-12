#pragma once
#include "TaxSpace.h"
class IncomeTaxSpace : public TaxSpace
{
private:

public:
	IncomeTaxSpace(std::string name, int pos, int taxAmount);
	virtual void display();
	virtual void action(Player& player);
};