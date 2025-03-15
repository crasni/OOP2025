#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXM 257
#define MAXN 10
#define MAXNAMELEN 64

typedef struct player {
    char name[MAXNAMELEN];
    int numToPos[MAXM*MAXM][2];
    int row[MAXM];
    int col[MAXM];
    int diag[2];
} Player;

typedef struct game {
    Player players[MAXN];
    int playerCount;
    int boardSize;
    int winner[MAXN];
    int winnerCount;
    int winCondition;
} Game;

void initGame(Game *game) {
    game->winnerCount = 0;
    for (int i = 0; i < MAXN; i++) {
        game->players[i].diag[0] = 0;
        game->players[i].diag[1] = 0;
        for (int j = 0; j < MAXM; j++) {
            game->players[i].row[j] = 0;
            game->players[i].col[j] = 0;
        }
    }
}

void getPlayerInfo(Game *game) {
    int n, m;
    scanf("%d%d", &n, &m);
    game->playerCount = n;
    game->boardSize = m;
    for (int i = 0; i < n; i++) {
        scanf("%s", game->players[i].name);
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < m; k++) {
                int tmp; 
                scanf("%d", &tmp);
                game->players[i].numToPos[tmp][0] = j;
                game->players[i].numToPos[tmp][1] = k;
            }            
        }
    }
}

void printWinner(Game *game) {
    printf("%d ", game->winCondition);
    for (int i = 0; i < game->winnerCount - 1; i++) {
        printf("%s ", game->players[game->winner[i]].name);
    }
    printf("%s\n", game->players[game->winner[game->winnerCount-1]].name);
}

void gamePlay(Game *game) {
    for (int _ = 0; _ < game->boardSize * game->boardSize; _++) {
        int tmp;
        scanf("%d", &tmp);

        for (int i = 0; i < game->playerCount; i++) {
            int x = game->players[i].numToPos[tmp][0];
            int y = game->players[i].numToPos[tmp][1];
            game->players[i].row[x]++;
            game->players[i].col[y]++;
            if (x == y) game->players[i].diag[0]++;
            if (x + y == game->boardSize - 1) game->players[i].diag[1]++;
            if (game->players[i].row[x] == game->boardSize ||
                    game->players[i].col[y] == game->boardSize ||
                    game->players[i].diag[0] == game->boardSize ||
                    game->players[i].diag[1] == game->boardSize) {
                game->winner[game->winnerCount] = i;
                game->winnerCount++;
            }
        }
        if (game->winnerCount != 0) {
            game->winCondition = tmp;
            break;
        }
    }
}
 
int main(void) {
    Game *game = (Game *)malloc(sizeof(Game));

    initGame(game);
    getPlayerInfo(game);
    gamePlay(game);
    printWinner(game);

    return 0;
}