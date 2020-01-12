#include "Game.h"
#include "NonProperty.h"
#include "Property.h"
#include <iostream>
#include "GoSpace.h"
#include "TaxSpace.h"
#include "DrawSpace.h"
#include "GoToJailSpace.h"
#include "UtilitySpace.h"
#include "card.h"
#include "cardMove.h"
#include "cardMoney.h"
#include "JailSpace.h"
#include "RailRoadSpace.h"

using namespace std;

std::string Game::winner{ "" };

Game::Game(std::vector<Player>& players)
	:players{ players }
{
	this->banker.setBank(1000000);
	this->playerCounter = 0;
	GoSpace a{ "The Shire", 0 };
	Property b{ "Bag End", 1, 60, 2, "purple" };
	DrawSpace c{ "Community Chest", 2 };
	Property d{ "The Green Dragon Inn", 3, 60, 4, "purple" };
	TaxSpace e{ "Income Tax", 4, 200 };
	RailRoadSpace f{ "Long Long Lake", 5, 200, 25, "railroad" };
	Property g{ "High Pass", 6, 100, 6, "light blue" };
	DrawSpace h{ "Chance", 7 };
	Property i{ "Goblin Town", 8, 100, 6, "light blue" };
	Property j{ "Eagles' Eyrie", 9, 120, 8, "light blue" };
	JailSpace k{ "Smaug's Lair", 10 };
	Property l{ "Beorn's Hall", 11, 140, 10, "pink" };
	UtilitySpace m{ "Gandalf's Pipe", 12, 150, 0, "utility" };
	Property n{ "Mirkwood", 13, 140, 10, "pink" };
	Property o{ "Thranduil's Hall", 14, 160, 12, "pink" };
	RailRoadSpace p{ "Gollum's Lake", 15, 200, 25, "railroad" };
	Property q{ "Esgaroth", 16, 180, 14, "orange" };
	DrawSpace r{ "Community Chest", 17 };
	Property s{ "Bard the Bowman's House", 18, 180, 14, "orange" };
	Property t{ "The Lonely Mountain", 19, 200, 16, "orange" };
	NonProperty u{ "The Inn of the Prancing Pony", 20 };
	Property v{ "The River Running", 21, 220, 18, "red" };
	DrawSpace w{ "Chance", 22 };
	Property x{ "Dale", 23, 220, 18, "red" };
	Property y{ "Front Gate", 24, 240, 20, "red" };
	RailRoadSpace z{ "Nen Hithoel", 25, 200, 25, "railroad" };
	Property aa{ "Erebor", 26, 260, 22, "yellow" };
	Property bb{ "Great Hall of Thrain", 27, 260, 22, "yellow" };
	UtilitySpace cc{ "Bilbo's Pipe", 28, 150, 0, "utility" };
	Property dd{ "Raven Hill", 29, 280, 24, "yellow" };
	GoToJailSpace ee{ "Desolated by Smaug", 30 };
	Property ff{ "Woodland Realm", 31, 300, 26, "green" };
	Property gg{ "Dorwinion", 32, 300, 26, "green" };
	DrawSpace hh{ "Community Chest", 33 };
	Property ii{ "Faerie", 34, 320, 28, "green" };
	RailRoadSpace jj{ "Lake Evendim", 35, 200, 25, "railroad" };
	DrawSpace kk{ "Chance", 36 };
	Property ll{ "Iron Hills", 37, 350, 35, "blue" };
	TaxSpace mm{ "Luxury Tax", 38, 75 };
	Property nn{ "Kingdom Under the Mountain", 39, 400, 50, "blue" };

	std::array<BoardSpace*, 40> spaces{ &a,&b,&c,&d,&e,&f,&g,&h,&i,&j,&k,&l,&m,&n,&o,&p,&q,&r,&s,&t,&u,&v,&w,&x,&y,&z,&aa,&bb,&cc,&dd,&ee,&ff,&gg,&hh,&ii,&jj,&kk,&ll,&mm,&nn };
	for (auto& s : spaces)
	{
		s->setOwner(this->banker, false);
	}
	this->board = { spaces };
	this->play();
}
//--------------------------------------------------------------------------------------------------------------------
int getNumberOfPlayers()
{
    return this->numberOfPlayers;
}
//---------------------------------------------------------------------------------------------------------------------

