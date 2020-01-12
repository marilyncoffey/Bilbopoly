#pragma once
#include "NonProperty.h"
#include "Player.h"
class TaxSpace : public NonProperty
{
private:
	int taxAmount;
public:
	TaxSpace(std::string name, int pos, int taxAmount);
	int getTaxAmount();
	virtual void display();
	virtual void action(Player& p);
};