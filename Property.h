#pragma once
#include "BoardSpace.h"
class Property : public BoardSpace
{
private:
	int cost;
	int rent;
	std::string group;
	bool mortgaged;
public:
	Property(std::string name, int pos, int cost, int rent, std::string group);
	int getRent();
	void setRent(int rent);
	
	void setCost(int cost);
	void setGroup(std::string group);
	virtual void tradeTo(Player& player, int amount);
	
	//bool isOwned();
	virtual int getCost() override;
	virtual void setMortgaged(bool m) override;
	virtual bool isMortgaged() override;
	virtual bool getInfo() override;
	virtual void action(Player& p) override;
	virtual void display() override;
	virtual std::string getGroup() override;
	
	std::string printDeedFormat(std::string str);
	std::string printDeedFormat(int numRows = 1);
};