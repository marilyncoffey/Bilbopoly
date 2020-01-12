#pragma once
#include "NonProperty.h"
class GoToJailSpace : public NonProperty
{
private:

public:
	GoToJailSpace(std::string name, int pos);
	virtual void action(Player& p) override;
	virtual void display() override;
};