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
        bool checkRow(const int boardSize);
        bool checkCol(const int boardSize);
        bool checkDiag(const int boardSize);
    public:
        Player(string s, const int boardSize) :
            name(s), numToPos((size_t)(boardSize*boardSize), vector<int>(2, 0)), 
            row((size_t)boardSize, 0), col((size_t)boardSize, 0), diag {0, 0} {}
        bool checkWin(const int boardSize);
        string getName() {return name;};
        void getInfo(const int boardSize);
        void chooseNumber(const int number, const int boardSize);

        //debug use
        void printnumToPos();
        void printInfo();
};

#endif
