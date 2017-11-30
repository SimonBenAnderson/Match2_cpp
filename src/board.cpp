
#include <vector>

class Board
{
    int columns;
    int rows;
    int cardPairs;
    int emptyCards;
    // 2D vector
    std::vector< std::vector<Card>> cards;

public:
    Board(int rows, int columns);
    void setCardVisibility(int row, int column, bool vis);
    bool getCardVisibility(int row, int column);
    void setRows(int rows);
    void setColumns(int column);
    void resetBoard();
    void initCards();
    void clearCards();
};

//Construcs a new board, and sets the rows and columns
Board::Board(int rows, int columns)
{
    this->columns = columns;
    this->rows = rows;
}

// set a card at a specific location on the board to be visible or hidden
void Board::setCardVisibility(int row, int column, bool vis)
{
    this->cards[row][column] = vis;
}

bool Board::getCardVisibility(int row, int column)
{
    return cards[row][column];
}
void setRows(int rows)
{
    this->rows = rows;
}
void setColumns(int columns)
{
    this->columns = columns;
}
// Flips over all the cards
void resetBoard()
{
    vector<Card>::iterator itterColumn;
    vector<Card>::iterator itterRow;
    //loop through all rows
    for (itterRow cards.begin(); itterRow != cards.end(); ++itterRow)
    {
        // loop through all columns
        for (itterColumn *itterRow.begin(); itterColumn != *itterRow.end(); ++itterColumn)
        {
            // sets the face of the card to be down
            *itterColumn -> setFaceUp(false);
        }
    }
}
// initialises the cards in each for the board
void initCards()
{
    // amount of spaces the will have no cards
    emptyCards = (columns * rows)%2;
    cardPairs = ((columns * rows) - emptyCards)/2;

    // initialise vector size
    cards.resize(rows);
    for (int i = 0 ; i < rows; i++)
    {
        cards[i].resize(columns;)
    }

}

// removes all initCard
void clearCards()
{
    cards.clear();
}
