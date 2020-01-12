#pragma once
#include <vector>
#include "Player.h"
#include "BoardSpace.h"
#include "Board.h"
#include "card.h"
class Game
{
private:
	std::vector<Player> players;
	int playerCounter;
	Board board;
	Player banker;
	int numberOfPlayers = players.size();

public:
	Game(std::vector<Player>& players);
	void play();
	void playerLose(Player& p);
	void viewProperties(Player& p);
	bool railRoadTravel(Player& activePlayer);
	void displayGameInfo(Player& activePlayer);
	void checkForMorePlayers(Player& activePlayer);
	void changeActivePlayer();
	void mortgageProperty(Player& activePlayer);
	void unMortgageProperty(Player& activePlayer);
	bool jailTurn(Player& activePlayer);
	bool normalTurn(Player& activePlayer);
	void checkUtilityOwners();
	void checkRailRoadOwners();
	bool rollChoice(Player& activePlayer);
	void trade(Player& currentPlayer, Player& trader);
    int getNumberOfPlayers();
	std::string getWinner();

	static std::string winner;
};