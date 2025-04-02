#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "player.h"
#include "game.h"

#define MAXM 257
#define MAXN 10
#define MAXNAMELEN 64

int main(void) {
    Game game;

    game.getGameInfo();
    game.play();
    game.printResult();
    
    return 0;
}
