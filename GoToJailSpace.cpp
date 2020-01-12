#include "GoToJailSpace.h"
#include <iostream>
using namespace std;

GoToJailSpace::GoToJailSpace(std::string name, int pos)
	:NonProperty(name,pos)
{
}

void GoToJailSpace::action(Player& p)
{
	p.setPosition(10);
	p.setInJail(true);
	cout << "\t" << p.getName() << " is sent to jail." << endl;
}

void GoToJailSpace::display()
{
	cout << "\t ________________________ \n"
		<< "\t|       _________        |\n"
		<< "\t|      / ___/ __ \\       |\n"
		<< "\t|     / (_ / /_/ /       |\n"
		<< "\t|     \\___/\\____/_       |\n"
		<< "\t|     /_   __/ __ \\      |\n"
		<< "\t|      /  / / /_/ /      |\n"
		<< "\t|     /_ /__\\____/_ __   |\n"
		<< "\t|      / / _ | /  _/ /   |\n"
		<< "\t|  / // / __ |_/ // /__  |\n"
		<< "\t|  \\___/_/ |_/___/____/  |\n"
		<< "\t|________________________|\n";
}
