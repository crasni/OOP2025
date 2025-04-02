#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "player.h"

bool Player::checkRow(const int boardSize) {
    for (auto n : row)
        if (n == boardSize) return true;
    return false;
}

bool Player::checkCol(const int boardSize) {
    for (auto n : col)
        if (n == boardSize) return true;
    return false;
}

bool Player::checkDiag(const int boardSize) {
    for (auto n : diag)
        if (n == boardSize) return true;
    return false;
}

bool Player::checkWin(const int boardSize){
    return checkRow(boardSize) || checkCol(boardSize) || checkDiag(boardSize);
}

void Player::getInfo(const int boardSize) {
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardSize; j++) {
            size_t number;
            cin >> number;
            numToPos[number - 1][0] = i;
            numToPos[number - 1][1] = j;   
        }
    }
    
}

void Player::chooseNumber(const int number, const int boardSize) {
    int r = numToPos[number - 1][0];
    int c = numToPos[number - 1][1];
    row[r]++;
    col[c]++;
    if (r == c) diag[0]++;
    if (r + c == boardSize) diag[1]++;
}

// debug use
void Player::printnumToPos() {
    cout << name << "\n";
    for (auto pos : numToPos) 
        cout << pos[0] << " " << pos[1] << "\n";;
}

void Player::printInfo() {
    for (auto rx: row) 
        cout << rx << " ";
    cout << "\n";
    for (auto cx: col) 
        cout << cx << " ";
    cout << "\n";
    for (auto dx: diag) 
        cout << dx << " ";
    cout << "\n";
}
