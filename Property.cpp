#include "Property.h"
#include <iostream>
#include "Player.h"
#include <iomanip>
using namespace std;

Property::Property(std::string name, int pos, int cost, int rent, std::string group)
	:BoardSpace(name, pos), cost{ cost }, rent{ rent }, group{ group }
{
	this->setIsOwned(false);
	this->setMortgaged(false);
}

int Property::getRent()
{
	return this->rent;
}

void Property::setRent(int rent)
{
	this->rent = rent;
}

int Property::getCost()
{
	return this->cost;
}

void Property::setCost(int cost)
{
	this->cost = cost;
}

string Property::getGroup()
{
	return this->group;
}

void Property::setGroup(std::string group)
{
	this->group = group;
}


//Player& Property::getOwner()
//{
//	return *this->owner;
//}

void Property::tradeTo(Player& player, int amount)
{
	this->getOwner().pay(player, amount);
	this->setOwner(player, true);
}

void Property::setMortgaged(bool m)
{
	this->mortgaged = m;
}

bool Property::isMortgaged()
{
	return this->mortgaged;
}

bool Property::getInfo()
{
	cout << "\t" << this->getPos() << ") " << setw(20) << left << this->getName() << this->getGroup();
	if (!this->getOwner().getName().empty())
	{
		cout << " -----[" <<this->getOwner().getName() << "]";
	}
	if (this->isMortgaged())
	{
		cout << " (Mortgaged)";
	}
	cout << "\n" << endl;
	
	return true;
}

void Property::action(Player& p)
{
	if (!this->isOwned())
	{
		string choice;
		cout << "\tWould you like to buy " << this->getName() << "? (y/n): ";
		cin >> choice;
		cout << endl;
		if (choice == "y")
		{
			if (p.getBank() >= this->getCost())
			{
				p.pay(this->getOwner(), this->getCost());
				this->setOwner(p);
			}
			else
			{
				cout << p.getName() << " does not have enough money to buy this Property." << endl;
			}
		}
	}
	else if (this->isOwned() && !this->mortgaged && p.getGamePiece() != this->getOwner().getGamePiece())
	{
		cout <<"\t" << p.getName() << " pays " << this->getOwner().getName() << " $" << this->getRent() << endl;
		p.pay(this->getOwner(), this->getRent());
	}
	else if (this->isMortgaged() == true)
	{
		cout << "\t" << this->getName() << " is mortgaged. No rent is due." << endl;
	}
}



void Property::display()
{
	string topBorder{ "\t ------------------------------ \n" };
	string midBorder{ "\t|------------------------------|\n" };
	string bottomBorder{ "\t|______________________________|\n" };
	cout << topBorder
		<< printDeedFormat()
		<< printDeedFormat(this->getName())
		<< printDeedFormat("(" + this->getGroup() + ")")
		<< midBorder
		<< printDeedFormat("Cost: $" + to_string(this->getCost()))
		<< printDeedFormat("Rent $" + to_string(this->rent))
		<< printDeedFormat()
		<< printDeedFormat("With 1 House      $" + to_string(this->rent * 2))
		<< printDeedFormat("With 2 Houses     $" + to_string(this->rent * 4))
		<< printDeedFormat("With 3 Houses     $" + to_string(this->rent * 6))
		<< printDeedFormat("With 4 Houses     $" + to_string(this->rent * 8))
		<< printDeedFormat()
		<< printDeedFormat("With Hotel $" + to_string(this->rent * 12))
		<< printDeedFormat()
		<< printDeedFormat("Mortgage Value $" + to_string(this->getCost() / 2))
		<< printDeedFormat("Houses Cost $" + to_string(this->getCost() / 2) + " each")
		<< printDeedFormat("Hotels, $" + to_string(this->getCost() / 2) + " plus 4 houses")
		<< bottomBorder;
}

string Property::printDeedFormat(string str)
{
	string result{ "" };
	int deedWidth{ 30 };
	size_t strWidth{ str.size() };

	int spaces = deedWidth - strWidth;
	int spacesLeft = spaces / 2;
	int spacesRight = spaces / 2 + spaces % 2;

	result += "\t|" + string(spacesLeft, ' ') + str + string(spacesRight, ' ') + "|\n";

	return result;
}

string Property::printDeedFormat(int numRows)
{
	string result{ "" };
	for (int i{ 0 }; i < numRows; i++)
	{
		result += "\t|" + string(30, ' ') + "|\n";
	}

	return result;
}

