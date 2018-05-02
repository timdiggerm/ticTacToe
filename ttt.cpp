#include <iostream>
#include "ttt.h"


char play1symbol;
char play2symbol;
int rowCount = 3;
int colCount = 3;
int diagTop;
int diagBot;
int turns = 0;

int main() {
	int playerTurn = 1;
	int row, col, result = 0;
	int p1Score = 0;
	int p2Score = 0;

	//
	//Prompts users to choose a symbol 
	//
	std::cout << "Player 1, select on the keyboard what symbol you would like." << std::endl;
	std::cin >> play1symbol;
	std::cout << "Player 2, select on the keyboard what symbol you would like." << std::endl;
	std::cin >> play2symbol;
	//
	//If users select the same symbol
	//
	if (play1symbol == play2symbol) { 
		while (play1symbol == play2symbol) {
			std::cout << "Users cannot select identical symbols." <<std:: endl;
			std::cout << "Player 1, select on the keyboard what symbol you would like" << std::endl;
			std::cin >> play1symbol;
			std::cout << "Player 2, select on the keyboard what symbol you would like" << std::endl;
			std::cin >> play2symbol;
		}
	}

	boardSize();
	int** board = new int*[rowCount]; //initializes a board to create dimensions with desired row & columns
	for(int i = 0; i < rowCount; ++i)
		board[i] = new int[colCount];

	while(p1Score < 3 && p2Score < 3){
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
			if(playerTurn == 1){
				playerTurn = 0;
			}else{
				playerTurn = 1; 
			}
		}
		printBoard(board, playerTurn);
		if(checkWin(board) == 1){
			p1Score++;
			std::cout << "Player 1 wins the round, and has " << p1Score << " points!\n" << std::endl;
		}else if(checkWin(board) == -2){
			std::cout << "It's a tie!\n" << std::endl;
		}else{
			p2Score++;
			std::cout << "Player 2 wins the round, and has " << p2Score << " points!\n" << std::endl;
		}
		board[row-1][col-1] = playerTurn == 1 ? 1 : -1;
		//Switch players
		if(playerTurn == 1) {
			playerTurn = 2;
		}  else {
			playerTurn = 1;
		}
		turns++;
		std::cout << "Turn #: " << turns << std::endl;
	
		printBoard(board, playerTurn);
	
		if(checkWin(board) == -2){
			std::cout << "It's a tie!" << std::endl;
		}else if(playerTurn == 2){
			std::cout << "Player 1 wins!" << std::endl;
		}else if(playerTurn == 1){
			std::cout << "Player 2 wins!" << std::endl;
		}

		for(int x = 0; x < 3; x++){
			for(int y = 0; y < 3; y++){
				board[x][y] = 0;
			}
		}
		playerTurn = 1;
	}
	if(p1Score == 3){
		std::cout << "Player 1 wins the game!" << std::endl;
	}else{
		std::cout << "Player 2 wins the game!" << std::endl;
	}
	return 0;
}

void boardSize(){
	std::cout << "How big would you like your board to be? Enter row and column:";
	int rowNew, columnNew;
	std::cin >> rowNew >> columnNew;
	rowCount = rowNew;
	colCount = columnNew;
}


void printBoard(int** board, int playerTurn) {

	if(playerTurn == 1) {
		std::cout << "Player 1's Turn" << std::endl;
	} else {
		std::cout << "Player 2's Turn" << std::endl;
	}

	std::cout << std::endl << "   ";
	//Column headers
	for(int i = 0; i < colCount; i++) {
		std::cout << " " << i+1 << "  ";
	}
	std::cout << std::endl;

	for(int i = 0; i < rowCount; i++) {
		std:: cout << " " << i+1 << " "; //Row headers
		for(int j = 0; j < colCount; j++) {
			//Board uses 0 for unused, 1 for X and -1 for O
			switch(board[i][j]) {
				case 0:
					std::cout << "   ";
					break;
				case 1:
					std::cout <<" " << play1symbol << " ";
					break;
				case -1:
					std::cout <<" " << play2symbol << " ";
					break;
			}
			if(j < colCount-1) {
				std::cout << "|"; //Lines between the columns
			}
		}
		std::cout << std::endl << "   ";
		if(i < rowCount-1) {
			//Print lines between rows
			for(int j = 0; j < colCount; j++) {
				std::cout << "---";
				if(j < colCount-1) {
					std::cout <<"-";
				}
			}
			std::cout << std::endl;
		}
	}

}

int checkWin(int** board) {
	int result = 0;
	//Check rows and cols for wins
	for(int i = 0; i < rowCount; i++) {
		int rowSum = sumRow(board[i]), colSum = sumCol(board, i);
		if(rowSum > rowCount-1 || colSum > colCount - 1) {
			result = 1;
		} else if(rowSum < 0-(rowCount-1) || colSum < 0-(colCount-1)) {
			result = -1;
		}
	}
	//Check diagonals for wins
	for(int i = board[0][0]; i < board[rowCount -2][colCount-1]; i++){
		diagTop = board[i][i];
	}
	
	for(int i = board[0][colCount-1]; i < board[rowCount-1][0]; i--){
		diagBot = board[i][i];
	}
			
	if(diagTop > rowCount-1 || diagBot > rowCount-1) {
		result = 1;
	} else if(diagTop < 0-(rowCount-1) || diagBot < 0-(rowCount-1)) {
		result = -1;
	}
	int counter = 0;
	for(int x = 0; x < rowCount; x++){
		for(int y = 0; y < colCount; y++){
			if(board[x][y] == 1 || board[x][y] == -1)
				counter++;
		}
	}

	if(counter == 9 && result == 0){
		result = -2;
	}
	
	return result;
}

int sumRow(int* row) {
	for (int i =0 ; i < rowCount; i ++){
			return row[i];
	}

}

int sumCol(int** board, int column) {
	for(int i =0 ; i < colCount; i++){
		return board[i][column];
	}
	
}