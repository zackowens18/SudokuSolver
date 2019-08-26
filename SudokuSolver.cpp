#include <iostream>
#include <ctime>
#include <cstdio>

class Sudoku {
	public:
		void change(int row, int col,int value);
		bool solve(int array[9][9]);
		void print();
		Sudoku();
		bool checkRow(int row,int col, int value);
		bool checkColumn(int row, int col,int value);
		bool checkSquare(int row, int col, int value);
		bool checkFilled();
		bool findSpot(int &row,int &col);
		int board[9][9] = {
					  {1, 0, 0, 0, 0, 0, 4, 2, 9},
					  {0, 0, 8, 6, 4, 1, 0, 0, 0},
					  {4, 0, 3, 5, 0, 0, 8, 0, 0},
					  {0, 0, 0, 2, 0, 0, 3, 0, 7},
					  {5, 0, 0, 3, 0, 9, 0, 0, 4},
					  {6, 0, 2, 0, 0, 5, 0, 0, 0},
					  {0, 0, 4, 0, 0, 8, 9, 0, 5},
					  {0, 0, 0, 7, 5, 4, 6, 0, 0},
					  {8, 2, 5, 0, 0, 0, 0, 0, 1},
		};
};
void Sudoku::change(int row, int col,int value) {
	board[row][col] = value;
}
void Sudoku::print() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			std::cout << board[i][j]<<" ";
		}
		std::cout << "\n";
	}

}
bool Sudoku::solve(int array[9][9]) {
	int row, col;
	if (findSpot(row,col)) {
		return true;
	}
	else {
		
		for (int num = 1; num <= 9; num++) {
			if (checkColumn(row, col, num) && checkRow(row, col, num) && checkSquare(row, col, num)) {
				board[row][col] = num;
				
				if (solve(board)) 
					return true;
				board[row][col] = 0;
			}
		
		}
		return false;
	}
}

Sudoku::Sudoku() {
	int board[9][9] = {
					  {3, 0, 6, 5, 0, 8, 4, 0, 0},
					  {5, 2, 0, 0, 0, 0, 0, 0, 0},
					  {0, 8, 7, 0, 0, 0, 0, 3, 1},
					  {0, 0, 3, 0, 1, 0, 0, 8, 0},
					  {9, 0, 0, 8, 6, 3, 0, 0, 5},
					  {0, 5, 0, 0, 9, 0, 6, 0, 0},
					  {1, 3, 0, 0, 0, 0, 2, 5, 0},
					  {0, 0, 0, 0, 0, 0, 0, 7, 4},
					  {0, 0, 5, 2, 0, 6, 3, 0, 0}
	};
}
bool Sudoku::checkColumn(int row, int col,int value) {
	
	for (int i = 0; i < 9; i++) {
		if (board[i][col] == value && i!=row) {
			
			return false;
			
		}
	}
	return true;
}
bool Sudoku::checkRow(int row, int col,int value) {
	for (int i = 0; i < 9; i++) {
		if (board[row][i] == value && i!=col) {
			//std::cout << "problem with row";
			return false;
			
		}
	}
	return true;
}
bool Sudoku::checkSquare(int row, int col, int value){
	int start_row = (row / 3) *3;
	int start_col = (col / 3) *3;
	int end_col = (start_col) + 3;
	int end_row = (start_row) + 3;
	for (int i = start_row; i < end_row; i++) {
		for (int j = start_col; j < end_col; j++) {
			if (board[i][j] == value && (i!=row && j!=col)) {
				return false;
			}
		}
	}
	return true;

}

bool Sudoku::checkFilled() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (board[i][j] == 0)
				return false;
		}
	}
	//std::cout << "worked";
	return true;
}
bool Sudoku::findSpot(int &row,int &col) {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (board[i][j] == 0) {
			row = i;
			col = j;
			return false;
			}
		}
	}
	return true;
}

int main() {
	Sudoku game;
	game.print();
	std::clock_t start = 1;
	double duration;
	if (game.solve(game.board)) {
		game.print();
	}
	duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;
	std::cout << "printf: " << duration << '\n';
	
	
	return 0;
}
