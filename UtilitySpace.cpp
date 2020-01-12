#include "UtilitySpace.h"
#include <iostream>
using namespace std;

UtilitySpace::UtilitySpace(std::string name, int pos, int cost, int rent, std::string group)
	:Property(name,pos,cost,rent,group)
{
}

void UtilitySpace::display()
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
		<< printDeedFormat("*4x dice roll") 
		<< printDeedFormat("if one utility is owned")
		<< printDeedFormat()
		<< printDeedFormat("*10x dice roll")
		<< printDeedFormat("if two utilities are owned")
		<< printDeedFormat(2)
		<< printDeedFormat("Mortgage Value $" + to_string(this->getCost() / 2))
		<< printDeedFormat(2)
		<< bottomBorder;
}

void UtilitySpace::action(Player& player)
{
	int numOwned{ this->getOwner().getUtilityCount() };
	int multiplier{ 4 };
	if (numOwned == 2)
	{
		multiplier = 10;
	}
	this->setRent(player.getDiceTotal()*multiplier);
	Property::action(player);
}
