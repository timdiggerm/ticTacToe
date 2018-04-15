#ifndef TTT_H
#define TTT_H

void printBoard(int board[3][3], int playerTurn);
int checkWin(int board[3][3]);
int sumRow(int row[3]);
int sumCol(int board[3][3], int column);

#endif