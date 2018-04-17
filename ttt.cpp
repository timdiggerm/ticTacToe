#include <iostream>
#include "ttt.h"
#include <string>
 

using namespace std;
void printBoard(int board[3][3], bool player1Turn);
int checkWin(int board[3][3]);
int sumRow(int row[3]);
int sumCol(int board[3][3], int column);
 
char player1Char;
char player2Char;
 
std::string name1;
std::string name2;

int main() {
	
 
	std::cout << "Player 1: Enter a symbol you want to use - ";
	std::cin >> player1Char;
	
	std::cout << "Player 2: Enter a symbol you want to use - ";
	std::cin >> player2Char;

	std::cout << "Player 1 Name: ";
	std::cin >> name1;
	std::cout << "Player 2 Name: ";
	std::cin >> name2;	
	
	
	int playerNum;

	int board[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
	int row, col, result = 0;
	int playerTurn = 1;
	
	while(checkWin(board) == 0) {
		printBoard(board, playerTurn);
		std::cout << "Enter a row and a column: ";
		std::cin >> row >> col;
		
		while(board[row-1][col-1] != 0) {
			std::cout <<"Enter a valid, empty row and column choice: ";
			std::cin >> row >> col;
		}
		
		board[row-1][col-1] = playerTurn == 1 ? 1 : -1;
		//Switch players
		if(playerTurn == 1) {
			playerTurn = 2;
		}  else {
			playerTurn = 1;
		}
	}
 
 
	printBoard(board, playerTurn);
	
	if (checkWin(board) == 1){
		std::cout << name1 << " Wins!";
	}else if (checkWin(board) == -1){
		std::cout << name2 << " Wins!";
	}else if (checkWin(board) == -2){
		std::cout << "It's a draw!";
	}
	
	return 0;
}

 
void printBoard(int board[3][3], int playerTurn) {

	if(playerTurn == 1) {
		std::cout << name1 << "'s Turn" << std::endl;
	} else {
		std::cout << name2 << "'s Turn" << std::endl;
	}
	
 
	std::cout << std::endl << "   ";
	//Column headers
	for(int i = 0; i < 3; i++) {
		std::cout << " " << i+1 << "  ";
	}
	std::cout << std::endl;
	for(int i = 0; i < 3; i++) {
		std:: cout << " " << i+1 << " "; //Row headers
		for(int j = 0; j < 3; j++) {
			//Board uses 0 for unused, 1 for X and -1 for O
			switch(board[i][j]) {
				case 0:
					std::cout << "   ";
					break;
				case 1:
					std::cout << " " << player1Char << " ";
					break;
				case -1:
					std::cout << " " << player2Char << " ";
					break;
			}
			if(j != 2) {
				std::cout << "|"; //Lines between the columns
			}
		}
		std::cout << std::endl;
		if(i != 2) {
			//Print lines between rows
			std::cout << "   ---+---+---" << std::endl;
		}
	}
}

int checkWin(int board[3][3]) {
	int result = 0;
	
	
	//Check rows and cols for wins
	for(int i = 0; i < 3; i++) {
		int rowSum = sumRow(board[i]), colSum = sumCol(board, i);
		if(rowSum > 2 || colSum > 2) {
			result = 1;
		} else if(rowSum < -2 || colSum < -2) {
			result = -1;
		} 
	}
	
	//Check diagonals for wins
	int diagTop = board[0][0] + board[1][1] + board[2][2],
		diagBot = board[2][0] + board[1][1] + board[0][2];
			
	if(diagTop > 2 || diagBot > 2) {
		result = 1;
	} else if(diagTop < -2 || diagBot < -2) {
		result = -1;
	}
	
	int count = 0;
	for(int x = 0; x < 3; x++){
		for(int y = 0; y < 3; y++){
			if(board[x][y] == 1 || board[x][y] == -1)
				count++;
		}
	}
	
	if(count == 9 && result == 0){
		result = -2;
	}

	return result;
}

int sumRow(int row[3]) {
	return row[0] + row[1] + row[2];
}

int sumCol(int board[3][3], int column) {
	return board[0][column] + board[1][column] + board[2][column];
}