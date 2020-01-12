#include "TaxSpace.h"
#include <iostream>
using namespace std;

TaxSpace::TaxSpace(std::string name, int pos, int taxAmount)
	:NonProperty(name, pos), taxAmount{ taxAmount }
{
}

int TaxSpace::getTaxAmount()
{
	return this->taxAmount;
}

void TaxSpace::display()
{
	if (this->getName() == "Luxury Tax")
	{
		cout << "\t ___________ \n"
			<< "\t|           |\n"
			<< "\t|           |\n"
			<< "\t|   LUXURY  |\n"
			<< "\t|    TAX    |\n"
			<< "\t|    PAY    |\n"
			<< "\t|    $75    |\n"
			<< "\t|           |\n"
			<< "\t|___________|\n";
	}
	else if (this->getName() == "Income Tax")
	{
		cout << "\t ___________ \n"
			<< "\t|           |\n"
			<< "\t|           |\n"
			<< "\t|   INCOME  |\n"
			<< "\t|    TAX    |\n"
			<< "\t|    PAY    |\n"
			<< "\t|    $200   |\n"
			<< "\t|           |\n"
			<< "\t|___________|\n";
	}
	
}

void TaxSpace::action(Player& p)
{
	cout << "\t" << p.getName() << " pays " << this->taxAmount << " to the bank." << endl;
	p.pay(this->getOwner(), this->taxAmount);
}
