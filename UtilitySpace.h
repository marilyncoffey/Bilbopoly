#pragma once
#include "Property.h"
class UtilitySpace : public Property
{
private:

public:
	UtilitySpace(std::string name, int pos, int cost, int rent, std::string group);
	virtual void display();
	virtual void action(Player& player);
};