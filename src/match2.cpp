/* simple game, implementing c++

    The point of this is to create a simple game, that allows the user to match hidden 'cards'

    Coding standard: GOOGLE standard
    https://google.github.io/styleguide/cppguide.html
 */

#include <iostream>
#include <vector>
#include <string>

#include "card.cpp"
#include "player.cpp"

char CARD_FACE_TYPE[] = {'J','K','Q','A'};
char CARD_BACK[] = {'x'};

 int main()
 {
     system("CLS"); // clear the screen

     std::vector<Player> players;
     int totalPlayers = 0;
     bool gameover = false;

     // Get Player amount
     // TODO: Add in integer check, to make sure an int is input
     std::cout << "How many players : ";
     std::cin >> totalPlayers;
     std::cout << '\n';

     // Get Player names
     std::string name;
     for(int i = 1; i<=totalPlayers;i++)
     {
         while(true)
         {
             std::cout << "Player "<< i << " Name : ";
             std::cin >> name;
             if (name.length() >= 3)
             {
                 Player newPlayer(name);
                 players.push_back(newPlayer);
                 break;
             }
             system("CLS");  // clear the screen
        }
     }

     for(int i = 0 ; i<totalPlayers; i++)
     {
         std::cout << players[i].getName() << '\n';
     }

     /*
     while (gameover == false)
     {

     }
     */

     return 0;
 }
