#include <iostream>

#include "include/loadmaze.h"
#include "include/allmazeaccess.h"
#include "include/createmaze.h"
#include "include/base.h"
#include "include/non_recursive.h"

int main() {
    string file = "Maze.txt";
    int **Maze = CreateMaze(file);
    if (Maze == nullptr) return -1;
    showMaze(Maze);
    RunAllAccessDFS(LoadStartX(file), LoadStartY(file), LoadEndX(file), LoadEndY(file), Maze);
    RunAllAccessBFS(LoadStartX(file), LoadStartY(file), LoadEndX(file), LoadEndY(file), Maze);
    return 0;
}


