#include "RailRoadSpace.h"
#include <iostream>
using namespace std;

RailRoadSpace::RailRoadSpace(std::string name, int pos, int cost, int rent, std::string group)
	:Property(name,pos,cost,rent,group)
{
}

void RailRoadSpace::display()
{
	string topBorder{ "\t ------------------------------ \n" };
	string midBorder{ "\t|------------------------------|\n" };
	string bottomBorder{ "\t|______________________________|\n" };
	cout << topBorder
		<< printDeedFormat()
		<< printDeedFormat(this->getName())
		<< printDeedFormat("(" + this->getGroup() + ")")
		<< midBorder
		<< printDeedFormat("Cost: $" + to_string(this->getCost()))
		<< printDeedFormat("Rent $*")
		<< printDeedFormat()
		<< printDeedFormat("*$25 if one RR is owned")
		<< printDeedFormat("*$50 if two RRs are owned")
		<< printDeedFormat("*$100 if three RR are owned")
		<< printDeedFormat("*$200 if four RR are owned")
		<< printDeedFormat(3)
		<< printDeedFormat("Mortgage Value $" + to_string(this->getCost() / 2))
		<< printDeedFormat(2)
		<< bottomBorder;
}

void RailRoadSpace::action(Player& player)
{
	int numOwned{ this->getOwner().getRailRoadCount() };
	int rent{ 0 };
	switch (numOwned)
	{
		case 1: rent = 25;
			break;
		case 2: rent = 50;
			break;
		case 3: rent = 100;
			break;
		case 4: rent = 200;
			break;
		default: rent = 0;
			break;
	}
	this->setRent(rent);
	Property::action(player);
}
