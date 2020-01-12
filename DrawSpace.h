#pragma once
#include "NonProperty.h"
#include "card.h"
#include <array>
class DrawSpace : public NonProperty
{
private:
	static std::array<Card*, 10> community;
	static std::array<Card*, 10> chance;
	static int communityCount;
	static int chanceCount;
	void shuffleDeck(std::array<Card*, 10> &deck);
public:
	DrawSpace(std::string name, int pos);
	virtual void action(Player& p);
	virtual void display();
	void setUpCards();
	Card& getChanceCard(int num);
	Card& getCommunityCard(int num);
};