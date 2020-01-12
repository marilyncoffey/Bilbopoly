#pragma once
#include <random>

class Player
{
	static std::default_random_engine engine;
	static std::uniform_int_distribution<int> randInt;
	static int numPlayers;
private:
	std::string name;
	std::string gamePiece;
	int diceTotal;

	int position;

	int bank;
	int jailCounter;
	int numUtilities;
	int numRailRoads;
	int doublesCount;
	bool inJail;
	bool bankrupt;
	bool hasJailCard;

public:
	Player();
	Player(std::string name);
	std::string getGamePiece();
	std::string getName();
	int roll();
	int getDiceTotal();
	void setDiceTotal(int total);
	int getPosition();
	void setPosition(int pos);
	bool isInJail();
	void setInJail(bool j);
	int move(int roll);
	int getBank();
	void setBank(int amount);
	void pay(Player& other, int amount);
	bool isBankrupt();
	void checkBankrupt();
	void receive(int amount);
	void goToJail();
	int getJailCounter();
	void setJailCounter(int count);
	void getOutOfJail();
	void setUtilityCount(int count);
	int getUtilityCount();
	void setRailRoadCount(int count);
	int getRailRoadCount();
	void setDoublesCount(int count);
	int getDoublesCount();
	void setHasJailCard(bool);
	bool doesHaveJailCard();
	void operator=(Player& p);
	bool operator==(Player& p);
};