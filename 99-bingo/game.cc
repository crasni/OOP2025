#include <iostream>
#include <string>
#include <vector>

#include "player.h"
#include "game.h"

void Game::getGameInfo() {
    cin >> playerCount >> boardSize;
    for (int i = 0; i < playerCount; i++) {
        string curName;
        cin >> curName;
        Player curPlayer = Player(curName, boardSize);
        curPlayer.getInfo(boardSize);
        playerBase.push_back(curPlayer);
    }
}

void Game::play() {
    int curNumber;
    for (int i = 0; i < boardSize*boardSize; i++) {
        cin >> curNumber;
        for (int pID = 0; pID < playerCount; pID++) {
            playerBase[pID].chooseNumber(curNumber, boardSize);
        }
    }
}
