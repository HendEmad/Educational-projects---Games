 #include<bits/stdc++.h>
# define N 3
using namespace std;

class TicTacToe{
private:
    char grid[N][N];

public:
    //this function is for creating the grid of the game
    void create_grid(){
        //keep track of index we are working with
        int number = 1;
        for(int x = 0; x < N; x++){
            for(int y = 0; y < N; y++){
            //cast number to string type
                grid[x][y] = to_string(number).c_str()[0];
                number += 1;
            }
        }
    }

    //this function is to show the grid of the game
    void show_grid(){
        cout << " ----------------\n";
        for(int x = 0; x < N; x++){
            cout << " | ";
            for(int y = 0; y < N; y++){
                cout << " " << grid[x][y] << " | ";
            }
            cout << "\n ----------------\n";
        }
    }

    //This function is to ask the players about their next move
    void ask_turn(){
        string input;
        while(true){
            cout << "Please enter the position where you want to play" << endl;
            getline(cin, input);
            if(input != " "){
                //cutout the first character only if the user enters number bigger than 9
                char entered = input.c_str()[0];
                if(entered >= '1' && entered <= '9'){
                    //cout << "You entered " << entered << endl;
                    // making sure that the character back to the integer format.
                    int enterd_number = entered - '0';
                    int index = enterd_number - 1;
                    int row = index / 3;
                    int col = index % 3;
                    char grid_position = grid[row][col];
                    //cout << "You want to play at position: " << grid_position << endl;
                    if(grid_position == 'X' || grid_position == 'O'){
                        cout << "This position is already taken!"<< endl;
                    }else{
                        grid[row][col] = 'X';
                         break;
                    }
                }else{
                    cout << "You have to play in the positions of range 1 --> 9." << endl;
                }
            }else{
                cout << "You must enter a position to play in." << endl;
            }
        }
    }

    //this function is for computer as a player
    void computer_player_turn(){
        while(true){
            int computer_choice = (rand() % 9) + 1;
            //cout << "computer chose" << " " << computer_choice << endl;
            int row = (computer_choice - 1) / 3;
            int col = (computer_choice - 1) % 3;
            char grid_position = grid[row][col];
            if(grid_position == 'X' || grid_position == 'O'){
                //This position is already taken, try another random number
                continue;
            }else{
                cout << "The computer chose position " << computer_choice << " " << "to play in." << endl;
                grid[row][col] = 'o';
                break;
            }
        }
    }

    //this function output's is the winner
    void check_win(){
        //win moves are: 123, 456, 789, 147, 258, 369, 159, 357
         //creating the list of win moves
         const char* winning_moves[8] = {
             "123", "456", "789", "147", "258", "369", "159", "753"
         };

         //loop through all of the possible winning moves
         for(int i = 0; i < 8; i++){
            bool winner = true;
            char previous_grid = '0';
            const char* winning_move = winning_moves[i];

            for(int index = 0; index < N; index++){
                char character = winning_move[index];
                int entered_number = character - '0';
                int grid_space = entered_number - 1;

                int row = grid_space / N;
                int col = grid_space % N;
                char grid_char = grid[row][col];

                if(previous_grid == '0'){
                    previous_grid = grid_char;
                }else if(previous_grid == grid_char){
                    //may be the winner
                    continue;
                }else{
                    //this player is not the winner
                    winner = false;
                    break;
                }
            }
            if(winner){
                cout << "congratulations, the player " << previous_grid << " " << "won." << endl;
                exit(0);
                break;
         }
    }
}
    //Constructor of the class game
    TicTacToe(){
        create_grid();
        show_grid();
        check_win();
        while(true){
            ask_turn();
            //show_grid();
            check_win();
            computer_player_turn();
            show_grid();
            check_win();


        }
    }
};

int main(int arr, char* arr2[]){
    //Create the object of the class
    TicTacToe game;
    return 0;
}
