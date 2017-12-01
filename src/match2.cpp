/* simple game, implementing c++

    The point of this is to create a simple game, that allows the user to match hidden 'cards'

    Coding standard: GOOGLE standard
    https://google.github.io/styleguide/cppguide.html
 */

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

#include "card.cpp"
#include "player.cpp"
#include "board.cpp"

 int main()
 {
     system("CLS"); // clear the screen

     Board board;
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
        }
     }
     system("CLS");  // clear the screen

     // Ask for board size and layout
     std::string boardSize;
     int row=0;
     int column=0;
     std::cout << "What size board do you wish to play on (rows x column)? \n Smallest size is 3x3 \n Size : ";
     std::cin >> boardSize;
     //TODO: Check board size is correct size, and not smaller then 3

     size_t pos = boardSize.find('x');
     if (pos != 4294967295)  // did not error
     {
         // convert string to int
        std::stringstream( boardSize.substr(0, pos) ) >> row;
        std::stringstream( boardSize.substr(pos+1, boardSize.length()) ) >> column;

        board.setRows(row);
        board.setColumns(column);
        system("CLS");  // clear the screen
     }

     board.initCards();
     board.draw();

     // TODO: Game loop, which asks for input from the player
     // TODO: Game handles logic
     bool turnComplete = false; // stores when the players turn is complete.
     int revealCount = 0;   // counts how many cards the player has revealed in there go, 1s card or second card
     std::string revealInput;   // the input of the card location you want to show.
     std::vector<Player>::iterator playerItter;
     Card *selectedCard;
     // master game loop
     while (gameover == false)
     {
         // player turn loop
         for (playerItter = players.begin(); playerItter != players.end(); ++playerItter)
         {
             // player move loop
             while(turnComplete ==false)
             {
                 std::cout << playerItter -> getName() << ", what location would you like to reveal? : ";
                 std::cin >> revealInput;
                 size_t pos = boardSize.find('x');
                 if (pos != 4294967295)  // did not error
                 {
                     std::stringstream( revealInput.substr(0, pos) ) >> row;
                     std::stringstream( revealInput.substr(pos+1, revealInput.length()) ) >> column;
                 }
                 if ( board.flipCard(row-1, column-1) )
                 {
                     revealCount+=1;
                     board.draw();
                 }
                 // if first card selected, we store it
                 if(revealCount == 1)
                 {
                     selectedCard = board.getCard(row-1, column-1);
                 }
                 // two cards have been revealed, time to stop the turn
                if( revealCount == 2)
                {
                    // Check cards are equal
                    if (selectedCard == board.getCard(row-1, column-1))
                    {
                        // Add point to players score
                        (*playerItter).addScore(1);
                        // player gets another go to find more cards
                        revealCount = 0;
                    }
                    else
                    {
                        revealCount = 0;
                        turnComplete = true;
                    }
                }
             }
         }
         gameover=true;
     }
     return 0;
 }
