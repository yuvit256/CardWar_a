#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

namespace ariel
{
    enum shape
    {
        Spades,
        Hearts,
        Diamonds,
        Clubs
    };
    class Card
    {
    public:
        Card(int val, string shape);

        // Card(Card &card);

        // Card();

        // ~Card();

    private:
        int val;

        shape shape;
    };
};

#endif