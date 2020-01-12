#pragma once
#include "card.h"
#include <string>

class CardMoney : public Card {

private:
	std::string cardText;
	int moneyAmount;

public:
	CardMoney();
	void setAmount(int num);
	void setCardText(std::string text1);
	void cardAction(Player& bank1, Player& player1);
	std::string getCardText();
};
