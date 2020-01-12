#pragma once
#include <string>
#include "Player.h"
class BoardSpace
{
private:
	std::string name;
	int pos;
	std::string spaceString;
	std::string blankSpace;
	bool owned;
	Player* owner;
public:
	BoardSpace(std::string name, int pos);
	std::string getName();
	void setName(std::string name);
	int getPos();
	void setPos(int pos);
	std::string getSpaceString();
	void setSpaceString(std::string str);
	void resetSpaceString();
	std::string toString();
	void tradeTo(Player& player, int amount);
	
	
	Player& getOwner();
	bool isOwned();
	void setIsOwned(bool setIsOwned);

	virtual int getCost();
	virtual std::string getGroup();
	virtual void setMortgaged(bool m);
	virtual bool isMortgaged();
	virtual bool getInfo();
	virtual void setOwner(Player& owner, bool setIsOwned = true);
	virtual void action(Player& p);
	virtual void display();

//protected:
//	Player* owner;
//	bool owned;
};