#include <iostream>
#include <vector>
using namespace std;

// A fucntion to print the sudoku board
void printSudoku(int arr[9][9]) {
    cout << "----------------------------------" << endl;
    for(int r = 0; r < 9; r++) {
        for (int c = 0; c < 9; c++) {
            cout << arr[r][c] << " | ";
        }
        cout << endl;
        cout << "--  --  --  --  --  --  --  --  --" << endl;
    }
}

// A function to check if we can place a number in an empty cell; if this number apply the constraints of the game
bool canPlace(int arr[9][9], int row, int column, int num) {
    // check it the cell is empty
    if (arr[row][column] != 0)
        return false;

    bool status = true;
    int gridx = (column / 3) * 3;  // 0  3  6
    int gridy = (row / 3) * 3;  // 0  3  6

    for(int i = 0; i < 9; i++) {
        if (arr[row][i] == num) {  // check 2nd constraint
            status = false;
            break;
        }

        if(arr[i][column] == num) {  // check 3rd constraint
            status = false;
            break;
        }

        if (arr[gridy + i / 3][gridx + i % 3] == num) {  // check 4th constraint
            status = false;
            break;
        } 
    }
    return status;
}

// A function to get all the numbers can be put in the cell
vector<int> findPlaceables(int arr[9][9], int row, int col) {
    vector<int> cps = {};
    for(int i = 1; i <= 9; i++) {
        if (canPlace(arr, row, col, i)) 
            cps.push_back(i);
    }
    return cps;
}

// A fucntion to get a copy of the array
void copyArr(int arr[9][9], int arrCpy[9][9]) {
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            arrCpy[i][j] = arr[i][j];
        }
    }
}

// A fucntion to get the next empty column and row
void nextEmpty(int arr[9][9], int r, int c, int &nRow, int &nColumn) {
    int index = 9 * 9;
    for(int i = r * 9 + c + 1; i < index; i++) {
            if (arr[i / 9][i % 9] == 0){
                index = i;
                break;
            }
    }
    nRow = index / 9;
    nColumn = index % 9;
}

//A function returns if the suboku can be solved or nor
bool solveSudoku(int arr[9][9], int r, int c) {
    // system("cls");
    // printSudoku(arr);

    if (r > 8)
        return true;

    if (arr[r][c] != 0) { // if the cell is not empty, skip it and check for the next one
        int nextColumn, nextRow; 
        nextEmpty(arr, r, c, nextRow, nextColumn);
        return solveSudoku(arr, nextRow, nextColumn);
    }
    
    // find the numbers can be put into that row or column
    vector<int> placeables = findPlaceables(arr, r, c);

    if(placeables.size() == 0)
        return false;

    bool status = false;
    for(int i = 0; i < placeables.size(); i++) {
        int n = placeables[i];
        int arrCpy[9][9];
        copyArr(arr, arrCpy);
        arrCpy[r][c] = n;  // possibility to explore

        int nextColumn, nextRow; 
        nextEmpty(arrCpy, r, c, nextRow, nextColumn);
        if(solveSudoku(arrCpy, nextRow, nextColumn)) {
            copyArr(arrCpy, arr);
            status = true;
            break;
        }
    }
    return status;
}

int main() {
    int board[9][9] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    printSudoku(board);
    solveSudoku(board, 0, 0);
    printSudoku(board);

    return 0;
}