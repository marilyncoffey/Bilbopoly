#pragma once
#include <string>
#include "card.h"

class CardGetOutOfJail : public Card {
private:
    std::string cardText;

public:
    CardGetOutOfJail();
    virtual void setAmount(int num) override;
    virtual void setCardText(std::string text) override;
    virtual void cardAction(Player& bank1, Player& activePlayer);
    virtual std::string getCardText();

};
