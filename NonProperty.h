#pragma once
#include "BoardSpace.h"
class NonProperty : public BoardSpace
{
private:

public:
	NonProperty(std::string name, int pos);
	virtual void action(Player& p) override;
	virtual void display() override;
};