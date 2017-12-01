#include <algorithm>
#include <vector>
#include <random>
#include <chrono>

class Board
{
    int columns;
    int rows;
    int cardPairs;
    int emptyCards;
    // 2D vector
    std::vector<std::vector<Card>> cards;

public:
    Board();
    Board(int rows, int columns);
    bool flipCard(int row, int column);
    void setCardVisibility(int row, int column, bool vis);
    bool getCardVisibility(int row, int column);
    void setRows(int rows);
    void setColumns(int column);
    void resetBoard();
    void initCards();
    void clearCards();
    void draw();
    Card* getCard(int row, int column);
};
Board::Board()
{
    this->columns = 0;
    this->rows = 0;
    this->cardPairs = 0;
    this->emptyCards = 0;
}
//Construcs a new board, and sets the rows and columns
Board::Board(int rows, int columns)
{
    this->columns = columns;
    this->rows = rows;
    this->cardPairs = 0;
    this->emptyCards = 0;
}

Card* Board::getCard(int row, int column)
{
    return &cards[column][row];
}

/*
try to flip a card on the board, if it fails to flip the card as it is already flipped then returns false.
    return:
        true: if card if flipped
        false: if card is already facing up
*/
bool Board::flipCard(int row, int column)
{
    if(Board::getCardVisibility(row,column))
    {
        return false;
    }

    Board::setCardVisibility(row, column, true);
    return true;
}

// set a card at a specific location on the board to be visible or hidden
void Board::setCardVisibility(int row, int column, bool vis)
{
    this->cards[row][column].setFaceUp(vis);
}

bool Board::getCardVisibility(int row, int column)
{
    return cards[row][column].isFaceUp();
}
void Board::setRows(int rows)
{
    this->rows = rows;
}
void Board::setColumns(int columns)
{
    this->columns = columns;
}
// Flips over all the cards
void Board::resetBoard()
{
    std::vector<Card>::iterator itterColumn;
    std::vector<std::vector<Card>>::iterator itterRow;
    //loop through all rows
    for (itterRow = cards.begin(); itterRow != cards.end(); ++itterRow)
    {
        // loop through all columns
        for (itterColumn = itterRow->begin(); itterColumn != itterRow->end(); ++itterColumn)
        {
            // sets the face of the card to be down
            itterColumn -> setFaceUp(false);
        }
    }
}
// initialises the cards in each for the board
void Board::initCards()
{
    // amount of spaces the will have no cards
    emptyCards = (columns * rows)%2;
    cardPairs = ((columns * rows) - emptyCards)/2;

    // initialise vector size
    cards.resize(rows);
    for (int i = 0 ; i < rows; i++)
    {
        cards[i].resize(columns);
    }

    // create a row of new cards, easier to work with
    std::vector<Card> newCards;
    for (int i=0; i<cardPairs; i++)
    {
        int ranID = rand()%4;
        Card newCard_1(ranID);
        Card newCard_2(ranID);
        newCards.push_back(newCard_1);
        newCards.push_back(newCard_2);
    }
    if (emptyCards==1)
    {
        Card emptyCard;
        newCards.push_back(emptyCard);
    }

    // randomize position
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    shuffle (newCards.begin(), newCards.end(), std::default_random_engine(seed));

    // initialise cardPairs
    for(int i =0; i < cards.size(); i++)
    {
        for(int j =0; j < cards[i].size(); j++)
        {
            int cardIndex = (i*cards[i].size())+j;
            cards[i][j] = newCards[cardIndex];
        }
    }
}

// removes all initCard
void Board::clearCards()
{
    cards.clear();
}

void Board::draw()
{
    std::cout << "\n===============================" <<'\n';
    // column headings
    for(int j =0; j < cards[0].size(); j++)
    {
        std::cout <<" \t "<< j+1;
    }
    std::cout << '\n';

    for(int i =0; i < cards.size(); i++)
    {
        // row headings
        std::cout <<" "<< i+1;
        for(int j =0; j < cards[i].size(); j++)
        {
            std::cout <<'\t'<< cards[i][j].representation();
        }
        std::cout << '\n';
    }
    std::cout << "\n===============================" <<'\n';
}
