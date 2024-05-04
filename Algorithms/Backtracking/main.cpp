#include "iterative_backtracking.cpp"
#include "recursive_backtracking.cpp"
#include <list>
using namespace std;

int main() {
    list<int> sample_maze[9];

    sample_maze[0].push_back(1);
    sample_maze[0].push_back(3);

    sample_maze[1].push_back(0);
    sample_maze[1].push_back(2);

    sample_maze[2].push_back(1);

    sample_maze[3].push_back(0);
    sample_maze[3].push_back(4);
    sample_maze[3].push_back(6);

    sample_maze[4].push_back(5);
    sample_maze[4].push_back(3);
    sample_maze[4].push_back(7);

    sample_maze[5].push_back(4);

    sample_maze[6].push_back(3);

    sample_maze[7].push_back(4);
    sample_maze[7].push_back(8);

    sample_maze[8].push_back(7);

    list<int> solution = BT_solve_maze(sample_maze, 0, 8);
    list<int>::iterator iter;

    cout << "Path found by iterative_solution: \n";
    for(iter = solution.begin(); iter != solution.end(); iter++) {
        cout << *iter << "\n";
    }

    list<int> solution2 = R_solve_maze(sample_maze, 0, 8);

    cout << "Path found by recursive solution: \n";
    for(iter = solution2.begin(); iter != solution2.end(); iter++) {
        cout << *iter << "\n";
    }

    return 0;
}