
#include <stdio.h>

#define BOARD_SIZE 8

char board[BOARD_SIZE][BOARD_SIZE];

void initializeBoard() {

    // 盤面を初期化

    for (int i = 0; i < BOARD_SIZE; i++) {

        for (int j = 0; j < BOARD_SIZE; j++) {

            board[i][j] = ' ';

        }

    }

    // 初期配置

    board[3][3] = 'O';

    board[4][4] = 'O';

    board[3][4] = 'X';

    board[4][3] = 'X';

}

void printBoard() {

    // 盤面を表示

    printf("  0 1 2 3 4 5 6 7\n");

    for (int i = 0; i < BOARD_SIZE; i++) {

        printf("%d ", i);

        for (int j = 0; j < BOARD_SIZE; j++) {

            printf("%c|", board[i][j]);

        }

        printf("\n");

    }

}

int main() {

    initializeBoard();

    printBoard();

    return 0;

}