#include <iostream>
int rowCount = 3;
int colCount = 3;
int diagTop;
int diagBot;
void boardSize();
void printBoard(int** board, bool player1Turn);
int checkWin(int** board);
int sumRow(int* board);
int sumCol(int** board, int column);


int main() {
	using namespace std;
	bool player1Turn = true;
	
	int row, col, result = 0;
	boardSize();
	int** board = new int*[rowCount]; //initializes a board to create dimensions with desired row & columns
	for(int i = 0; i < rowCount; ++i)
		board[i] = new int[colCount];
	
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
	}
	printBoard(board, player1Turn);
	return 0;
}

void boardSize(){
	std::cout << "How big would you like your board to be? Enter row and column:";
	int rowNew, columnNew;
	std::cin >> rowNew >> columnNew;
	rowCount = rowNew;
	colCount = columnNew;
}

void printBoard(int** board, bool player1Turn) {
	if(player1Turn) {
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
					std::cout << " X ";
					break;
				case -1:
					std::cout << " O ";
					break;
			}
			if(j != colCount) {
				std::cout << "|"; //Lines between the columns
			}
		}
		std::cout << std::endl;
		if(i != rowCount) {
			//Print lines between rows
			std::cout << " -" << std::endl;
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

