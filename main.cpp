#include <iostream>

#include "include/loadmaze.h"
#include "include/allmazeaccess.h"
#include "include/createmaze.h"
#include "include/base.h"
#include "include/non_recursive.h"


void showMenu()
{
    cout<<"------------------------------------------------------------------------------------"<<endl;
    cout<<"                                  1.生成迷宫                                         "<<endl;
    cout<<"                                  2.求解迷宫所有解法                                 "<<endl;
    cout<<"                                  3.求解迷宫一种解法                                 "<<endl;
    cout<<"                                  4.退出程序                                        "<<endl;
    cout<<"------------------------------------------------------------------------------------"<<endl;
    cout<<"请输入您的选项:";
}

int main() {
    string userInput;
    while (true) {
        showMenu();
        //getline(cin, userInput);
        cin>>userInput;
        string str="\n";
        getline(cin,str);
        if (userInput == "1") {
            cout << "请输入生成后的迷宫输出的文件名(直接回车默认文件名为out.txt):";
            string fileName;
            getline(cin, fileName);
            cout << "请输入生成的迷宫起点(终点为随机生成,输入示例:1 1):";
            int xi, yi;
            cin >> xi >> yi;
            cout << "请输入生成的迷宫大小(迷宫为正方形，输入边长即可):";
            int n;
            cin >> n;
            createMaze(xi, yi, n, fileName);
        } else if (userInput == "2") {
            cout << "请输入要求解的迷宫文件(直接回车默认文件名为out.txt):";
            string fileName;
            getline(cin, fileName);
            if (fileName.empty()) fileName = "out.txt";
            int **Maze = CreateMaze(fileName);
            if (Maze == nullptr) cout << "迷宫文件为非法文件，无法读取，请检查迷宫文件是否正常";
            else {
                showMaze(Maze);
                RunAllAccessDFS(LoadStartX(fileName), LoadStartY(fileName), LoadEndX(fileName), LoadEndY(fileName),
                                Maze);
                delete Maze;
            }
        } else if (userInput == "3") {
            cout << "请输入要求解的迷宫文件(直接回车默认文件名为out.txt):";
            string fileName;
            getline(cin, fileName);
            if (fileName.empty()) fileName = "out.txt";
            int **Maze = CreateMaze(fileName);
            if (Maze == nullptr) cout << "迷宫文件为非法文件，无法读取，请检查迷宫文件是否正常";
            else {
                showMaze(Maze);
                RunAllAccessBFS(LoadStartX(fileName), LoadStartY(fileName), LoadEndX(fileName), LoadEndY(fileName),
                                Maze);
                delete Maze;
            }
        } else if (userInput == "4") {
            return 0;
        } else if (userInput.empty()){
            cout<<"";
        } else {
            cout << "非法输入，请检查你的输入"<<endl;
            userInput = "";
        }
    }
    //string file = "out.txt";
    //int **Maze = CreateMaze(file);
    //if (Maze == nullptr) return -1;
    //showMaze(Maze);
    //createMaze(1,3,20);
    //RunAllAccessDFS(LoadStartX(file), LoadStartY(file), LoadEndX(file), LoadEndY(file), Maze);
    //RunAllAccessBFS(LoadStartX(file), LoadStartY(file), LoadEndX(file), LoadEndY(file), Maze);
    //while (1){
    //    int i=3;
    //}
    //return 0;
}



