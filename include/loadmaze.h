//
// Created by 17289 on 2021/3/11.
//此头文件用于读取文本中的各种迷宫数据
//

#ifndef MAZE_LOADMAZE_H
#define MAZE_LOADMAZE_H

#endif //MAZE_LOADMAZE_H

#include <iostream>
#include<fstream>

/*
 * Describe:读取文本数据创建迷宫
 * Parameter:String(需要读取数据的文件名)
 * Return:int**(创建的动态二维数组的指针,若返回的是空指针则是非法迷宫)
 */
int **CreateMaze(const std::string &fileName) {
    std::fstream inFile(fileName, std::ios::in);
    if (!inFile)std::cout << "文件打开失败" << std::endl;
    //读取迷宫大小
    int mazeSize, xi, yi, xe, ye;
    inFile >> mazeSize;

    //读取迷宫的起点和终点数据
    inFile >> xi >> yi;
    inFile >> xe >> ye;


    //创建动态二维数组
    int **m = new int *[mazeSize + 2];
    for (int i = 0; i < mazeSize + 2; i++) {
        m[i] = new int[mazeSize + 2];
    }


    //全部赋值为1 间接建墙
    for (int i = 0; i < mazeSize + 2; i++) {
        for (int j = 0; j < mazeSize + 2; j++) {
            m[i][j] = 1;
        }

    }

    //读取迷宫数据
    for (int i = 1; i <= mazeSize; i++) {
        for (int j = 1; j <= mazeSize; j++) {
            inFile >> m[i][j];
            //如果不是1或者0则为非法数据，返回空指针
            if (m[i][j] == 1 || m[i][j] == 0);
            else return nullptr;
        }
    }

    //判断是否为非法迷宫(起点或终点在墙上或越界)
    if (xi >= mazeSize || yi >= mazeSize || xe >= mazeSize || ye >= mazeSize || xi < 0 || yi < 0 || xe < 0 || ye < 0 ||
        m[xi + 1][yi + 1] == 1 || m[xe + 1][ye + 1] == 1)
        return nullptr;

    inFile.close();
    return m;
}

/*
 * Describe:读取文本数据中的起点X轴数据
 * Parameter:String(需要读取数据的文件名)
 * Return:int(起点的X轴数据)
 */
int LoadStartX(const std::string &fileName) {
    std::fstream inFile(fileName, std::ios::in);
    if (!inFile)std::cout << "文件打开失败" << std::endl;

    inFile.seekg(std::ios::beg + 2);  // 偏移文件指针，直接定位到文本中的迷宫数据，提升效率

    int xi;
    inFile >> xi;
    return xi + 1;
}

/*
 * Describe:读取文本数据中的起点Y轴数据
 * Parameter:String(需要读取数据的文件名)
 * Return:int(起点的Y轴数据)
 */
int LoadStartY(const std::string &fileName) {
    std::fstream inFile(fileName, std::ios::in);
    if (!inFile)std::cout << "文件打开失败" << std::endl;

    inFile.seekg(std::ios::beg + 4);  // 偏移文件指针，直接定位到文本中的迷宫数据，提升效率

    int yi;
    inFile >> yi;
    return yi + 1;
}

/*
 * Describe:读取文本数据中的终点X轴数据
 * Parameter:String(需要读取数据的文件名)
 * Return:int(终点的X轴数据)
 */
int LoadEndX(const std::string &fileName) {
    std::fstream inFile(fileName, std::ios::in);
    if (!inFile)std::cout << "文件打开失败" << std::endl;

    inFile.seekg(std::ios::beg + 9);  // 偏移文件指针，直接定位到文本中的迷宫数据，提升效率

    int xe;
    inFile >> xe;
    return xe + 1;
}

/*
 * Describe:读取文本数据中的终点Y轴数据
 * Parameter:String(需要读取数据的文件名)
 * Return:int(终点的Y轴数据)
 */
int LoadEndY(const std::string &fileName) {
    std::fstream inFile(fileName, std::ios::in);
    if (!inFile)std::cout << "文件打开失败" << std::endl;

    inFile.seekg(std::ios::beg + 11);  // 偏移文件指针，直接定位到文本中的迷宫数据，提升效率

    int ye;
    inFile >> ye;
    return ye + 1;
}

/*
 * Describe:读取文本数据中的迷宫大小数据
 * Parameter:String(需要读取数据的文件名)
 * Return:int(迷宫大小)
 */
int LoadMazeSize(const std::string &fileName) {
    std::fstream inFile(fileName, std::ios::in);
    if (!inFile)std::cout << "文件打开失败" << std::endl;

    //读取迷宫大小
    int mazeSize;
    inFile >> mazeSize;
    return mazeSize;
}

/*
int main(){
    int **b = CreateMaze("333.txt");
    for(int i = 0; i < 7; i++)
    {
        for(int j = 0; j < 7; j++)
        {
            std::cout<<b[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
}*/
