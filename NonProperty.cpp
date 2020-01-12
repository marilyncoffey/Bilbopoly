#include "NonProperty.h"
#include <iostream>
#include "Player.h"
using namespace std;

NonProperty::NonProperty(std::string name, int pos)
	:BoardSpace(name, pos)
{
}

void NonProperty::action(Player& p)
{
}

void NonProperty::display()
{
}


