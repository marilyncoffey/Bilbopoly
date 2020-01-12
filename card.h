#pragma once
#include <string>
#include "Player.h"

class Card {

private:
	std::string name;

public:
	Card();
	virtual void setAmount(int num)=0;
	virtual void setCardText(std::string text)=0;
	virtual void cardAction(Player& bank1, Player& player1)=0;
	virtual std::string getCardText()=0;

};