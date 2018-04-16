#include <iostream>
#include <string>

void printBoard(int board[3][3], bool player1Turn);
void clearBoard(int board[3][3]);
int checkWin(int board[3][3], bool &cont);
int sumRow(int row[3]);
int sumCol(int board[3][3], int column);


int main() {
	bool player1Turn = true;
	int player1score, player2score = 0;
	int row, col, result = 0;
	int board[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
	bool loep = false;
	while(loep == false) {
		if(checkWin(board, loep) == 1){
			player1score++;
			clearBoard(board);
		}else if(checkWin(board, loep) == -1){
			player2score++;
			clearBoard(board);
		}
		
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
	}
	
	std::cout << std::endl << "Final Score: " << std::endl << "Player 1: " << player1score 
	<< std::endl << "Player 2: " << player2score << std::endl;
	
	return 0;
}


void printBoard(int board[3][3], bool player1Turn) {
	if(player1Turn) {
		std::cout << "Player 1's Turn";
	} else {
		std::cout << "Player 2's Turn";
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

int checkWin(int board[3][3], bool &cont) {
	int result = 0;
	char strang;
	
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
	if(result != 0){
		printBoard(board, false);
		std::cout << "Would you like to play again? (Y/N)" << std::endl;
		std::cin >> strang;
		if(strang=='y'){
			std::cout << "Resetting..." << std::endl;
		}else{
			cont = true;
		}
	}

	return result;
}

void clearBoard(int board[3][3]){
	for(int i=0; i<3; i++){
		for(int j=0; j<3; i++){
			board[i][j] = 0;
		}
	}
}

int sumRow(int row[3]) {
	return row[0] + row[1] + row[2];
}

int sumCol(int board[3][3], int column) {
	return board[0][column] + board[1][column] + board[2][column];
}
