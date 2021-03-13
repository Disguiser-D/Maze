#include<iostream>
#include<malloc.h>

#define maxsize 100
using namespace std;

// ��ջ
typedef struct box {
    int i = -1;
    int j = -1;
    int di{};
} box;
typedef struct a {
    box date;
    struct a *next{};
} sqstack;

void initstack(sqstack *&s) {
    // ��ʼ��ջ
    s = (sqstack *) malloc(sizeof(sqstack));
    s->next = nullptr;
}

void destorystack(sqstack *&s) {
    // �ͷ�ջ���ڴ�ռ�
    sqstack *pre = s, *p = s->next;
    while (p != nullptr) {

        free(pre);
        pre = p;
        p = pre->next;
    }
    free(pre);
}

bool stackempty(sqstack *s) {
    // ��ջ��
    return (s->next == nullptr);
}

void push(sqstack *&s, box &e) {
    // ѹ��ջ
    sqstack *p;
    p = (sqstack *) malloc(sizeof(sqstack));
    p->date = e;
    p->next = s->next;
    s->next = p;
}

bool pop(sqstack *&s, box &e) {
    // ȡ��ջ
    sqstack *p;
    if (s->next == nullptr)
        return false;
    p = s->next;
    e = p->date;
    s->next = p->next;
    free(p);
    return true;
}

bool gettop(sqstack *&s, box &e) {
    // ȡջ��
    e = s->next->date;
    return true;
}
// ��ջ

int context_Compared(int x1, int y1, int x2, int y2) {
    // �Ա�����ǰ��·�������ط���
    //printf("%d,%d,%d,%d",x1,y1,x2,y2);
    if (x2 == -1 && y2 == -1) {
        //�����Ѱ·
        return 0;
    }
    if (x1 == x2) {
        //�����ƶ�
        if (y2 < y1) {
            //�����ƶ�
            return 3;
        } else {
            return 1;
        }
    } else if (y1 == y2) {
        //�����ƶ�
        if (x2 < x1) {
            //�����ƶ�
            return 4;
        } else {
            return 2;
        }
    }
    return -1;
}

// https://blog.csdn.net/wyh1618/article/details/83547074?utm_medium=distribute.pc_relevant.none-task-blog-baidujs_title-1&spm=1001.2101.3001.4242

bool strack_maze_path(int xi, int yi, int xe, int ye, int **mg) {
    // ջ&�Թ��ĺ��ĺ��������õ���BFS�����������
    box path[maxsize], e;
    int i, j, di, il, jl, k;
    bool find;
    sqstack *s;
    initstack(s);
    e.i = xi;
    e.j = yi;
    e.di = -1;
    push(s, e);
    mg[xi][yi] = -1; // ��ʼ���Թ�
    while (!stackempty(s)) {
        gettop(s, e);
        i = e.i;
        j = e.j;
        di = e.di;
        if (xe == i && ye == j) {
            cout << "\t�Թ�����Ϊ:" << endl;
            cout << "\t";
            k = 0;
            while (!stackempty(s)) {
                pop(s, e);
                path[k++] = e;
            }
            cout << "���->";
            while (k >= 1) {
                k--;
                cout << "(" << path[k].i << ',' << path[k].j << ','
                     << context_Compared(path[k].i, path[k].j, path[k + 1].i, path[k + 1].j) << "),";
            }
            cout << ">-����" << endl;
            destorystack(s);
            return true;
        }
        // ջ����
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
                default:
                    continue;
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
    strack_maze_path(xi, yi, xe, ye, mg);
}