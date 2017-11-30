
class Card
{
    bool faceUp;
    int cardID;
    char cardFace;
    char cardBack;
public:
    Card();
    Card(int id);
    void setCardId(int id);
    int getCardId();
    bool isFaceUp();
    void setFaceUp(bool vis);
    std::string representation();
};

// constructors
Card::Card()
{
    cardID = -1;    // no card id specified
    faceUp = false;
    cardFace = 'F';
    cardBack = 'B';
}

// constructor and initialises the cards ID
Card::Card(int id)
{
    this->cardID = id;
    faceUp = false;
    cardFace = 'F';
    cardBack = 'B';
}

void Card::setCardId(int id)
{
    this->cardID = id;
}

int Card::getCardId()
{
    return this->cardID;
}

// is the card visible
bool Card::isFaceUp()
{
    return this->faceUp;
}

void Card::setFaceUp(bool vis)
{
    this->faceUp = vis;
}

std::string Card::representation()
{
    std::string repr="[";
    
    // card doesn't exist in play
    if (cardID == -1)
    {
        return "   ";
    }

    // checks if the card is face up or face down.
    if (faceUp)
    {
        repr += cardFace;
    }
    else
    {
        repr += cardBack;
    }
    repr.append("]");
    return repr;
}
