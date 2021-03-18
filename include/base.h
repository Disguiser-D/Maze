//
// Created by 17289 on 2021/3/13.
//

#ifndef MAZE_BASE_H
#define MAZE_BASE_H

#endif //MAZE_BASE_H

#include <string>
#include <malloc.h>
#include <windows.h>

/*
 * Describe:检查用户输入是否正确
 * Parameter:String(用户输入的字符串)
 * Return:bool(返回true则输入正常，返回false则输入异常)
 */
bool checkInuPut(const std::string& userInput)
{
    try{
        int userInputNumber = std::stoi(userInput);
    }catch (std::invalid_argument&){
        // if no conversion could be performed
        cout << "无效参数" << endl;
        return false;
    }
    catch (std::out_of_range&){
        // if the converted value would fall out of the range of the result type
        // or if the underlying function (std::strtol or std::strtoull) sets errno
        // to ERANGE.
        cout << "超出范围" << endl;
        return false;
    }
    catch (...) {
        // everything else
        cout << "未知错误" << endl;
        return false;
    }
    return true;
}

int checkOS()
{
    int os_flag=0;

#ifdef linux
    os_flag=1;
#endif

#ifdef _UNIX
    os_flag=2;
#endif

#ifdef __WINDOWS_
    os_flag=3;
#endif

#ifdef _WIN32
    os_flag=4;
#endif

    return os_flag;
}

char *randStr(char *str, const int len)
{
    srand(time(NULL));
    int i;
    for (i = 0; i < len; ++i)
    {
        switch ((rand() % 3))
        {
            case 1:
                str[i] = 'A' + rand() % 26;
                break;
            case 2:
                str[i] = 'a' + rand() % 26;
                break;
            default:
                str[i] = '0' + rand() % 10;
                break;
        }
    }
    str[++i] = '\0';
    return str;
}

/*
 * Describe:将一个迷宫打印出来
 * Parameter:int**(用动态二维数组表示的迷宫)
 * Return:void(打印出迷宫)
 */
void showMaze(int** maze)
{
    //system("mode con cols=198 lines=150");


    //HWND hwnd=GetForegroundWindow();//获取当前进程的句柄


    //ShowWindow(hwnd,SW_MAXIMIZE);


    char title[260];
    if (GetConsoleTitle(title, 260));
    else cout << "获取句柄失败" << endl;

    char randomTitle[258];


    randStr(randomTitle, 256);

    SetConsoleTitle(randomTitle);

    Sleep(40);

    HWND hwnd = FindWindow(NULL, randomTitle);

    ShowWindow(hwnd,SW_MAXIMIZE);

    SetConsoleTitle(title);


    int size = 0;

    if (checkOS() == 3 || checkOS() == 4) {
        size_t size_tmp = _msize(maze);
        size = (int)size_tmp / 4;
    }
    else {
        printf("只支持windows系统");
    }
    if (size>=100) printf("迷宫太大，无法显示");
    else{
        printf("\n");
        for(int i=0;i<size;i++)
        {
            for(int j=0;j<size;j++)
            {
                if (i == 0 && j == 0) std::cout<<"   ";
                else if (i > size-2 || j > size - 2);
                else if (i == 0) j>10?(j%2!=0?printf("%d",j-1):printf("  ")):printf("%d ",j-1);
                else if (j == 0) i>10?printf("%d ",i-1):printf("%d  ",i-1);
                    //cout<<maze[i][j]<<endl;
                else if (maze[i][j] == 1) std::cout<<"■";
                else if (maze[i][j] == 0) std::cout<<"  ";
                //std::cout<<m[i][j];
            }
            std::cout<<std::endl;

        }
    }
}


