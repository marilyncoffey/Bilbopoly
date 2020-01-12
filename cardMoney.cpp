#include "cardMoney.h"
#include <iostream>
using namespace std;

CardMoney::CardMoney() : Card() {
	cardText = "Card Name";
	moneyAmount = 0;
}

void CardMoney::setAmount(int num) {
	moneyAmount = num;
}

void CardMoney::setCardText(string text) {
	cardText = text;
}

void CardMoney::cardAction(Player& bank1, Player& player1) {
	cout << this->getCardText() << endl;
	bank1.setBank(bank1.getBank() - moneyAmount);
	player1.setBank(player1.getBank() + moneyAmount);
}

string CardMoney::getCardText() {
	return cardText;
}
