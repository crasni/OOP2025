#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "player.h"

bool Player::checkRow(int boardSize) {
    for (auto n : row)
        if (n == boardSize) return true;
    return false;
}

bool Player::checkCol(int boardSize) {
    for (auto n : col)
        if (n == boardSize) return true;
    return false;
}

bool Player::checkDiag(int boardSize) {
    for (auto n : diag)
        if (n == boardSize) return true;
    return false;
}

bool Player::checkWin(int boardSize) {
    return checkRow(boardSize) || checkCol(boardSize) || checkDiag(boardSize);
}

void Player::getInfo(int boardSize) {
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardSize; j++) {
            size_t number;
            cin >> number;
            numToPos[number - 1][0] = i;
            numToPos[number - 1][1] = j;   
        }
    }
    
}

// debug use
void Player::printnumToPos() {
    for (auto pos : numToPos) 
        cout << pos[0] << " " << pos[1] << "\n";
}
