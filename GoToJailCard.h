#pragma once
#include "cardMove.h"
class GoToJailCard : public CardMove
{
private:

public:
	GoToJailCard();
	virtual void cardAction(Player& bank1, Player& player1);
};