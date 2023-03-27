#include "player.hpp"
#include "card.hpp"
#include <iostream>
using namespace ariel;
using namespace std;

Player::Player(string name)
{
    cout << "Player Constructor\n";
}

// Player::Player(Player &player)
// {
//     cout << "Player Copy Constructor\n";
// }

Player::Player()
{
    cout << "Player Defult Constructor\n";
}

// Player::~Player()
// {
//     cout << "Player Distructor\n";
// }

int Player::stacksize()
{
    return 0;
}

int Player::cardesTaken()
{
    return 0;
}

string Player::getName()
{
    return this->name;
}