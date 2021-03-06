//
// Created by 17289 on 2021/3/11.
//求解所有的迷宫路径
//

#ifndef MAZE_ALLMAZEACCESS_H
#define MAZE_ALLMAZEACCESS_H

#endif //MAZE_ALLMAZEACCESS_H


#include <stdio.h>
#include <string.h>

#define MaxSize 550

typedef struct {
    int i;                //当前方块的行号
    int j;                //当前方块的列号
} Box;
typedef struct {
    Box data[MaxSize];
    int length;            //路径长度
} PathType;                //定义路径类型
int count = 0;            //存放迷宫路径的条数


int findDirection(int x1, int y1, int x2, int y2) {
    //printf("%d,%d,%d,%d",x1,y1,x2,y2);
    if (x2 == -1 && y2 == -1) {
        //已完成寻路
        return 0;
    }
    if (x1 == x2) {
        //左右移动
        if (y2 < y1) {
            //向左移动
            return 3;
        } else {
            return 1;
        }
    } else if (y1 == y2) {
        //上下移动
        if (x2 < x1) {
            //向上移动
            return 4;
        } else {
            return 2;
        }
    }
    return -1;//发生异常
}

void mgpath(int xi, int yi, int xe, int ye, PathType path, int **mg)
//求解路径为:(xi,yi)->(xe,ye)
{
    /*for(int i = 0; i < 22; i++)
    {
        for(int j = 0; j < 22; j++)
        {
            std::cout<<mg[i][j]<<" ";
        }
        std::cout<<std::endl;
    }*/
    //std::cout<<std::endl;
    int di, k, i, j;
    if (xi == xe && yi == ye)        //找到了出口,输出路径
    {
        path.data[path.length].i = xi;
        path.data[path.length].j = yi;
        path.length++;
        printf("迷宫路径%d如下:\n", ++count);
        for (k = 0; k < path.length; k++) {
            printf("(%d,%d,%d)", path.data[k].i - 1, path.data[k].j - 1,
                   findDirection(path.data[k].i, path.data[k].j, path.data[k + 1].i, path.data[k + 1].j));
            printf("  ");
        }
        printf("\n");
    } else                        //(xi,yi)不是出口
    {
        if (mg[xi][yi] == 0)        //(xi,yi)是一个可走方块
        {
            di = 0;
            while (di < 4)        //找(xi,yi)的一个相邻方块(i,j)
            {
                switch (di) {
                    case 0:
                        i = xi - 1;
                        j = yi;
                        break;
                    case 1:
                        i = xi;
                        j = yi + 1;
                        break;
                    case 2:
                        i = xi + 1;
                        j = yi;
                        break;
                    case 3:
                        i = xi;
                        j = yi - 1;
                        break;
                }
                path.data[path.length].i = xi;
                path.data[path.length].j = yi;
                path.length++;
                mg[xi][yi] = -1;            //避免重复找路径
                mgpath(i, j, xe, ye, path, mg);
                path.length--;            //回退一个方块
                mg[xi][yi] = 0;            //恢复(xi,yi)为可走
                di++;
            }
        }
    }
}


/*
 * Describe:求解迷宫的所有路径
 * Parameter:int(起点坐标X轴),int(起点坐标y轴),int(终点坐标X轴),int(终点坐标y轴),int**(迷宫二维数组)
 * Return:void(输出结果)
 */
void RunAllAccessDFS(int xi, int yi, int xe, int ye, int **mg) {
    PathType path;
    path.length = 0;                //初始化路径长度
    memset(path.data, -1, MaxSize);
    mgpath(xi, yi, xe, ye, path, mg);
}


