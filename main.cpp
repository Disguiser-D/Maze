#include <iostream>

#include<fstream>

#include "loadmaze.h"
#include "allmazeaccess.h"

int main()
{

    int **b = CreateMaze("333.txt");
    if (b == nullptr) return -1;
    RunAllAccessDFS(LoadStartX("333.txt"),LoadStartY("333.txt"),LoadEndX("333.txt"),LoadEndY("333.txt"), b);
}

