#include "Player.h"
#include <time.h>
#include <string>
#include <iostream>
#include "Property.h"
using namespace std;

std::default_random_engine Player::engine(time(0));
std::uniform_int_distribution<int> Player::randInt(1, 6);
int Player::numPlayers{ 0 };

Player::Player()
{
}

Player::Player(std::string name)
	:name{ name }
{
	numPlayers++;
	this->position = 0;
	this->gamePiece = "[" + to_string(numPlayers) + "]";
	this->bank = 200;
	this->bankrupt = false;
	this->jailCounter = 0;
	this->inJail = false;
	this->diceTotal = 0;
	this->numUtilities = 0;
	this->doublesCount = 0;
}

std::string Player::getName()
{
	return this->name;
}

int Player::getPosition()
{
	return this->position;
}

void Player::setPosition(int pos)
{
	this->position = pos;
}

bool Player::isInJail()
{
	return this->inJail;
}

void Player::setInJail(bool j)
{
	this->inJail = j;
}

int Player::roll()
{
	return randInt(engine);
}

int Player::getDiceTotal()
{
	return this->diceTotal;
}

void Player::setDiceTotal(int total)
{
	this->diceTotal = total;
}

int Player::move(int roll)
{
	this->position = (this->position + roll) % 40;

	return this->position;
}

int Player::getBank()
{
	return this->bank;
}

void Player::setBank(int amount)
{
	this->bank = amount;
}

//void Player::pay(Player& other, int amount)
//{
//	this->setBank(this->getBank() - amount);
//	other.receive(amount);
//}

void Player::pay(Player& payee, int amount)
{
	if (this->bank >= amount)
	{
		this->bank -= amount;
	}
	else
	{
		amount = this->bank;
		this->bank = 0;
		this->checkBankrupt();
	}
	int payment = payee.getBank() + amount;
	payee.setBank(payment);

}

bool Player::isBankrupt()
{
	return this->bankrupt;
}

void Player::checkBankrupt()
{
	if (this->bank <= 0)
	{
		std::cout << "\n\n" << endl;
		std::cout << "\t" << this->getName() << " is Bankrupt, Game Over!" << endl;
		this->bankrupt = true;
	}
}

void Player::receive(int amount)
{
	this->bank += amount;
}

void Player::goToJail()
{
	this->position = 10;
}

int Player::getJailCounter()
{
	return this->jailCounter;
}

void Player::setJailCounter(int count)
{
	this->jailCounter = count;
}

void Player::getOutOfJail()
{
}

void Player::setUtilityCount(int count)
{
	this->numUtilities = count;
}

int Player::getUtilityCount()
{
	return this->numUtilities;
}

void Player::setRailRoadCount(int count)
{
	this->numRailRoads = count;
}

int Player::getRailRoadCount()
{
	return this->numRailRoads;
}

void Player::setDoublesCount(int count)
{
	this->doublesCount = count;
}

int Player::getDoublesCount()
{
	return this->doublesCount;
}

void Player::operator=(Player& p)
{
	this->bank = p.bank;
	this->position = p.position;
	this->gamePiece = p.gamePiece;
	this->name = p.name;
}

bool Player::operator==(Player& p)
{
	if (this->bank == p.getBank() &&
		this->position == p.getPosition() &&
		this->gamePiece == p.getGamePiece() &&
		this->name == p.getName())
	{
		return true;
	}
	return false;
}

std::string Player::getGamePiece()
{
	return this->gamePiece;
}

void Player::setHasJailCard(bool y)
{
   this-> hasJailCard = y;
}
bool Player::doesHaveJailCard()
{
    return this->hasJailCard;
}
