#include <iostream>

#include<fstream>

#include "include/loadmaze.h"
#include "include/allmazeaccess.h"
#include "include/createmaze.h"
#include "include/base.h"

int main()
{

    int **b = CreateMaze("333.txt");
    if (b == nullptr) return -1;
    RunAllAccessDFS(LoadStartX("333.txt"),LoadStartY("333.txt"),LoadEndX("333.txt"),LoadEndY("333.txt"), b);

    showMaze(b);
    //std::cin>>a;
    //std::cout<<checkInuPut(a);
}

