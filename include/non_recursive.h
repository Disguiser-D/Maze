#include<iostream>
#include<malloc.h>
#define maxsize 100
using namespace std;
#define M 8
#define N 8

// https://blog.csdn.net/wyh1618/article/details/83547074?utm_medium=distribute.pc_relevant.none-task-blog-baidujs_title-1&spm=1001.2101.3001.4242
int mg[M+2][N+2]=
        {
                {1,1,1,1,1,1,1,1,1,1},
                {1,0,0,0,0,0,1,1,0,1},
                {1,0,1,1,0,0,1,1,0,1},
                {1,0,1,1,0,1,1,1,0,1},
                {1,0,1,1,0,1,0,1,1,1},
                {1,1,0,1,0,1,0,0,1,1},
                {1,0,1,1,0,1,1,1,0,1},
                {1,0,0,1,0,1,1,1,1,1},
                {1,1,0,0,0,0,0,0,0,1},
                {1,1,1,1,1,1,1,1,1,1}
        };
typedef struct
{
    int i;
    int j;
    int di;
}box;
typedef struct a
{
    box date;
    struct a *next;
}sqstack;
void initstack(sqstack *&s)
{
    s=(sqstack *)malloc(sizeof(sqstack));
    s->next=NULL;
}
void destorystack(sqstack *&s)
{
    sqstack *pre=s,*p=s->next;
    while(p!=NULL)
    {

        free(pre);
        pre=p;
        p=pre->next;
    }
    free(pre);
}
bool stackempty(sqstack *s)
{
    return (s->next==NULL);
}
bool push(sqstack *&s,box &e)
{
    sqstack *p;
    p=(sqstack *)malloc(sizeof(sqstack));
    p->date=e;
    p->next=s->next;
    s->next=p;
}
bool pop(sqstack *&s,box &e)
{
    sqstack *p;
    if(s->next==NULL)
        return false;
    p=s->next;
    e=p->date;
    s->next=p->next;
    free(p);
    return true;
}
bool gettop(sqstack *&s,box &e)
{
    e=s->next->date;
    return true;
}
bool mgpath(int xi,int yi,int xe,int ye)
{
    box path[maxsize],e;
    int i,j,di,il,jl,k;
    bool find;
    sqstack *s;
    initstack(s);
    e.i=xi;
    e.j=yi;
    e.di=-1;
    push(s,e);
    mg[xi][yi]=-1;
    while(!stackempty(s))
    {
        gettop(s,e);
        i=e.i;
        j=e.j;
        di=e.di;
        if(xe==i&&ye==j)
        {
            cout<<"\t迷宫路径如下:"<<endl;
            cout<<"\t";
            k=0;
            while(!stackempty(s))
            {
                pop(s,e);
                path[k++]=e;
            }
            while(k>=1)
            {
                k--;
                cout<<"("<<path[k].i<<','<<path[k].j<<") ";
            }
            cout<<endl;
            destorystack(s);
            return true;
        }
        find=false;
        while(di<4&&!find)
        {
            di++;
            switch(di)
            {
                case 0:il=i-1;jl=j;break;
                case 1:il=i;jl=j+1;break;
                case 2:il=i+1;jl=j;break;
                case 3:il=i;jl=j-1;break;
            }
            if(mg[il][jl]==0)
                find=true;
        }
        if(find)
        {
            s->date.di=di;
            e.i=il;
            e.j=jl;
            e.di=-1;
            push(s,e);
            mg[il][jl]=-1;
        }
        else
        {
            pop(s,e);
            mg[e.i][e.j]=0;
        }
    }
    destorystack(s);
    return false;
}