void Game::play()
{
	bool haveWinner{ false };

	while (!haveWinner)
	{
		Player& activePlayer = this->players[this->playerCounter];
		bool endTurn{ false };
		while (!endTurn && activePlayer.isBankrupt() == false)
		{
			this->checkUtilityOwners();
			this->checkRailRoadOwners();
			if (activePlayer.isInJail() == false)
			{
				endTurn = this->normalTurn(activePlayer);
			}
			else
			{
				endTurn = this->jailTurn(activePlayer);
			}
		}

		if (activePlayer.isBankrupt())
		{
			for (int i{ 0 }; i < this->board.getBoardSize(); i++)
			{
				if (this->board.getSpace(i).getOwner() == activePlayer)
				{
					this->board.getSpace(i).setOwner(this->banker);
					this->board.getSpace(i).setIsOwned(false);
				}
			}
		}

		this->changeActivePlayer();
	}
	Game::winner = "Player1";
}

//---------------------------------------------------------------------------------------------------------------------

void Game::playerLose(Player& curPlayer)
{

	if (curPlayer.isBankrupt() == true)
	{

		for (int i{ 0 }; i < this->board.getBoardSize(); ++i)
		{
			if (this->board.getSpace(i).getOwner().getGamePiece() == curPlayer.getGamePiece())
			{
				this->board.getSpace(i).setOwner(this->banker, false);
			}
		}
	}

}

//---------------------------------------------------------------------------------------------------------------------

// if player chooses to roll
bool Game::rollChoice(Player& activePlayer)
{
    system("cls");

	bool doubles = false;	
	bool endTurn{ true };

	int die1{ activePlayer.roll() };
	int die2{ activePlayer.roll() };
	/*int die1{ 4 };
	int die2{ 4 };*/
	int roll{ die1 + die2 };
	activePlayer.setDiceTotal(roll);

	if (die1 == die2)
	{
		doubles = true;
		endTurn = false;
		activePlayer.setDoublesCount(activePlayer.getDoublesCount() + 1);
		if (activePlayer.getDoublesCount() >= 3)
		{
			this->board.getSpace(activePlayer.getPosition()).resetSpaceString();
			activePlayer.setPosition(10);
			activePlayer.setInJail(true);
			activePlayer.setDoublesCount(0);
			this->board.getSpace(activePlayer.getPosition()).setSpaceString(activePlayer.getGamePiece());
			this->board.setPlayerName(activePlayer.getName()).setDie(1, die1).setDie(2, die2).display();
			this->displayGameInfo(activePlayer);
			cout << activePlayer.getName() << " has rolled 3 doubles in a row. Go to Jail!" << endl;
			endTurn = true;
			return endTurn;
		}
	}

	if (activePlayer.isInJail() == false)
	{
		this->checkForMorePlayers(activePlayer);

		activePlayer.move(roll);
		this->board.getSpace(activePlayer.getPosition()).setSpaceString(activePlayer.getGamePiece()); // show gamePiece where the player rolled to
		this->board.setPlayerName(activePlayer.getName()).setDie(1, die1).setDie(2, die2).display(); // displays the board and the information inside of it
	}
	else if (activePlayer.isInJail() == true)
	{
		if (doubles == false)
		{
			this->board.setPlayerName(activePlayer.getName()).setDie(1, die1).setDie(2, die2).display(); // displays the board and the information inside of it
			cout << "\tYou did not roll doubles." << endl;
			activePlayer.setJailCounter(activePlayer.getJailCounter() + 1);

			if (activePlayer.getJailCounter() >= 3)
			{
				cout << "\t" << activePlayer.getName() << " must pay a $50 fee and move forward." << endl;
				system("pause");
                system("cls");
				activePlayer.pay(this->banker, 50);
				activePlayer.move(roll);
				this->board.getSpace(activePlayer.getPosition()).setSpaceString(activePlayer.getGamePiece());
				this->board.setPlayerName(activePlayer.getName()).setDie(1, die1).setDie(2, die2).display();
				activePlayer.setInJail(false);
				activePlayer.setJailCounter(0);
			}
		}
		else if (doubles == true)
		{
			this->checkForMorePlayers(activePlayer);
			activePlayer.setInJail(false);
			activePlayer.setJailCounter(0);
			activePlayer.move(roll);
			this->board.getSpace(activePlayer.getPosition()).setSpaceString(activePlayer.getGamePiece());
			this->board.setPlayerName(activePlayer.getName()).setDie(1, die1).setDie(2, die2).display();
		}
		endTurn = true;
	}

	this->displayGameInfo(activePlayer);

	board.resetDice().resetPlayerName();

	return endTurn;
}

