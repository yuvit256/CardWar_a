#include <iostream>
#include "game.hpp"
using namespace ariel;
using namespace std;

Game::Game(Player player1, Player player2)
{
    cout << "Game Constructor\n";
}

// Game::Game(Game &game)
// {
//     cout << "Game Copy Constructor\n";
// }

Game::Game()
{
    cout << "Game Defult Constructor\n";
}

// Game::~Game()
// {
//     cout << "Game Distructor\n";
// }

void Game::playTurn()
{
}

void Game::printLastTurn()
{
}

void Game::playAll()
{
}

void Game::printWiner()
{
}

void Game::printLog()
{
}

void Game::printStats()
{
}
