#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <unordered_set>
using namespace std;

list<int> BT_solve_maze(list<int> maze[], int start, int finish) {
    unordered_set<int> visited;  // visited nodes set
    list<int> path;

    // add the start point at the end of the path list
    path.push_back(start);
    int current_point = start;
    visited.insert(current_point);

    while(path.back() != finish && path.empty() == false) {
        list<int>::iterator iter = maze[current_point].begin();  // traverse the visited list to check if the next point is already visted or not
        bool foundOutlet = false;
        while((iter != maze[current_point].end()) && (!foundOutlet)) {
            // check if connection leads to unvisited point
            if(visited.count(*iter) == 0)   // if not found
                foundOutlet = true;
            else
                iter++;
        }

        if(foundOutlet){
            path.push_back(*iter);
            visited.insert(*iter);
        }
        else
            path.pop_back(); // backtrack if not found a new point to go

        current_point = path.back();
    }

    return path;
}