string Game::getWinner()
{
	return this->winner;
}

//---------------------------------------------------------------------------------------------------------------------

// if player chooses to view properties
void Game::viewProperties(Player& activePlayer)
{
    system("cls");
	string choice{ "" };
	cout << "\t" << activePlayer.getName() << "'s turn\n" << endl;
	
	// give choice to view player's property or show all properties and their owners
	cout << "\t1) View all properties" << endl;
	cout << "\t2) View your properties" << endl;
	cout << "\tChoice: ";
	cin >> choice;

	if (choice == "1")
	{
		this->board.displayOwners(); // board object function
		cout << "\n\t-------------------------\n"
			<< "\t1) View a property\n"
			<< "\t2) Exit\n"
			<< "\t-------------------------" << endl;
		cout << "\tChoice: ";
		cin >> choice;
		
		if (choice == "1")
		{
			int pos{ -1 };
			while (pos < 0 || pos >= this->board.getBoardSize())
			{
				cout << "\tEnter the property position number: ";
				cin >> pos;
			}
			this->board.getSpace(pos).display();
			system("pause");
		}
		else if (choice == "2")//to exit viewing their own property
            {

		 }
	}
	else if (choice == "2")
	{
		this->board.displayOwner(activePlayer); // board object function
		cout << "\n\t-------------------------\n"
			<< "\t1) Mortgage a property\n"
			<< "\t2) UnMortgage a property\n"
			<< "\t3) View a property\n"
			<< "\t4) Exit\n" 
			<< "\t-------------------------" << endl;
		cout << "\tChoice: ";
		cin >> choice;

		if (choice == "1")
		{
			this->mortgageProperty(activePlayer);
			system("pause");
		}
		else if (choice == "2")
		{
			this->unMortgageProperty(activePlayer);
			system("pause");
		}
		else if (choice == "3")
		{
			int pos{ -1 };
			while (pos < 0 || pos >= this->board.getBoardSize())
			{
				cout << "Enter the property position number: ";
				cin >> pos;
			}
			this->board.getSpace(pos).display();
			system("pause");
		}
		else if (choice == "4")
		{

		}
		
	}
    system("cls");
}

//---------------------------------------------------------------------------------------------------------------------

bool Game::railRoadTravel(Player& activePlayer)
{
	bool endTurn{ false };
	if (this->board.getSpace(activePlayer.getPosition()).getGroup() == "railroad")
	{
		if (this->board.getSpace(activePlayer.getPosition()).getOwner() == activePlayer)
		{
			int choice{ -1 };
			cout << "-------------------------------------------" << endl;
			cout << "Which RailRoad would you like to travel to?" << endl;
			cout << this->board.getSpace(5).getPos() << ") " << this->board.getSpace(5).getName() << endl;
			cout << this->board.getSpace(15).getPos() << ") " << this->board.getSpace(15).getName() << endl;
			cout << this->board.getSpace(25).getPos() << ") " << this->board.getSpace(25).getName() << endl;
			cout << this->board.getSpace(35).getPos() << ") " << this->board.getSpace(35).getName() << endl;
			cin >> choice;

			if (choice == 5 || choice == 15 || choice == 25 || choice == 35)
			{
				if (this->board.getSpace(choice).getOwner() == activePlayer &&
					activePlayer.getPosition() != choice)
				{
					this->board.getSpace(activePlayer.getPosition()).resetSpaceString();
					activePlayer.setPosition(choice);
					cout << activePlayer.getName() << " travels to " << this->board.getSpace(choice).getName() << endl;
					endTurn = true;
				}
				else if (activePlayer.getPosition() == choice)
				{
					cout << "You cannot travel to the RailRoad that you are currently on." << endl;
				}
				else
				{
					cout << "You cannot travel to this RailRoad." << endl;
				}
			}
			else
			{
				cout << "Invalid choice." << endl;
				if (!cin)
				{
					cin.clear();
					cin.ignore(5000000, '\n');
				}
			}
			system("pause");
            system("cls");
		}
		else
		{
			cout << "You must own this RailRoad to RailRoad travel." << endl;
			system("pause");
            system("cls");
		}
	}
	else
	{
		cout << "You can't RailRoad travel from this space." << endl;
		system("pause");
        system("cls");
	}
	return endTurn;
}

