#include<iostream>
#include<malloc.h>

#define maxsize 100
using namespace std;

// 链栈
typedef struct {
    int i = -1;
    int j = -1;
    int di;
} box;
typedef struct a {
    box date;
    struct a *next;
} sqstack;

void initstack(sqstack *&s) {
    s = (sqstack *) malloc(sizeof(sqstack));
    s->next = NULL;
}

void destorystack(sqstack *&s) {
    sqstack *pre = s, *p = s->next;
    while (p != NULL) {

        free(pre);
        pre = p;
        p = pre->next;
    }
    free(pre);
}

bool stackempty(sqstack *s) {
    return (s->next == NULL);
}

void push(sqstack *&s, box &e) {
    sqstack *p;
    p = (sqstack *) malloc(sizeof(sqstack));
    p->date = e;
    p->next = s->next;
    s->next = p;
}

bool pop(sqstack *&s, box &e) {
    sqstack *p;
    if (s->next == NULL)
        return false;
    p = s->next;
    e = p->date;
    s->next = p->next;
    free(p);
    return true;
}

bool gettop(sqstack *&s, box &e) {
    e = s->next->date;
    return true;
}
// 链栈

int context_Compared(int x1, int y1, int x2, int y2) {
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

bool strackMgpath(int xi, int yi, int xe, int ye, int **mg) {
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
        if (xe == i && ye == j) {
            cout << "\t迷宫出口为:" << endl;
            cout << "\t";
            k = 0;
            while (!stackempty(s)) {
                pop(s, e);
                path[k++] = e;
            }
            cout << "入口->";
            while (k >= 1) {
                k--;
                cout << "(" << path[k].i << ',' << path[k].j << ','
                     << context_Compared(path[k].i, path[k].j, path[k + 1].i, path[k + 1].j) << "),";
            }
            cout << ">-出口" << endl;
            destorystack(s);
            return true;
        }
        find = false;
        while (di < 4 && !find) {
            di++;
            switch (di) {
                case 0:
                    il = i - 1;
                    jl = j;
                    break;
                case 1:
                    il = i;
                    jl = j + 1;
                    break;
                case 2:
                    il = i + 1;
                    jl = j;
                    break;
                case 3:
                    il = i;
                    jl = j - 1;
                    break;
            }
            if (mg[il][jl] == 0)
                find = true;
        }
        if (find) {
            s->date.di = di;
            e.i = il;
            e.j = jl;
            e.di = -1;
            push(s, e);
            mg[il][jl] = -1;
        } else {
            pop(s, e);
            mg[e.i][e.j] = 0;
        }
    }
    destorystack(s);
    return false;
}

void RunAllAccessBFS(int xi, int yi, int xe, int ye, int **mg) {
    strackMgpath(xi, yi, xe, ye, mg);
}