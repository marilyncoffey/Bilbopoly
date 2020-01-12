#pragma once
#include "card.h"

class CardMove : public Card {
private:
	std::string cardText;
	int posNum;

public:
	CardMove();
	void setAmount(int num);
	void setCardText(std::string text1);
	void cardAction(Player& bank1, Player& player1);
	std::string getCardText();
	int getPosNum();
};
