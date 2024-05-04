#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <unordered_set>
using namespace std;

bool R_solve_maze(list<int> maze[], int start, int finish, unordered_set<int>& visited, list<int>& path) {
    if(start == finish) {
        path.push_front(start);
        return true;
    }

    visited.insert(start);
    list<int>::iterator iter = maze[start].begin();
    while(iter != maze[start].end()) {
        if(visited.count(*iter) == 0) {
            if(R_solve_maze(maze, *iter, finish, visited, path)) {
                path.push_front(start);
                return true;
            }
        }
        iter++;
    }
    return false;
}

list<int> R_solve_maze(list<int> maze[], int start, int finish) {
    unordered_set<int> visited;
    list<int> solution_path;
    R_solve_maze(maze, start, finish, visited, solution_path);
    return solution_path;
}

