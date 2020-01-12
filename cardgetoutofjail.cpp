#include "cardgetoutofjail.h"

using namespace std;

CardGetOutOfJail::CardGetOutOfJail(): Card(){
    cardText = "Card Name";
}
void CardGetOutOfJail::setAmount(int num){

}
void CardGetOutOfJail::setCardText(string text){
    cardText = text;
}
void CardGetOutOfJail::cardAction(Player& bank1, Player& activePlayer)
{
    activePlayer.setHasJailCard(true);
}
string CardGetOutOfJail::getCardText(){
    return cardText;
}