//---------------------------------------------------------------------------------------------------------------------

// display player names, bank totals, active player's location
void Game::displayGameInfo(Player& activePlayer)
{
	cout << "\n\tPlayers:" << endl;
	cout << "\t";
	for (auto& player : this->players)
	{
		//print all names and bank totals
		if (player.getGamePiece() == activePlayer.getGamePiece())
		{
			cout << "[" << player.getName() << ": $" << player.getBank() << "]" << "  "; //surround active player's name in square brackets
		}
		else
		{
			cout << player.getName() << ": $" << player.getBank() << "  ";
		}
	}

	//print game bank total
	cout << "\n\n\tBank Total: $" << this->banker.getBank();

	cout << "\n" << endl;

	//display visual of the active player's current space
	cout << "\tCurrent Space:" << endl;
	this->board.getSpace(activePlayer.getPosition()).display();
}

//---------------------------------------------------------------------------------------------------------------------

// check if there are more players on a space after the active player moves
void Game::checkForMorePlayers(Player& activePlayer)
{
	bool stillOccupied{ false }; // confusing name, can't think of a good way to name this
	// If any players are on the same space, this will show the next player's gamePiece once one of the players moves off
	for (int i{ 0 }; i < this->players.size(); i++)
	{
		if (players[i].getPosition() == activePlayer.getPosition() && // if a player in the players vector has the same position as the active player
			players[i].getGamePiece() != activePlayer.getGamePiece() && // don't check against the active player's gamePiece
			!stillOccupied)
		{
			stillOccupied = true; // set to true to stop if statement from running again
			this->board.getSpace(activePlayer.getPosition()).setSpaceString(players[i].getGamePiece()); //set the space to show the next player's gamePiece in the players array
		}
	}

	// if there are no other players on the space then set it back to a blank space
	if (!stillOccupied)
	{
		this->board.getSpace(activePlayer.getPosition()).resetSpaceString();
	}
}

//---------------------------------------------------------------------------------------------------------------------

void Game::changeActivePlayer()
{
	//increment playerCounter to get the next player in the players vector
	this->playerCounter++;

	if (this->playerCounter >= this->players.size()) //reset to 0 once it hits the end
	{
		this->playerCounter = 0;
	}
}

//---------------------------------------------------------------------------------------------------------------------

void Game::mortgageProperty(Player& activePlayer)
{
	string choice{ "" };
	cout << "\tWould you like to mortgage a property? (y/n): ";
	cin >> choice;

	if (choice == "y")
	{
		int pos{ -1 };
		while (pos < 0 || pos > this->board.getBoardSize())
		{
			cout << "\tEnter the property position number: ";
			cin >> pos;
		}
		BoardSpace& property = this->board.getSpace(pos);
		cout << "\t";
		if (property.getOwner() == activePlayer)
		{
			if (!property.isMortgaged())
			{
				int mortgageVal = property.getCost() / 2;
				cout << property.getName() << " has been mortgaged." << endl;
				property.setMortgaged(true);
				cout << activePlayer.getName() << " receives $" << mortgageVal << " from the bank." << endl;
				activePlayer.setBank(activePlayer.getBank() + mortgageVal);
				this->banker.setBank(this->banker.getBank() + mortgageVal);
			}
			else
			{
				cout << property.getName() << " is already mortgaged." << endl;
			}
		}
		else
		{
			cout << "You do not own this property." << endl;
		}
	}
}

