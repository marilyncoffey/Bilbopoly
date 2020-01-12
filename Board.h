#pragma once
#include <array>
#include "BoardSpace.h"
class Board
{
private:
	static const int boardSize{ 40 };
	std::array<BoardSpace*, boardSize> board;
	int die1;
	int die2;
	std::string playerName;
	std::string printWord(std::string word); //print word inside of the board
public:
	Board() {};
	Board(std::array<BoardSpace*, boardSize> spaces);
	void display();
	BoardSpace& getSpace(int i);
	Board& setDie(int dieNum, int roll);
	Board& resetDice();
	Board& setPlayerName(std::string name);
	Board& resetPlayerName();
	void displayOwners();
	void displayOwner(Player& owner);
	int getBoardSize();
};