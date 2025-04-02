#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
using namespace std;

class Player
{
    private:
        string name;
        vector<vector<int>> numToPos;
        vector<int> row, col;
        int diag[2];
        bool checkRow();
        bool checkCol();
        bool checkDiag();
    public:
        Player(string s) : name(s) {};
        bool checkWin();
};

#endif
