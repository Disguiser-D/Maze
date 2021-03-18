#include <iostream>

#include "include/loadmaze.h"
#include "include/allmazeaccess.h"
#include "include/createmaze.h"
#include "include/base.h"
#include "include/non_recursive.h"

int main() {
    string file = "out.txt";
    int **Maze = CreateMaze(file);
    if (Maze == nullptr) return -1;
    showMaze(Maze);
    //createMaze(1,3,20);
    //RunAllAccessDFS(LoadStartX(file), LoadStartY(file), LoadEndX(file), LoadEndY(file), Maze);
    //RunAllAccessBFS(LoadStartX(file), LoadStartY(file), LoadEndX(file), LoadEndY(file), Maze);
    while (1){
        int i=3;
    }
    return 0;
}


