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

void pauseScreen();

 int main()
 {
     system("CLS"); // clear the screen

     Board board;
     std::vector<Player> players;
     int totalPlayers = 0;
     bool gameover = false;
     char restart; //restart the game 'y' or 'n'

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
             if (name.length() >= 2)
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
             //resetting so the next player has a turn
             turnComplete = false;

             // player move loop
             while((turnComplete == false)&&(gameover==false))
             {
                 system("CLS");
                 board.draw();
                 std::cout <<"Score:"<<playerItter->getScore()<<" "<< playerItter -> getName() << ", what location would you like to reveal? : ";
                 std::cin >> revealInput;
                 //force quit
                 if(revealInput=="q" || revealInput=="x")
                 {
                     turnComplete=true;
                     gameover=true;
                     break;
                 }
                 //converts string position into usable integers
                 size_t pos = revealInput.find('x');
                 if (pos != 4294967295)  // did not error
                 {
                     std::stringstream( revealInput.substr(0, pos) ) >> row;
                     std::stringstream( revealInput.substr(pos+1, revealInput.length()-(pos+1)) ) >> column;
                 }

                 if ( board.flipCard(row-1, column-1) )
                 {
                     revealCount+=1;
                     system("CLS");
                     board.draw();
                 }
                 // if first card selected, we store it
                 if(revealCount == 1)
                 {
                     selectedCard = board.getCard(row-1, column-1);
                 }
                 // two cards have been revealed, time to compare and see if we need to stop the turn
                if( revealCount == 2)
                {
                    // Check cards are equal
                    if ((*selectedCard) == (*board.getCard(row-1, column-1)))
                    {
                        // Add point to players score
                        (*playerItter).addScore(1);
                        // player gets another go to find more cards
                        revealCount = 0;

                        // display output information, and wait for key to be pressed
                        std::cout << "Got A Match" << '\n';
                        std::cout <<playerItter->getName()<<" : "<< playerItter->getScore() << '\n';
                        pauseScreen();
                    }
                    else
                    {
                        // As cards were not a match hides them
                        selectedCard->setFaceUp(false);
                        selectedCard = board.getCard(row-1, column-1);
                        selectedCard->setFaceUp(false);

                        revealCount = 0;
                        turnComplete = true;

                        // display output information, and wait for key to be pressed
                        std::cout << "No Match found" << '\n';
                        pauseScreen();
                    }
                }

                system("CLS");
                if (board.getFaceDownCardCount()==0 && gameover==false)
                {
                    gameover=true;

                    std::cout << "\n\n\n\t\tGame Over " << '\n';
                    for (playerItter = players.begin(); playerItter != players.end(); ++playerItter)
                    {
                        std::cout << "\t\t"<< (*playerItter).getName() <<" : "<<(*playerItter).getScore()<<'\n';
                    }
                    // need to set the itter to the begining as we are using the same itter to loop through all the players in the game.
                    playerItter = players.begin();
                    std::cout << "\nPlay another (y/n)?"<<'\n';
                    std::cin >> restart;
                    if (restart=='y')
                    {
                        gameover=false;
                        board.resetBoard();
                    }
                }
             }
         }
     }
     return 0;
 }

void pauseScreen()
{
    std::cin.ignore();
    getchar();
}
