#include "Board.h"
#include <iostream>
#include <iomanip>
#include "Property.h"

using namespace std;

Board::Board(std::array<BoardSpace*, 40> spaces)
	:board{ spaces }
{
	this->die1 = 0;
	this->die2 = 0;
	this->playerName = "";
}

void Board::display()
{
	//display the board with GO in the lower left corner

	//print top row of the board
	const int TOP_RIGHT{ 21 };
	cout << "\t";
	for (int topSpace{ 10 }; topSpace < TOP_RIGHT; topSpace++)
	{
		cout << board[topSpace]->toString();
	}
	cout << endl;

	//print both sides of the board and display dice rolls in the middle
	int leftSide{ 9 };
	int rightSide{ 21 };
	const int NUM_SIDE_SPACES{ 9 };
	bool rolled{ false };

	for (int i{ 0 }; i < NUM_SIDE_SPACES; i++)
	{
		cout << "\t";
		if (i == 2 && playerName != "")
		{
			cout << board[leftSide]->toString() << this->printWord(playerName) << board[rightSide]->toString() << endl;
			rolled = true;
		}
		else if (i == 3 && rolled)
		{
			cout << board[leftSide]->toString() << this->printWord("  rolled:") << board[rightSide]->toString() << endl;
		}
		else if (i == 4)
		{
			cout << board[leftSide]->toString() << setw(12) << right << "[" << die1 << "]"
				<< "[" << die2 << "]" << setw(13) << board[rightSide]->toString() << endl;
		}
		else
		{
			cout << board[leftSide]->toString() << setw(30) << right << board[rightSide]->toString() << endl;
		}
		leftSide--;
		rightSide++;
	}

	//print bottom of the board
	const int BOTTOM_LEFT{ 30 };
	cout << "\t";
	cout << board[0]->toString();
	for (int bottomSpace{ 39 }; bottomSpace >= BOTTOM_LEFT; bottomSpace--)
	{
		cout << board[bottomSpace]->toString();
	}
	cout << endl;
}

BoardSpace& Board::getSpace(int i)
{
	return *this->board[i];
}

Board& Board::setDie(int dieNum, int roll)
{
	if (dieNum == 1)
	{
		this->die1 = roll;
	}
	if (dieNum == 2)
	{
		this->die2 = roll;
	}
	return *this;
}

Board& Board::resetDice()
{
	this->die1 = 0;
	this->die2 = 0;
	return *this;
}

Board& Board::setPlayerName(std::string name)
{
	this->playerName = name;
	return *this;
}

Board& Board::resetPlayerName()
{
	this->setPlayerName("");
	return *this;
}

void Board::displayOwners()
{
	// show all properties and their owners
	for (auto& space : this->board)
	{
		space->getInfo();
	}
}

void Board::displayOwner(Player& owner)
{
	// show all properties of a single owner
	for (auto& space : this->board)
	{
		if (space->getOwner() == owner)
		{
			space->getInfo();
		}
	}
}

int Board::getBoardSize()
{
	return this->boardSize;
}

std::string Board::printWord(std::string word)
{
	string result{ "" };

	int innerWidth{ 27 };
	size_t wordWidth{ word.size() };

	int spaces = innerWidth - wordWidth;
	int spacesLeft = spaces / 2;
	int spacesRight = spaces / 2 + spaces % 2;

	result += string(spacesLeft, ' ') + word + string(spacesRight, ' ');

	return result;

}

