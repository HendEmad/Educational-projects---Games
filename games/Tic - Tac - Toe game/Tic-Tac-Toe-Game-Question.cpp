#include <bits/stdc++.h>
using namespace std;

const int N = 3;
const int n_players = 2;
const char marks[n_players] = {'X', 'O'};
char grid[N][N];

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
//This function checks if the game has a win state or not
bool check_win(char mark) {
    /*
    winning conditions:
    //row
    for i 0 --> N-1
    (grid[i][0] == grid[i][1] && grid[i][0] == grid[i][2])

    //column
    for i 0 --> N-1
    (grid[0][i] == grid[1][i] && grid[0][i] == grid[2][i])

    // diagonals
    (grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2])--> left
    (grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0])--> right
    */

    int count_row = 0, count_column = 0, count_diagonall = 0,
        count_diagonalr = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            //column
            if(grid[i][j] == mark){
                count_column += 1;
                if(count_column == N) return true;
            }

            //row
            if(grid[j][i] == mark){
                count_row += 1;
                if(count_row == N) return true;
            }

            //diagonals
            /*if((grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2])|| (grid[0][2] = grid[2][0] &&grid[0][2] == grid[1][1]))
                return true;*/
            if(i == j && grid[i][j] == mark)
            if(grid[j][i] == mark){
                count_diagonall += 1;
                if(count_diagonall == N) return true;
            }

            /*if(i == j){
                count_diagonall += 1;
                if(count_diagonall == N) return true;
            }*/

            //diagonal_right
            if(grid[N-1][0] == mark && grid[0][N-1] == mark && grid[N/2][N/2] == mark){
                if(count_diagonalr == N) return true;
            }
        }
    }
    return false;
}

//This function checks if the game has a tie state or not for the given mark
bool check_tie_player(char mark) {
    int count_ = 0, count_column = 0, count_row = 0,
        count_diagonall = 0, count_diagonalr = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j = N; j++){
            //for column
            if(grid[i][j] == mark || grid[i][j] == '_'){
                count_column += 1;
                if(count_column == N) return false;
            }
            //for row
            if(grid[j][i] == mark || grid[i][j] == '_'){
                count_row += 1;
                if(count_row == N) return false;
            }

            //for diagonal_left
            /*if(((grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2])|| (grid[0][2] = grid[2][0] &&grid[0][2] == grid[1][1])) || grid[i][j] = '_')
                return false;*/
            if(i == j && grid[j][i] == mark || grid[i][j] == '_'){
                count_diagonall += 1;
                if(count_diagonall == N) return false;
            }

            // diagonal_left
            /*if(i == j){
                count_diagonall += 1;
                if(count_diagonall == N) return false;
            }*/
            if (((grid[i][j] ==mark || grid[i][j] == '_') && (grid[j][i])==mark || grid[j][i] == '_') && (grid[N/2][N/2]==mark || grid[N/2][N/2] == '_')){
                    count_diagonalr+=1;
                    if (count_diagonalr ==3) return false;
            }
        }
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
    bool empty_cell = grid[i][j] == '_';
    return empty_cell;
}
//This function checks if given position is valid or not
bool check_valid_position(int i, int j) {
    /*if(0 <= i <= N && 0 <= j <= N)
        return true;
    else
        return false;*/
    bool valid_position = 0 <= i <= N && 0 <= j <= N;
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
            grid[i][j] = '_';
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
        if (check_win(marks[player])) {
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
