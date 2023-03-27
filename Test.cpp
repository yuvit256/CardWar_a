#include "sources/player.hpp"
#include "sources/game.hpp"
#include "sources/card.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "doctest.h"
using namespace std;
using namespace ariel;

TEST_CASE("TEST#1") // no 1 played so therefor the 2 players should have each 26 cards
{
    Player p1("Yuval");
    Player p2("Shimon");
    Game g(p1, p2);
    CHECK(p1.stacksize() == 26);
    CHECK(p2.stacksize() == 26);
}

TEST_CASE("TEST#2") // no 1 played so no need to cards to be taken
{
    Player p1("Yuval");
    Player p2("Shimon");
    Game g(p1, p2);
    CHECK(p1.cardesTaken() == 0);
    CHECK(p2.cardesTaken() == 0);
}

TEST_CASE("TEST#3") // check if is there actually a winner
{
    Player p1("Yuval");
    Player p2("Shimon");
    Game g(p1, p2);
    g.playAll();
    bool c1 = (p1.stacksize() == 0) || (p1.stacksize() == 52);
    CHECK(c1);
}

TEST_CASE("TEST#4") // checks if the amount of cards left. should be 21 but can be less if a draw was played
{
    Player p1("Yuval");
    Player p2("Shimon");
    Game g(p1, p2);
    for (int i = 0; i < 5; i++)
    {
        g.playTurn();
    }
    CHECK(p1.stacksize() <= 21);
}

TEST_CASE("TEST#5") // checks if the amount of cards left. should be 21 but can be less if a draw was played
{
    Player p1("Yuval");
    Player p2("Shimon");
    Game g(p1, p2);
    for (int i = 0; i < 5; i++)
    {
        g.playTurn();
    }
    CHECK(p2.stacksize() <= 21);
}

TEST_CASE("TEST#6") // check if is there actually a winner
{
    Player p1("Yuval");
    Player p2("Shimon");
    Game g(p1, p2);
    g.playAll();
    bool c1 = (p2.stacksize() == 0) || (p2.stacksize() == 52);
    CHECK(c1);
}

TEST_CASE("TEST#7") // check if the total amount of card is 52
{
    Player p1("Yuval");
    Player p2("Shimon");
    Game g(p1, p2);
    for (int i = 0; i < 12; i++)
    {
        g.playTurn();
    }
    CHECK(p1.stacksize() + p2.stacksize() == 52);
}

TEST_CASE("TEST#8") // 1 turn so therefor should be 1 player with more cards
{
    Player p1("Yuval");
    Player p2("Shimon");
    Game g(p1, p2);
    g.playTurn();
    bool c1 = ((p1.stacksize() > p2.stacksize()) || (p1.stacksize() < p2.stacksize()));
    CHECK(c1);
}

TEST_CASE("TEST#9") // no name
{
    Player p1("Yuval");
    Player p2("");
    CHECK_THROWS(Game{p1, p2});
}

TEST_CASE("TEST#10") // no name
{
    Player p1("");
    Player p2("Shimon");
    CHECK_THROWS(Game{p1, p2});
}

TEST_CASE("TEST#11") // Throws bc the hasnt even started so why there would be a winner
{
    Player p1("Yuval");
    Player p2("Shimon");
    Game game(p1, p2);
    CHECK_THROWS(game.printWiner());
}

TEST_CASE("TEST#12") // Throws bc same name
{
    Player p1("Yuval");
    Player p2("Yuval");
    CHECK_THROWS(Game{p1, p2});
}

TEST_CASE("TEST#13") // the game hasnt even started so no last turn
{
    Player p1("Yuval");
    Player p2("Shimon");
    Game g(p1, p2);
    CHECK_THROWS(g.printLastTurn());
}

TEST_CASE("TEST#14") // the game hasnt even started so no log
{
    Player p1("Yuval");
    Player p2("Shimon");
    Game g(p1, p2);
    CHECK_THROWS(g.printLog());
}

TEST_CASE("TEST#15") // the game hasnt even started so no stats
{
    Player p1("Yuval");
    Player p2("Shimon");
    Game g(p1, p2);
    CHECK_THROWS(g.printStats());
}

TEST_CASE("TEST#16") // we played one turn therefor there should be a last turn
{
    Player p1("Yuval");
    Player p2("Shimon");
    Game g(p1, p2);
    g.playTurn();
    CHECK_NOTHROW(g.printLastTurn());
}

TEST_CASE("TEST#17") // we finished the game so the function should work
{
    Player p1("Yuval");
    Player p2("Shimon");
    Game g(p1, p2);
    g.playAll();
    CHECK_NOTHROW(g.printLog());
}

TEST_CASE("TEST#18") // we finished the game so the function should work
{
    Player p1("Yuval");
    Player p2("Shimon");
    Game g(p1, p2);
    g.playAll();
    CHECK_NOTHROW(g.printStats());
}

TEST_CASE("TEST#19") // we finished the game so we cant take another turn
{
    Player p1("Yuval");
    Player p2("Shimon");
    Game g(p1, p2);
    g.playAll();
    CHECK_THROWS(g.playTurn());

}

TEST_CASE("TEST#20") // we finished the game so we cant finish another game
{
    Player p1("Yuval");
    Player p2("Shimon");
    Game g(p1, p2);
    g.playAll();
    CHECK_THROWS(g.playAll());
}