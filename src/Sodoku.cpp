#include <iostream>

/********************************************************************************************
 *This method will help the sodokuSolver method by checking to see there is an empty slot
 *in the sodoku board.
 *******************************************************************************************/
bool isMove(int board[9][9],int &row,int &col){
	for(row = 0; row < 9; row++){
		for(col = 0 ; col < 9; col++){
			if(board[row][col] == 0)
				return true;
		}
	}
	return false;
}

/********************************************************************************************
 *This method will help the sodokuSolver method see if their is a valid slot availabe
 *in the 3x3 square. 
 *******************************************************************************************/
bool foundInBox(int board[9][9], int newRow, int newCol, int val){
	for(int row = 0; row < 3; ++row){
		for(int col = 0; col < 3; ++col){
			if(board[row + newRow][col + newCol] == val)
				return false;
		}
	}
	return true;
}

/********************************************************************************************
 *This will check to see if the number passed in is in the given row or column. 
 *******************************************************************************************/
bool isValid(int board[9][9], int row, int col, int val){
	for(int i = 0; i < 9; i++){
		if(board[i][col] == val)
			return false;
	}
	
	for(int i = 0; i < 9; i++){
		if(board[row][i] == val)
			return false;
	}
	
	return foundInBox(board, row - row%3, col - col % 3, val);
}

/********************************************************************************************
 * This method will take in a sodoku board, and solve it using backtracking.
 *******************************************************************************************/
bool sodokuSolver( int board[9][9] ){
	int row, col;

	if(!isMove(board, row, col))
		return true;
		
	for (int i = 1; i <= 9; i++){
		if(board[row][col] == 0 && isValid(board, row, col, i)){
			board[row][col] = i;

			if(sodokuSolver(board))
				return true;
			board[row][col] = 0;
				}
			}
	return false;
}

/********************************************************************************************
 *This main method will just test the sodokuSover method by passing in
 *a sodoku Board. 
 *******************************************************************************************/
int main(){
	int board[9][9] = {{ 0, 3, 0, 0, 0, 0, 0, 2, 0 },
                   { 0, 9, 0, 0, 0, 0, 0, 8, 5 },
                   { 5, 0, 0, 0, 8, 0, 4, 0, 0 },
                   { 4, 0, 7, 2, 0, 6, 8, 9, 0 },
                   { 0, 1, 0, 8, 0, 9, 0, 4, 0 },
                   { 0, 8, 9, 5, 0, 1, 3, 0, 2 },
                   { 0, 0, 3, 0, 1, 0, 0, 0, 9 },
                   { 9, 4, 0, 0, 0, 0, 0, 1, 0 },
                   { 0, 7, 0, 0, 0, 0, 0, 3, 0 }
        };

	sodokuSolver(board);

	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			std::cout <<  board[i][j] << " ";
		}
		std::cout << std::endl;
	}
	return EXIT_SUCCESS;
}
