#pragma once
#include "NonProperty.h"
class DrawSpace : public NonProperty
{
private:
	std::array<Card*, 10> deck;
	void setUpCards();
public:
	DrawSpace(std::string name, int pos);
	virtual void action(Player p);
	virtual void display();
};