//---------------------------------------------------------------------------------------------------------------------

void Game::unMortgageProperty(Player& activePlayer)
{
	string choice{ "" };
	cout << "\tWould you like to unmortgage a property? (y/n): ";
	cin >> choice;

	if (choice == "y")
	{
		int pos{ -1 };
		while (pos < 0 || pos >= this->board.getBoardSize())
		{
			cout << "\tEnter the property position number: ";
			cin >> pos;
		}
		BoardSpace& property = this->board.getSpace(pos);
		cout << "\t";
		if (property.getOwner() == activePlayer)
		{
			if (property.isMortgaged())
			{
				int unMortgageVal = property.getCost() / 2 + (property.getCost() / 2 * 0.1);
				cout << property.getName() << " has been unmortgaged." << endl;
				property.setMortgaged(false);
				cout << activePlayer.getName() << " pays the bank $" << unMortgageVal << endl;
				activePlayer.setBank(activePlayer.getBank() - unMortgageVal);
				this->banker.setBank(this->banker.getBank() + unMortgageVal);
			}
			else
			{
				cout << property.getName() << " is not mortgaged." << endl;
			}
		}
		else
		{
			cout << "You do not own this property." << endl;
		}
	}
}

//---------------------------------------------------------------------------------------------------------------------

bool Game::jailTurn(Player& activePlayer)
{
	bool endTurn{ false };

	this->board.getSpace(activePlayer.getPosition()).setSpaceString(activePlayer.getGamePiece());
	this->board.display();
	this->displayGameInfo(activePlayer);

	string choice{ "" };
	cout << "\n\tWhat would you like to do?" << endl;
	cout << "\t1) Roll 2) Trade 3) View Properties 4) Use Card 5) Pay Fine: ";
	cin >> choice;

	if (choice == "1")
	{
		endTurn = this->rollChoice(activePlayer);
		system("pause");
        system("cls");
	}
	else if (choice == "2")
	{

	}
	else if (choice == "3")
	{
		this->viewProperties(activePlayer);
	}
	else if (choice == "4")
	{
		if(activePlayer.doesHaveJailCard() == true)
        {
            activePlayer.setInJail(false);
            activePlayer.setHasJailCard(false);
            std::cout << activePlayer.getName() << " has used a get out of jail card! " << endl;
            system("pause");
            this->rollChoice(activePlayer);
            system("pause");
            system("cls");
        } else
        {
		    cout << "\t" << activePlayer.getName() << " doesn't have a get out of jail card." << endl;
		}
	}
	else if (choice == "5")
	{
		activePlayer.pay(this->banker, 50);
		cout << "\t" << activePlayer.getName() << " has paid a $50 fee to get out of jail." << endl;
		system("pause");
		activePlayer.setInJail(false);
		activePlayer.setJailCounter(0);
		this->rollChoice(activePlayer);
		system("pause");
        system("cls");
	}

	return endTurn;
}

//---------------------------------------------------------------------------------------------------------------------

