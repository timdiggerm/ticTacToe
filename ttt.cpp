#include <iostream>

void printBoard(int board[3][3], int playerTurn);

int main() {
	int board[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
	
	int playerTurn = 1;
	
	printBoard(board, playerTurn);
	
	return 0;
}

void printBoard(int board[3][3], int playerTurn) {
	std::cout << std::endl << "Player " << playerTurn << "'s turn" << std::endl;
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
					std::cout << " X ";
					break;
				case -1:
					std::cout << " O ";
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
