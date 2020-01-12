#include "DrawSpace.h"
#include <iostream>
#include "cardMove.h"
#include "cardMoney.h"
#include "GoToJailCard.h"
#include "cardgetoutofjail.h"
#include <iomanip>
using namespace std;

std::array<Card*, 10> DrawSpace::community{};
std::array<Card*, 10> DrawSpace::chance{};
int DrawSpace::communityCount{ 0 };
int DrawSpace::chanceCount{ 0 };

DrawSpace::DrawSpace(std::string name, int pos)
	:NonProperty(name, pos)
{
	/*this->chanceCount = 0;
	this->communityCount = 0;*/
	this->setUpCards();
	srand(time(NULL));
	this->shuffleDeck(DrawSpace::chance);
}

void DrawSpace::action(Player& p)
{
	if (this->getName() == "Chance")
	{
		cout << "You landed on Chance!" << endl;
		this->getChanceCard(DrawSpace::chanceCount).cardAction(this->getOwner(), p);
		//increment counter
		DrawSpace::chanceCount++;
		//if reached end of array, restart
		if (DrawSpace::chanceCount > 9) {
			DrawSpace::chanceCount = 0;
			this->shuffleDeck(DrawSpace::chance);
		}
	}
	else if (this->getName() == "Community Chest")
	{
		DrawSpace::community[communityCount]->cardAction(this->getOwner(), p);
		//increment counter
		communityCount++;
		//if reached end of array, restart
		if (communityCount > 9) {
			communityCount = 0;
			this->shuffleDeck(DrawSpace::community);
		}
	}
}

void DrawSpace::display()
{
	if (this->getName() == "Chance")
	{
		cout << "\t __________________\n"
			<< "\t|                  |\n"
			<< "\t|     ,------.     |\n"
			<< "\t|    /  .--.  '    |\n"
			<< "\t|    |  |  |  |    |\n"
			<< "\t|    `--'__.  |    |\n"
			<< "\t|       |   .'     |\n"
			<< "\t|       |___|      |\n"
			<< "\t|       .---.      |\n"
			<< "\t|       `---'      |\n"
			<< "\t|                  |\n"
			<< "\t|__________________|\n";
	}
	if (this->getName() == "Community Chest")
	{
		cout << "\t ___________________\n"
			<< "\t|                   |\n"
			<< "\t|     __________    |\n"
			<< "\t|    /\\____;;___\\   |\n"
			<< "\t|   |/         /    |\n"
			<< "\t|   `. ())oo() .    |\n"
			<< "\t|    |\\(%()*^^()^\\  |\n"
			<< "\t|   %| |-%-------|  |\n"
			<< "\t|  % \\ | %  ))   |  |\n"
			<< "\t|  %  \\|%________|  |\n"
			<< "\t|   %%%%            |\n"
			<< "\t|                   |\n"
			<< "\t|___________________|\n";
	}
}

