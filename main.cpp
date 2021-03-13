#include <iostream>

#include "include/loadmaze.h"
#include "include/allmazeaccess.h"
#include "include/non_recursive.h"

int main() {
    string file = "Maze_nonrecursive.txt";
    int **b = CreateMaze(file);
    if (b == nullptr) return -1;
    RunAllAccessBFS(LoadStartX(file), LoadStartY(file), LoadEndX(file), LoadEndY(file), b);
//    for(unsigned int i=0;i<=8;i++) {
//        std::cout<<b[i][i]<<endl;
//    }
}
//    if (b == nullptr) return -1;
//    RunAllAccessDFS(LoadStartX("333.txt"), LoadStartY("333.txt"), LoadEndX("333.txt"), LoadEndY("333.txt"), b);
//}

