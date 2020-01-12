#include "BoardSpace.h"
#include <iostream>
#include "Player.h"
using namespace std;

BoardSpace::BoardSpace(std::string name, int pos)
	:name{ name }, pos{ pos }
{
	this->blankSpace = "[ ]";
	this->spaceString = blankSpace;
}

std::string BoardSpace::getName()
{
	return this->name;
}

void BoardSpace::setName(std::string name)
{
	this->name = name;
}

int BoardSpace::getPos()
{
	return this->pos;;
}

void BoardSpace::setPos(int pos)
{
	this->pos = pos;
}

std::string BoardSpace::getSpaceString()
{
	return this->spaceString;
}

void BoardSpace::setSpaceString(std::string str)
{
	this->spaceString = str;
}

void BoardSpace::resetSpaceString()
{
	this->spaceString = this->blankSpace;
}

std::string BoardSpace::toString()
{
	return this->spaceString;
}

void BoardSpace::tradeTo(Player& player, int amount)
{
}

int BoardSpace::getCost()
{
	return 0;
}

std::string BoardSpace::getGroup()
{
	return std::string();
}

void BoardSpace::setMortgaged(bool m)
{
}

bool BoardSpace::isMortgaged()
{
	return false;
}

bool BoardSpace::getInfo()
{
	return false;
}

Player& BoardSpace::getOwner()
{
	return *this->owner;
}

bool BoardSpace::isOwned()
{
	return owned;
}

void BoardSpace::setIsOwned(bool setIsOwned)
{
	this->owned = setIsOwned;
}

void BoardSpace::setOwner(Player& owner, bool setIsOwned)
{
	this->owner = &owner;
	this->owned = setIsOwned;
}

void BoardSpace::action(Player& p)
{
	cout << "BoardSpace" << endl;
}

void BoardSpace::display()
{
}
