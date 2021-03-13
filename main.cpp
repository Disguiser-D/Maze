#include <iostream>
#include <cstring>

#include "include/loadmaze.h"
#include "include/allmazeaccess.h"
#include "include/non_recursive.h"

int main() {
    string filepath = "Maze_nonrecursive.txt";
    int **maze = CreateMaze(filepath);
    if (maze == nullptr) return -1;
    RunAllAccessDFS(LoadStartX(filepath), LoadStartY(filepath), LoadEndX(filepath), LoadEndY(filepath), maze);
    RunAllAccessBFS(LoadStartX(filepath), LoadStartY(filepath), LoadEndX(filepath), LoadEndY(filepath), maze);
    return 0;
}

