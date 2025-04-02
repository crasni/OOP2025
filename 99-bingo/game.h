#ifndef GAME_H
#define GAME_H

#include <string>
#include <vector>
using namespace std;

#include "player.h"

#define MAXM 257
#define MAXN 10
#define MAXNAMELEN 64

class Game
{
    private:
        vector<Player> playerBase;
        int playerCount, boardSize;
        vector<string> winner;
        int winCondition;
    public:
        Game() : winCondition(0) {};
        void getGameInfo();
        void play();
        void printResult();
};

#endif
