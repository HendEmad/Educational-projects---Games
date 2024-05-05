#include <iostream>
#include <vector>
using namespace std;

class SudokuSolver {
private:
    int **board;
    int size;

    // A function to print the sudoku board
    void printSudoku() {
        cout << "----------------------------------" << endl;
        for(int r = 0; r < size; r++) {
            for (int c = 0; c < size; c++) {
                cout << board[r][c] << " | ";
            }
            cout << endl;
            cout << "--  --  --  --  --  --  --  --" << endl;
        }
    }

    // A function to check if we can place a number in an empty cell; if this number applies the constraints of the game
    bool canPlace(int row, int column, int num) {
        // check if the cell is empty
        if (board[row][column] != 0)
            return false;

        bool status = true;
        int gridSize = size / 3;
        int gridx = (column / gridSize) * gridSize;
        int gridy = (row / gridSize) * gridSize;

        for(int i = 0; i < size; i++) {
            if (board[row][i] == num || board[i][column] == num || board[gridy + i / gridSize][gridx + i % gridSize] == num) {
                status = false;
                break;
            }
        }
        return status;
    }

    // A function to get all the numbers that can be put in the cell
    vector<int> findPlaceables(int row, int col) {
        vector<int> cps = {};
        for(int i = 1; i <= size; i++) {
            if (canPlace(row, col, i))
                cps.push_back(i);
        }
        return cps;
    }

    // A function to get a copy of the array
    void copyArr(int** arr, int** arrCpy) {
        for(int i = 0; i < size; i++) {
            for(int j = 0; j < size; j++) {
                arrCpy[i][j] = arr[i][j];
            }
        }
    }

    // A function to get the next empty column and row
    void nextEmpty(int r, int c, int &nRow, int &nColumn) {
    for (int i = r; i < size; i++) {
        for (int j = (i == r) ? c + 1 : 0; j < size; j++) {
            if (board[i][j] == 0) {
                nRow = i;
                nColumn = j;
                return;
            }
        }
    }
    nRow = size;
    nColumn = size;
}

    // A function to solve the Sudoku puzzle
    bool solveSudoku(int r, int c) {
    if (r >= size)
        return true;

    if (board[r][c] != 0) {
        int nextColumn = (c + 1) % size;
        int nextRow = r + (nextColumn == 0 ? 1 : 0);
        return solveSudoku(nextRow, nextColumn);
    }

    vector<int> placeables = findPlaceables(r, c);

    if(placeables.size() == 0)
        return false;

    for(int i = 0; i < placeables.size(); i++) {
        int n = placeables[i];
        board[r][c] = n;

        int nextColumn = (c + 1) % size;
        int nextRow = r + (nextColumn == 0 ? 1 : 0);

        if(solveSudoku(nextRow, nextColumn)) {
            return true;
        }

        // Backtrack if no solution found
        board[r][c] = 0;
    }
    return false;
}

public:
    SudokuSolver(int **inputBoard, int boardSize) {
        size = boardSize;
        board = new int*[size];
        for(int i = 0; i < size; i++) {
            board[i] = new int[size];
            for(int j = 0; j < size; j++) {
                board[i][j] = inputBoard[i][j];
            }
        }
    }

    // A function to solve the Sudoku puzzle and print the solution
    void solve() {
        printSudoku();
        solveSudoku(0, 0);
        printSudoku();
    }

    // Destructor to free dynamically allocated memory
    ~SudokuSolver() {
        for (int i = 0; i < size; i++) {
            delete[] board[i];
        }
        delete[] board;
    }
};

int main() {
    int size;
    cout << "Enter the size of the Sudoku grid: ";
    cin >> size;

    int **board = new int*[size];
    cout << "Enter the Sudoku grid row by row, use 0 for empty cells:" << endl;
    for (int i = 0; i < size; i++) {
        board[i] = new int[size];
        for (int j = 0; j < size; j++) {
            cin >> board[i][j];
        }
    }

    SudokuSolver solver(board, size);
    solver.solve();

    // Free dynamically allocated memory
    for (int i = 0; i < size; i++) {
        delete[] board[i];
    }
    delete[] board;

    return 0;
}
