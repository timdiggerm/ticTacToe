#include <iostream>

void printBoard(int board[3][3]);

int main() {
	int board[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
	
	printBoard(board);
	
	return 0;
}

void printBoard(int board[3][3]) {
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
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
		}
		std::cout << std::endl;
	}
}