#pragma once
#include "NonProperty.h"
#include "Player.h"
class GoSpace : public NonProperty
{
private:

public:
	GoSpace(std::string name, int pos);
	virtual void display();
	virtual void action(Player& p);
};