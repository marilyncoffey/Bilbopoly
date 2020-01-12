#include "GoToJailCard.h"
#include <iostream>
using namespace std;

GoToJailCard::GoToJailCard()
{
}

void GoToJailCard::cardAction(Player& bank1, Player& player)
{
	cout << this->getCardText() << endl;
	player.setPosition(this->getPosNum());
	player.setInJail(true);
}
