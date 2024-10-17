#include <bits/stdc++.h>
using namespace std;

const int N = 3;
const int n_players = 2;
const char marks[n_players] = {'X', 'O'};
char grid[N][N];
char copy_grid[N][N];

//This function prints the grid of Tic-Tac-Toe Game as the game progresses
void print_grid() {
    cout << "Player 1: " << marks[0] << "  vs  Player 2: " << marks[1] << "\n";
    cout << "--";
    for (int i = 0; i < N; cout << "---", i++);
    cout << "--\n";
    for (int i = 0; i < N; i++) {
        cout << "|  ";
        for (int j = 0; j < N; j++)
            cout << grid[i][j] << "  ";
        cout << "|\n";
        cout << "--";
        for (int i = 0; i < N; cout << "---", i++);
        cout << "--\n";
    }
}

//This function checks if the rows has a win state or not
bool row(char grid[N][N]){
    //win moves are: [0,0][0,1][0,2] or [1,0][1,1][1,2] or [2,0][2,1][2,2]
	for(int r = 0; r < N; r++){
		for(int c = 0; c < N-1; c++){
			if(grid[r][c] == grid[r][c+1] &&
               grid[r][c] != '.'){
				if(c == N-2 )
					return true;
				continue;
			}else
				break;
	    }
	}
	return false;
}

//This function checks if the columns has a win state or not
bool column(char grid[N][N]){
    //win moves are: [0,0][1,0][2,0] or [0,1][1,1][2,1] or [0,2][1,2][2,2]
	for(int c = 0; c < N; c++){
		for(int r = 0; r < N-1; r++){
			if(grid[r][c] == grid[r+1][c] &&
               grid[r][c] != '.'){
                  if(r == N-2 )
                    return true;
				  continue;
			}else
			    break;
		}
	}
	return false;
}

//This function checks if the diagonals has a win state or not
bool diagonals(char grid[N][N]){
    //left diagonal
    //win moves are: [0,0][1,1][2,2]
	for(int i = 0 ; i < N-1 ; i++ ){
		if(grid[i][i] == grid[i+1][i+1] &&
           grid[i][i] != '.'){
			if(i == N - 2 )
				return true;
			continue;
		}else
			break;
	}

	//right diagonal
	//win move is: [0,2][1,1][2,0] --> row is increasing, column is decreasing
	for(int r = N-1, c=0; r > 0, c < N-1; r--, c++){
		if(grid[r][c]==grid[r-1][c+1] &&
           grid[r][c] != '.'){
			if(r == 1)
				return true;
			continue;
		}else
			break;
	}
	return false;
}

//This function checks if the game has a win state or not
bool check_win(){
	if(row(grid) ||
       column(grid) ||
       diagonals(grid)){
		return true;
	}
	return false;
}

//This function checks if the game has a tie state or not for the given mark
bool check_tie_player(char mark){
    //Create temporary grid (copy_grid) to fill the empty indices with the user mark.
	for(int i = 0; i<N; i++){
		for(int j = 0; j < N; j++){
			if(grid[i][j]=='.')
			    copy_grid[i][j] = mark;
			else
                copy_grid[i][j] = grid[i][j];
		}
 	}

	if(row(copy_grid) ||
       column(copy_grid) ||
       diagonals(copy_grid)){
		return false;
	}
	return true;
}

//This function checks if the game has a tie state or not
bool check_tie() {
    bool all_tie = true;
    for (int i = 0; i < n_players; i++)
        if (!check_tie_player(marks[i]))
            all_tie = false;
    return all_tie;
}

//This function checks if given cell is empty or not
bool check_empty(int i, int j) {
	bool check = grid[i][j] == '.';
	return check;
}

//This function checks if given position is valid or not
bool check_valid_position(int i, int j) {
	bool valid_position = 0 <= i < N && 0 <= j < N;
	return valid_position;

}

//This function sets the given mark to the given cell
void set_cell(int i, int j, char mark) {
	grid[i][j] = mark;
}

//This function clears the game structures
void grid_clear() {
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			grid[i][j] = '.';
		}
	}
}

//This function reads a valid position input
void read_input(int &i, int &j) {
	cout << "Enter the row index and column index: ";
	cin >> i >> j;
    while (!check_valid_position(i, j) || !check_empty(i, j)) {
		cout << "Enter a valid row index and a valid column index: ";
		cin >> i >> j;
	}
}

//MAIN FUNCTION
void play_game() {
    cout << "Tic-Tac-Toe Game!\n";
    cout << "Welcome...\n";
    cout << "============================\n";
    bool player = 0;
    while (true) {
        //Prints the grid
        print_grid();
        //Read an input position from the player
        cout << "Player " << marks[player] << " is playing now\n";
        int i, j;
		read_input(i, j);
        //Set the player mark in the input position
        set_cell(i, j, marks[player]);
        //Check if the grid has a win state
        if (check_win()) {
            //Prints the grid
            print_grid();
			//Announcement of the final statement
            cout << "Congrats, Player " << marks[player] << " is won!\n";
            break;
        }
        //Check if the grid has a tie state
        if (check_tie()) {
            //Prints the grid
            print_grid();
			//Announcement of the final statement
            cout << "Woah! That's a tie!\n";
            break;
        }
        //Player number changes after each turn
        player = 1 - player;
    }
}

int main() {
    while (true) {
    	grid_clear();
    	play_game();
    	char c;
    	cout << "Play Again [Y/N] ";
    	cin >> c;
    	if (c != 'y' && c != 'Y')
    		break;
    }
}
