#include<iostream>
#include<malloc.h>
#include <windows.h>

#define maxsize 100
using namespace std;

// 链栈
typedef struct box {
    int i = -1;
    int j = -1;
    int di{};
} box;
typedef struct path_data {
    box data;
    struct path_data *next{};
} sqstack;

void initstack(sqstack *&s) {
    // 初始化栈
    s = (sqstack *) malloc(sizeof(sqstack));
    s->next = nullptr;
}

void destorystack(sqstack *&s) {
    // 释放栈的内存空间
    sqstack *pre = s, *p = s->next;
    while (p != nullptr) {

        free(pre);
        pre = p;
        p = pre->next;
    }
    free(pre);
}

bool stackempty(sqstack *s) {
    // 判栈空
    return (s->next == nullptr);
}

void push(sqstack *&s, box &e) {
    // 压栈
    sqstack *p;
    p = (sqstack *) malloc(sizeof(sqstack));
    p->data = e;
    p->next = s->next;
    s->next = p;
}

bool pop(sqstack *&s, box &e) {
    // 取栈
    sqstack *p;
    if (s->next == nullptr)
        return false;
    p = s->next;
    e = p->data;
    s->next = p->next;
    free(p);
    return true;
}

bool gettop(sqstack *&s, box &e) {
    // 取栈顶
    e = s->next->data;
    return true;
}
// 链栈

int context_Compared(int x1, int y1, int x2, int y2) {
    // 简单的前后路径对比，得出方向
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
    return -1;
}

// https://blog.csdn.net/wyh1618/article/details/83547074?utm_medium=distribute.pc_relevant.none-task-blog-baidujs_title-1&spm=1001.2101.3001.4242

void strackMgpath(int xi, int yi, int xe, int ye, int **mg) {
    // 栈与迷宫主函数
    box path[maxsize], e;
    int i, j, di, il, jl, k;
    bool find;
    sqstack *s;
    initstack(s);
    e.i = xi;
    e.j = yi;
    e.di = -1;
    push(s, e);
    mg[xi][yi] = -1;
    while (!stackempty(s)) {
        gettop(s, e);
        i = e.i;
        j = e.j;
        di = e.di;
        if (xe == j && ye == i) {
            // xe是纵 ye是横
            cout << "迷宫出口为:" << endl;
//            cout << "\t";
            k = 0;
            while (!stackempty(s)) {
                // 获取路径长度，k 保存了路径长度
                pop(s, e);
//                cout<<k;
                path[k++] = e;
            }
            cout << "\t入口->";
            while (k >= 1) {
                k--;
                cout << "(" << path[k].i << "," << path[k].j << ","
                     << context_Compared(path[k].i, path[k].j, path[k + 1].i, path[k + 1].j) << ")";
            }
            cout << ">-出口" << endl;
            destorystack(s);
//            return true;
        }
        find = false;
        // 迷宫方向寻找
        while (di < 4 && !find) {
            find = false; // 建议每次内循环重置find
            di++;
            switch (di) {
                case 0:
                    // 向左移动
                    il = i - 1;
                    jl = j;
                    break;
                case 1:
                    // 向上移动
                    il = i;
                    jl = j + 1;
                    break;
                case 2:
                    // 向右移动
                    il = i + 1;
                    jl = j;
                    break;
                case 3:
                    // 向下移动
                    il = i;
                    jl = j - 1;
                    break;
                default:
                    continue;
            }
            if (mg[il][jl] == 0)
                // 找到0就是通路
                find = true;
        }
        if (find) {
            // 移动链栈指针，数据：二维数组
            s->data.di = di;  // 数据下一步走向
            e.i = il;
            e.j = jl;
            e.di = -1; // 清空走向
            push(s, e); // 压栈
            mg[il][jl] = -1; // 走过的路赋值为-1
        } else {
            // 当找不到任何出路时才调用
            pop(s, e); // 出栈
            mg[e.i][e.j] = 0; // 标记出口
        }
    }
    destorystack(s); // 释放栈内存
//    return false;
}

void RunAllAccessBFS(int xi, int yi, int xe, int ye, int **mg) {
    std::cout<<xi<<yi<<xe<<ye<<endl;

    strackMgpath(xi, yi, xe, ye, mg);
}