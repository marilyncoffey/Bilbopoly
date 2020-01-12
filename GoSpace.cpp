#include "GoSpace.h"
#include <iostream>
using namespace std;

GoSpace::GoSpace(std::string name, int pos)
	:NonProperty(name,pos)
{
}

void GoSpace::display()
{
	cout << "\t _____________________ \n"
		 << "\t|                     |\n"
		 << "\t|                     |\n"
		 << "\t|     _____ _____     |\n"
		 << "\t|    |   __|     |    |\n"
		 << "\t|    |  |  |  |  |    |\n"
		 << "\t|    |_____|_____|    |\n"
		 << "\t|                     |\n"
		 << "\t|                     |\n"
		 << "\t|_____________________|\n";

}

void GoSpace::action(Player& p)
{

}


