#include "cardMove.h"
#include <iostream>
using namespace std;

CardMove::CardMove() : Card() {
	cardText = "Card Name";
	posNum = -1;
}

void CardMove::setAmount(int num) {
	posNum = num;
}

void CardMove::setCardText(string text) {
	cardText = text;
}

void CardMove::cardAction(Player& bank1, Player& player) {
	cout << this->getCardText() << endl;
	player.setPosition(posNum);
}

string CardMove::getCardText() {
	return cardText;
}

int CardMove::getPosNum()
{
	return this->posNum;
}
