#include <iostream>

#include "include/loadmaze.h"
#include "include/allmazeaccess.h"
#include "include/non_recursive.h"

int main() {
    string filepath = "Maze_nonrecursive.txt";
    int **maze = CreateMaze(filepath);
    if (maze == nullptr) return -1;
    RunAllAccessBFS(LoadStartX(filepath), LoadStartY(filepath), LoadEndX(filepath), LoadEndY(filepath), maze);
//    for(unsigned int i=0;i<=8;i++) {
//        std::cout<<b[i][i]<<endl;
//    }
}
//    if (b == nullptr) return -1;
//    RunAllAccessDFS(LoadStartX("333.txt"), LoadStartY("333.txt"), LoadEndX("333.txt"), LoadEndY("333.txt"), b);
//}

