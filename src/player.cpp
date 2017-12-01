class Player
{
    std::string name;
    int score;
public:
    Player();
    Player(std::string name);
    void setName(std::string name);
    std::string getName();
    int getScore();
    void addScore(int points);
    void resetScore();
};

Player::Player()
{
    name = "NA";
    score = 0;
}

Player::Player(std::string name)
{
    this->name = name;
    score = 0;
}

void Player::setName(std::string name)
{
    this->name = name;
}
std::string Player::getName()
{
    return this->name;
}
int Player::getScore()
{
    return this->score;
}
void Player::addScore(int point)
{
    this->score += point;
}
void Player::resetScore()
{
    this->score = 0;
}
