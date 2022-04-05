#include <bits/stdc++.h>
using namespace std;

const int SIZE = 3;
struct TicTacToe
{
  char **board;  // this is the game board
};

//prototype
void createBoard(TicTacToe&);
void deallocateBoard(TicTacToe&);
void printBoard(TicTacToe);
bool is_tie(TicTacToe);
void convertUserEntry(char, char, int&, int&);
char winningMove(TicTacToe, int, int);

//main function
int main() {
    TicTacToe game;                // declare an instance of the tic-tac-toe game board
    createBoard(game);
    char winner = 0;               // no winner initially
    char turn = 'X';               // 'X' goes first
    char charRowIn, charColumnIn;  // user's input (characters)
    int row, column;               // user's input converted to 2D array indices

    while(!winner && !is_tie(game)){
            printBoard(game);

      // Read Move
            cout << "Player " << turn << "'s move (input format: a1): ";
            cin >> charRowIn >> charColumnIn;
            convertUserEntry(charRowIn, charColumnIn, row, column); // convert char ('a','0') to int (0,0)
            if (game.board[row][column]==' '){            // Make move if square free
                game.board[row][column] = turn;
                if (turn == 'X') turn = 'O'; // set turn to other person
                else turn = 'X';

            winner = winningMove(game, row, column);  //  if this move wins the game, returns 'X' or 'O',
            }
            //  else zero if no winner yet)
            else
                cout<<"Square taken, try again!";         // disallow taking a previously filled cell
    } // if no winner yet and not a tie

  // Game over, declare winner
  printBoard(game);
  if (winner == 'X' || winner == 'O')
    cout << "*** Congratulations, the winner is " << winner << '.' << endl;
  else
    cout << "*** Game ends in a tie." << endl;

  cout << endl<< "Shutting down!" << endl << endl;
  // delete dynamically allocated memory
  deallocateBoard(game);

  return 0;
}

// Returns 'X' if (i,j) was a winning move for X
// Returns 'Y' if (i,j) was a winning move for Y
// Returns ASCII value 0 otherwise
char winningMove(TicTacToe gameIn, int i, int j){
    if (gameIn.board[i][0]==gameIn.board[i][1] &&
        gameIn.board[i][0]==gameIn.board[i][2]){ // row i all the same
            return gameIn.board[i][j]; // return the id of the player in the [i,j] cell
    }
    if (gameIn.board[0][j]==gameIn.board[1][j] &&
        gameIn.board[0][j]==gameIn.board[2][j]){  // column j all the same
                return gameIn.board[i][j]; // return the id of player in the [i,j] cell
    }

    if (gameIn.board[0][0] != ' ' && // make sure not all blanks
        gameIn.board[0][0] == gameIn.board[1][1] &&
        gameIn.board[0][0] == gameIn.board[2][2]){
            return gameIn.board[i][j]; // left diagonal all the same
    }

    if (gameIn.board[0][2] != ' ' && // make sure not all blanks
        gameIn.board[0][2] == gameIn.board[1][1] &&
        gameIn.board[0][2] == gameIn.board[2][0]){
            return gameIn.board[i][j]; // right diagonal all the same
    }
  return 0;
}

// Returns true if the game is a tie
bool is_tie(TicTacToe gameIn){
    bool full = true;                      // assume full until determined otherwise
    for(int i = 0; full && i < SIZE; i++)
    for(int j = 0; full && j < SIZE; j++)
        full = gameIn.board[i][j] != ' ';   // found a non-blank cell, so board is NOT full
    return full;
}

// Prints the board
void printBoard(TicTacToe gameIn) {
    cout << endl << "      |1|2|3|" << endl;     // print top reference
    for(int i = 0; i < SIZE; i++){
            cout << "     " << char(i + 'a') << '|';    // prints left reference
    for(int j = 0; j < SIZE; j++)
        cout << gameIn.board[i][j] << '|';  // prints current board cell contents
    cout << endl;
    }
}

// Converts moves like "b3" into corresponding array indexes (1,2)
void convertUserEntry(char charRowIn, char charColumnIn, int& row, int& column){
    row = toupper(charRowIn) - 'A';  // charRowIn uppercased, then converted to 0,1,2
    column = charColumnIn - '1';     // ColumnIn converted to 0,1,2
}

// Creates the board with all squares init to ' '
void createBoard(TicTacToe& gameIn){
    gameIn.board = new char*[SIZE];     // allocate dynamic memory for 2D board
    for(int i = 0; i < SIZE; i++)
        gameIn.board[i] = new char[SIZE];
    for(int j =0;j < SIZE; j++)         // initialize board with blanks
        for(int k = 0; k < SIZE; k++)
            gameIn.board[j][k] = ' ';
}

// Free up all memory for the board
void deallocateBoard(TicTacToe& gameIn)
{
  for(int i = 0; i < SIZE; i++)
    delete [] gameIn.board[i];     // deallocate the 2D array, cell by cell
  delete [] gameIn.board;          // delete the outer array
  gameIn.board = NULL;             // defensive programming (the board no longer exists)
} 
