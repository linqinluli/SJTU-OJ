#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>

using namespace std;

const int MAX=101;
const int dx[4]={0,0,-1,1},dy[4]={1,-1,0,0};

struct point
{
    int x,y;
};

int N,M,All;
int Alt[MAX][MAX];
bool vid[MAX][MAX];
int heap_size;
point Heap[MAX*MAX];

void heap_ins(int x,int y)
{
    int i;
    for (i=++heap_size;Alt[x][y]<Alt[Heap[i/2].x][Heap[i/2].y];i=i/2)
        Heap[i]=Heap[i/2];
    Heap[i].x=x; Heap[i].y=y;
}

point heap_delmin()
{
    point R=Heap[1],M=Heap[heap_size--];
    int i,c;
    for (i=1;i*2<=heap_size;i=c)
    {
        c=i*2;
        if (c!=heap_size && Alt[Heap[c+1].x][Heap[c+1].y]<Alt[Heap[c].x][Heap[c].y])
            c++;
        if (Alt[M.x][M.y] > Alt[Heap[c].x][Heap[c].y])
            Heap[i]=Heap[c];
        else
            break;
    }
    Heap[i]=M;
    return R;
}

void init()
{
    freopen("wod.in","r",stdin);
    freopen("wod.out","w",stdout);
    scanf("%d%d",&N,&M);
    for (int i=1;i<=N;i++)
        for (int j=1;j<=M;j++)
            scanf("%d",&Alt[i][j]);
    Alt[0][0]=-0x7FFFFFFF;
    Heap[heap_size=0].x=Heap[0].y=0;
}

inline bool inrange(point A)
{
    return A.x>=1 && A.x<=N && A.y>=1 && A.y<=M;
}

void floodfill(point A,int h)
{
    point B;
    vid[A.x][A.y]=true;
    if (Alt[A.x][A.y]>=h)
        heap_ins(A.x,A.y);
    else
    {
        All+=h-Alt[A.x][A.y];
        for (int i=0;i<4;i++)
        {
            B.x=A.x+dx[i]; B.y=A.y+dy[i];
            if (inrange(B) && !vid[B.x][B.y])
                floodfill(B,h);
        }
    }
}

void solve()
{
    int i,j;
    point A,B;
    for (i=1;i<=N;i++)
    {
        heap_ins(i,1);
        heap_ins(i,M);
        vid[i][1]=vid[i][M]=true;
    }
    for (i=2;i<=M-1;i++)
    {
        heap_ins(1,i);
        heap_ins(N,i);
        vid[1][i]=vid[N][i]=true;
    }
    while (heap_size)
    {
        A=heap_delmin();
        for (i=0;i<4;i++)
        {
            B.x=A.x+dx[i]; B.y=A.y+dy[i];
            if (inrange(B) && !vid[B.x][B.y])
                floodfill(B,Alt[A.x][A.y]);
        }
    }
}

int main()
{
    init();
    solve();
    printf("%d",All);
    return 0;
}
