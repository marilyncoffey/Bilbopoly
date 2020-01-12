#include "IncomeTaxSpace.h"
#include <iostream>

using namespace std;

IncomeTaxSpace::IncomeTaxSpace(std::string name, int pos, int taxAmount)
	:TaxSpace(name,pos,taxAmount)
{
}

void IncomeTaxSpace::display()
{
	cout << "\t ___________ \n"
		<< "\t|           |\n"
		<< "\t|    PAY    |\n"
		<< "\t|    10%    |\n"
		<< "\t|    OR     |\n"
		<< "\t|   $200    |\n"
		<< "\t|           |\n"
		<< "\t|___________|\n";
}

void IncomeTaxSpace::action(Player& player)
{

	cout << player.getName() << " pays " << this->getTaxAmount() << " to the bank." << endl;
	player.pay(this->getOwner(), this->getTaxAmount());
}
