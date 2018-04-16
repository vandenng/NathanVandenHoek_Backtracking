#include <iostream>

bool isMove(int board[9][9]);

bool sodokuSolver( int board[9][9] ){
	if(!isMove(board))
		return true;
	
	for (int i = 1; i <= 9; i++){
		for(int row = 0; row < 9; row++){
			for(int col = 0; col < 9; col++){
				if(board[row][col] == 0){
					board[row][col] = i;
					if(sodokuSolver(board))
						return true;
					board[row][col] = 0;
				}
			}
		}
	}	
	return false;
}

bool isMove(int board[9][9]){
	for(int i = 0; i < 9; ++i){
		for( int j = 0 ; j < 9; ++j){
			if(board[i][j] == 0)
				return true;
		}
	}
	return false;
}
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
