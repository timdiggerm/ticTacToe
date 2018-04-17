#include <iostream>
void printBoard(int board[3][3], bool player1Turn);
int checkWin(int board[3][3]);
int sumRow(int row[3]);
int sumCol(int board[3][3], int column);
int turns = 0;
char symbol1, symbol2;
int main() {
	bool player1Turn = true;
	int board[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
	int row, col, result = 0;
	std::cout << "Player 1, choose your marker: ";
	std::cin >> symbol1;
	std::cout << "Player 2, choose your marker: ";
	std::cin >> symbol2;
	while(checkWin(board) == 0) {
		printBoard(board, player1Turn);
		std::cout << "Enter a row and a column: ";
		std::cin >> row >> col;
		while(board[row-1][col-1] != 0) {
			std::cout <<"Enter a valid, empty row and column choice: ";
			std::cin >> row >> col;
		}
		board[row-1][col-1] = player1Turn ? 1 : -1;
		//Switch players
		player1Turn = !player1Turn;
		turns++;
		std::cout << "Turn #: " << turns << std::endl;
	}
	printBoard(board, player1Turn);
	if(checkWin(board) == -2){
		std::cout << "It's a tie!" << std::endl;
	}else if(!player1Turn){
		std::cout << "Player 1 wins!" << std::endl;
	}else if(player1Turn){
		std::cout << "Player 2 wins!" << std::endl;
	}
	return 0;
}
void printBoard(int board[3][3], bool player1Turn) {
	std::cout << std::endl << "   ";
	for(int i = 0; i < 3; i++) { //Column headers
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
					std::cout << " " << symbol1 << " ";
					break;
				case -1:
					std::cout << " " << symbol2 << " ";
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
	if(player1Turn) {
		std::cout << "Player 1's Turn" << std::endl;
	} else {
		std::cout << "Player 2's Turn" << std::endl;
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
	int counter = 0;
	for(int x = 0; x < 3; x++){
		for(int y = 0; y < 3; y++){
			if(board[x][y] == 1 || board[x][y] == -1)
				counter++;
		}
	}
	if(counter == 9 && (result != 1 || result != -1)){
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