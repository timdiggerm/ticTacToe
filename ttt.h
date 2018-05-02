#ifndef TTT_H
#define TTT_H

void printBoard(int** board, int playerTurn);
int checkWin(int** board);
int sumRow(int* row);
int sumCol(int** board, int column);
void boardSize();

#endif