bool Game::normalTurn(Player& activePlayer)
{
	string choice;
	int playerPos{ activePlayer.getPosition() };
	int playerBank{ activePlayer.getBank() };
	bool doubles{ false };
	bool endTurn{ false };

	this->board.getSpace(activePlayer.getPosition()).setSpaceString(activePlayer.getGamePiece());
	this->board.display();
	this->displayGameInfo(activePlayer);

	cout << "\n\tWhat would you like to do?" << endl;
	cout << "\t1) Roll 2) Trade 3) View Properties 4) RailRoad Travel: ";
	cin >> choice;

	if (choice == "1") // roll
	{
		endTurn = this->rollChoice(activePlayer);
		cout << endl;
		int pos = activePlayer.getPosition();// keep track of player's landing position

		this->board.getSpace(activePlayer.getPosition()).action(activePlayer);

		if (pos != activePlayer.getPosition())//if the space action moves the player
		{
			this->board.getSpace(pos).resetSpaceString();
			this->board.getSpace(activePlayer.getPosition()).setSpaceString(activePlayer.getGamePiece());
			this->board.getSpace(activePlayer.getPosition()).action(activePlayer);
		}
		system("pause");
        system("cls");
	}else if(choice == "2")
    {
	    int trader;
        cout<<"Who do you want to trade with? " << endl;
        int i{1};
	    for(auto& player : players)
        {
	     cout <<i << " " << player.getName()<< endl ;
	     ++i;
        }
        cin >> trader;
	   this->trade( activePlayer,players[trader-1]);

    }

	else if (choice == "3") // view properties
	{
		this->viewProperties(activePlayer);
	}
	else if (choice == "4")
	{
		this->railRoadTravel(activePlayer);
	}
	else if (choice == "10")
	{
		int pos{ -1 };
		cout << "\tEnter the position you want to go to: ";
		cin >> pos;
        system("cls");
		this->checkForMorePlayers(activePlayer);

		activePlayer.setPosition(pos);
		pos = activePlayer.getPosition();
		this->board.getSpace(activePlayer.getPosition()).setSpaceString(activePlayer.getGamePiece());
		this->board.setPlayerName(activePlayer.getName()).setDie(1, 0).setDie(2, 0).display();

		this->displayGameInfo(activePlayer);
		this->board.getSpace(activePlayer.getPosition()).action(activePlayer);
		if (pos != activePlayer.getPosition())//if the space action moves the player
		{
			this->board.getSpace(pos).resetSpaceString();
			this->board.getSpace(activePlayer.getPosition()).setSpaceString(activePlayer.getGamePiece());
			this->board.getSpace(activePlayer.getPosition()).action(activePlayer);
		}
		
		system("pause");
        system("cls");
	}

	if (activePlayer.isInJail() == true)
	{
		endTurn = true;
	}

	return endTurn;
}

//---------------------------------------------------------------------------------------------------------------------

void Game::checkUtilityOwners()
{
	board.getSpace(12).getOwner().setUtilityCount(0);
	board.getSpace(28).getOwner().setUtilityCount(0);

	if (board.getSpace(12).isOwned() == true)
	{
		this->board.getSpace(12).getOwner().setUtilityCount(board.getSpace(28).getOwner().getUtilityCount() + 1);
	}
	
	if (this->board.getSpace(28).isOwned() == true)
	{
		this->board.getSpace(28).getOwner().setUtilityCount(board.getSpace(28).getOwner().getUtilityCount() + 1);
	}
}

//---------------------------------------------------------------------------------------------------------------------

void Game::checkRailRoadOwners()
{
	board.getSpace(5).getOwner().setRailRoadCount(0);
	board.getSpace(15).getOwner().setRailRoadCount(0);
	board.getSpace(25).getOwner().setRailRoadCount(0);
	board.getSpace(35).getOwner().setRailRoadCount(0);

	if (board.getSpace(5).isOwned() == true)
	{
		this->board.getSpace(5).getOwner().setRailRoadCount(board.getSpace(5).getOwner().getRailRoadCount() + 1);
	}

	if (this->board.getSpace(15).isOwned() == true)
	{
		this->board.getSpace(15).getOwner().setRailRoadCount(board.getSpace(15).getOwner().getRailRoadCount() + 1);
	}

	if (board.getSpace(25).isOwned() == true)
	{
		this->board.getSpace(25).getOwner().setRailRoadCount(board.getSpace(25).getOwner().getRailRoadCount() + 1);
	}

	if (this->board.getSpace(35).isOwned() == true)
	{
		this->board.getSpace(35).getOwner().setRailRoadCount(board.getSpace(35).getOwner().getRailRoadCount() + 1);
	}
}

void Game::trade(Player &currentPlayer, Player &trader)
{
     std::vector<BoardSpace*> playerOne;//currplayer offer
     std::vector<BoardSpace*> playerTwo;//trader offer
    cout <<"It does something";
   //  this->board.displayOwner(activePlayer);
    //int selectedProperty{0};
     //cout << "What Property would you like to trade? "; cin >> selectedProperty;
    // while(!cin)


}
