#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <stack>
#include "card.hpp"
using namespace std;

namespace ariel
{
    class Player
    {
    public:
        Player(string name);

        // Player(Player &player);

        Player();

        // ~Player();

        int stacksize();

        int cardesTaken();

        string getName();

    private:
        string name;

        stack<Card> cardsDeck;

        stack<Card> usedCards;
    };
};

#endif