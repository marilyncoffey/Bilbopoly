#pragma once
#include "Property.h"
class RailRoadSpace : public Property
{
private:

public:
	RailRoadSpace(std::string name, int pos, int cost, int rent, std::string group);
	virtual void display();
	virtual void action(Player& player);
};