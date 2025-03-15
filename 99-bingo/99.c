#include <stdio.h>
#include <stdbool.h>

#define MAXM 256
#define MAXN 10
#define MAXNAMELEN 64

typedef struct player {
    char name[MAXNAMELEN];
    int numToPos[MAXM][2];
    int row[MAXM];
    int col[MAXM];
    int diag[2];
} Player;

typedef struct game {
    Player players[MAXN];
} Game;
 
int main(void) {
    int n, m;
    scanf("%d%d", &n, &m);
    char names[n][100];
    int b[n][m*m+2][2]; // name: number: position
    int win[n][2 * m + 2]; // rows, cols, main diagonal, sub diagonal
    for (int i = 0; i < n + 1; i++) {
        for (int j = 0; j < 2*m+2; j++) {
            win[i][j] = 0;
        }
    }
 
    for (int i = 0; i < n; i++) {
        scanf("%s", names[i]);
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < m; k++) {
                int tmp; 
                scanf("%d", &tmp);
                b[i][tmp][0] = j;
                b[i][tmp][1] = k;
            }            
        }
    }
 
    int winner[n+1];
    for (int i = 0; i < n + 1; i++)  winner[i] = -1;
 
    int wc = 0;
    int wincondition = -1;
 
    for (int _ = 0; _ < m * m; _++) {
        int tmp;
        scanf("%d", &tmp);
 
        for (int i = 0; i < n; i++) {
 
            int x = b[i][tmp][0], y = b[i][tmp][1];
            win[i][x]++;
            win[i][m+y]++;
            if (x == y) win[i][2*m]++;
            if (x + y == m - 1) win[i][2*m+1]++;
            if (win[i][x] == m || win[i][m+y] == m || win[i][2*m] == m || win[i][2*m+1] == m) {
                winner[wc] = i;
                wc++;
                wincondition = tmp;
            }
 
        }
 
        if (wincondition != -1) break;
 
    }
 
    printf("%d ", wincondition);
    for (int i = 0; i < m; i++) {
        if (winner[i+1] == -1) {
            printf("%s\n", names[winner[i]]);
            break;
        }
        printf("%s ", names[winner[i]]);
    }
 
    return 0;
}