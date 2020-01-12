// Move Two players - done
// Buy properties and charge rent - done
// Jail and Tax Spaces - done
// Mortgaging - done
// Bankruptcy - done
// ----------------------------- 70
// Cards level1 - done - 5
// Cards level2 - done -5
// Multiplayer - done - 5
// Doubles - done - 5
// RailRoad Travel - done - 5
// Cheats - done/add more - 5
// ------------------------------ 95

#include <array>
#include "BoardSpace.h"
#include "Property.h"
#include <iostream>
#include "NonProperty.h"
#include "Board.h"
#include "Player.h"

#include "Game.h"
using namespace std;
int getNumPlayers(int,int );

int getInt(int min, int max);

int main()
{

    std::string introMessage = "                                                                                    \n"
                          "     ##### ##       ###      /                                 ###                  \n"
                          "  ######  /##   #    ###   #/                                   ###                 \n"
                          " /#   /  / ##  ###    ##   ##                                    ##                 \n"
                          "/    /  /  ##   #     ##   ##                                    ##                 \n"
                          "    /  /   /          ##   ##                                    ##                 \n"
                          "   ## ##  /   ###     ##   ## /###     /###     /###     /###    ##  ##   ####      \n"
                          "   ## ## /     ###    ##   ##/ ###  / / ###  / / ###  / / ###  / ##   ##    ###  /  \n"
                          "   ## ##/       ##    ##   ##   ###/ /   ###/ /   ###/ /   ###/  ##   ##     ###/   \n"
                          "   ## ## ###    ##    ##   ##    ## ##    ## ##    ## ##    ##   ##   ##      ##    \n"
                          "   ## ##   ###  ##    ##   ##    ## ##    ## ##    ## ##    ##   ##   ##      ##    \n"
                          "   #  ##     ## ##    ##   ##    ## ##    ## ##    ## ##    ##   ##   ##      ##    \n"
                          "      /      ## ##    ##   ##    ## ##    ## ##    ## ##    ##   ##   ##      ##    \n"
                          "  /##/     ###  ##    ##   ##    /# ##    ## ##    ## ##    ##   ##   ##      ##    \n"
                          " /  ########    ### / ### / ####/    ######  #######   ######    ### / #########    \n"
                          "/     ####       ##/   ##/   ###      ####   ######     ####      ##/    #### ###   \n"
                          "#                                            ##                                ###  \n"
                          " ##                                          ##                         #####   ### \n"
                          "                                             ##                       /#######  /#  \n"
                          "                                              ##                     /      ###/    ";
    std::string bilboHouse= R"(

                . .:.:.:.:. .:\     /:. .:.:.:.:. ,
            .-._  `..:.:. . .:.:`- -':.:. . .:.:.,'  _.-.
            .:.:.`-._`-._..-''_...---..._``-.._.-'_.-'.:.:.
          .:.:. . .:_.`' _..-''._________,``-.._ `.._:. . .:.:.
       .:.:. . . ,-'_.-''      ||_-(O)-_||      ``-._`-. . . .:.:.
      .:. . . .,'_.'           '---------'           `._`.. . . .:.
     :.:. . . ,','               _________               `.`. . . .:.:
     `.:.:. .,','            _.-''_________``-._            `._.     _.'
  -._  `._./ /            ,'_.-'' ,       ``-._`.          ,' '`:..'  _.-
 .:.:`-.._' /           ,','                   `.`.       /'  '  \\.-':.:.
 :.:. . ./ /          ,','               ,       `.`.    / '  '  '\\. .:.:
:.:. . ./ /          / /    ,                      \ \  :  '  '  ' \\. .:.:
.:. . ./ /          / /            ,          ,     \ \ :  '  '  ' '::. .:.
:. . .: :    o     / /                               \ ;'  '  '  ' ':: . .:
.:. . | |   /_\   : :     ,                      ,    : '  '  '  ' ' :: .:.
:. . .| |  ((<))  | |,          ,       ,             |\'__',-._.' ' ||. .:
.:.:. | |   `-'   | |---....____                      | ,---\/--/  ' ||:.:.
------| |         : :    ,.     ```--..._   ,         |''  '  '  ' ' ||----
_...--. |  ,       \ \             ,.    `-._     ,  /: '  '  '  ' ' ;;..._
:.:. .| | -O-       \ \    ,.                `._    / /:'  '  '  ' ':: .:.:
.:. . | |_(`__       \ \                        `. / / :'  '  '  ' ';;. .:.
:. . .<' (_)  `>      `.`.          ,.    ,.     ,','   \  '  '  ' ;;. . .:
.:. . |):-.--'(         `.`-._  ,.           _,-','      \ '  '  '//| . .:.
:. . .;)()(__)(___________`-._`-.._______..-'_.-'_________\'  '  //_:. . .:
.:.:,' \/\/--\/--------------------------------------------`._',;'`. `.:.:.
:.,' ,' ,'  ,'  /   /   /   ,-------------------.   \   \   \  `. `.`. `..:
,' ,'  '   /   /   /   /   //                   \\   \   \   \   \  ` `.SSt)";
    cout<<bilboHouse<<endl<<endl;
    cout << introMessage << '\n'<< endl;

    std::vector<Player> players;
    int numPlayers{0};
    while(numPlayers < 2 || numPlayers > 6)
    {
        numPlayers = getNumPlayers(2,6);
    }

    for(int i{0}; i < numPlayers; ++i)
    {
        string name{""};
        cout << "Enter your name:    "; cin >> name;
        Player p(name);
        players.push_back(p);
    }

	Game game{ players };
	cout << game.getWinner() << " wins!" << endl;
}

int getNumPlayers(int min, int max)
{
    int numPeople;
    std::cout << "How many will be embarking on an adventure today? "; cin >> numPeople;
    while(!cin)
    {
        if (numPeople< min && numPeople > max)
        {
            cin.clear();
            cin.ignore(5000000, '\n');
        }
    }
    return numPeople;
}