void DrawSpace::setUpCards()
{
	CardGetOutOfJail* community1 = new CardGetOutOfJail{};
	CardMove* community2 = new CardMove{};
	CardMoney* community3 = new CardMoney{};
	CardMoney* community4 = new CardMoney{};
	CardMove* community5 = new CardMove{};
	CardMove* community6 = new CardMove{};
	CardMoney* community7 = new CardMoney{};
	CardMoney* community8 = new CardMoney{};
	CardMoney* community9 = new CardMoney{};
	CardMove* community10 = new CardMove{};

	//buildling community deck
	DrawSpace::community[0] = community1;
	DrawSpace::community[1] = community2;
	DrawSpace::community[2] = community3;
	DrawSpace::community[3] = community4;
	DrawSpace::community[4] = community5;
	DrawSpace::community[5] = community6;
	DrawSpace::community[6] = community7;
	DrawSpace::community[7] = community8;
	DrawSpace::community[8] = community9;
	DrawSpace::community[9] = community10;

	//move
	community1->setCardText("Get out of Jail"); //work this out
	//move
	community2->setCardText("Go back? No good at all! Go sideways? Impossible! Go forward? Only thing to do, on you go!");
	community2->setAmount(0);
	//money
	community3->setCardText("You travel for free on Boromir's funeral boat. Save on travel fees.");
	community3->setAmount(100);
	//money
	community4->setCardText("The King under the Mountain shares not a mountain of gold, but at least something.");
	community4->setAmount(20);
	//move
	community5->setCardText("The eagles! The Eagles are coming! Why hadn't they come sooner? Advance to WHATSFREEPARKING and ponder.");
	community5->setAmount(20);
	//move to jail
	community6->setCardText("Never laugh at live dragons, you fool!");
	community6->setAmount(30);
	//money
	community7->setCardText("");
	community7->setAmount(200);
	//money
	community8->setCardText("");
	community8->setAmount(150);
	//money
	community9->setCardText("");
	community9->setAmount(70);
	//move
	community10->setCardText("Mirkwood they said, it'll be fun they said!");
	community10->setAmount(39);

	CardMove* chance1 = new CardMove{};
	GoToJailCard* chance2 = new GoToJailCard{};
	CardMoney* chance3 = new CardMoney{};
	CardMoney* chance4 = new CardMoney{};
	CardMove* chance5 = new CardMove{};
	CardMoney* chance6 = new CardMoney{};
	CardMoney* chance7 = new CardMoney{};
	CardMoney* chance8 = new CardMoney{};
	CardMoney* chance9 = new CardMoney{};
	CardMove* chance10 = new CardMove{};
	
	//MOVE send to GO
	chance1->setCardText("You're going on an adventure, advance to GO!");
	chance1->setAmount(0);
	//MOVE send to Dragon/Jail
	chance2->setCardText("Hide your gold! To the Dragon's Lair with you!");
	chance2->setAmount(10);
	//MONEY
	chance3->setCardText("A Birthday Party thrown in your honor!");
	chance3->setAmount(100);
	//MONEY
	chance4->setCardText("You stumble upon a chest and find $50!");
	chance4->setAmount(50);
	//MOVE
	chance5->setCardText("What fine clothes you have! Advance to Luxury Tax!");
	chance5->setAmount(38);
	//MOVE
	chance6->setCardText("Unexpected guests arrive! They're pleasant and chip in for First Dinner!");
	chance6->setAmount(100);
	//MONEY
	chance7->setCardText("Someone picks up your tab at The Inn of the Prancing Pony! Here's $30!");
	chance7->setAmount(30);
	//MONEY
	chance8->setCardText("You find rare minerals in Moria, worth $150!");
	chance8->setAmount(150);
	//MONEY
	chance9->setCardText("You stay for free at The Green Dragon Inn!");
	chance9->setAmount(100);
	//MOVE what are we calling free parking?
	chance10->setCardText("You get turned around and don't know where to go. Time to take a break and find your next move!");
	chance10->setAmount(20);

	DrawSpace::chance[0] = chance1;
	DrawSpace::chance[1] = chance2;
	DrawSpace::chance[2] = chance3;
	DrawSpace::chance[3] = chance4;
	DrawSpace::chance[4] = chance5;
	DrawSpace::chance[5] = chance6;
	DrawSpace::chance[6] = chance7;
	DrawSpace::chance[7] = chance8;
	DrawSpace::chance[8] = chance9;
	DrawSpace::chance[9] = chance10;
}

Card& DrawSpace::getChanceCard(int num)
{
	return *DrawSpace::chance[num];
}

Card& DrawSpace::getCommunityCard(int num)
{
	return *this->community[num];
}

void DrawSpace::shuffleDeck(std::array<Card*, 10> &deck)
{
	
	/*for (int i = 0; i < 10; i++) {
		deck[i] = i;
	}*/
	int randomNum = -1;
	Card* temp{};

	for (int i = 0; i < 10; i++) {
		randomNum = rand() % 10;
		temp = deck[i];
		deck[i] = deck[randomNum];
		deck[randomNum] = temp;
	}
}
