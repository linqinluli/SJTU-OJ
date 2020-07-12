#include <iostream>
using namespace std;
class queue
{
public:
    queue(int capacity=20001)
    {
        array=new int [capacity];
        maxsize=capacity;
        currentsize=0;
    }
    ~queue()
    {
        delete[]array;
    }
    bool isempty() const
    {
        return currentsize==0;
    }
    void enqueue(const int&x)
    {
        if(currentsize==maxsize-1)
            doublespace();

        int hole=++currentsize;
        for(; hole>1&&x<array[hole/2]; hole/=2)
            array[hole]=array[hole/2];
        array[hole]=x;
    }
    void dequeue()
    {
        array[1]=array[currentsize--];
        percolatedown(1);
        return;
    }
    void percolatedown(int hole)
    {
        int child;
        int tmp=array[hole];

        for(; hole*2<=currentsize; hole=child)
        {
            child=hole*2;
            if(child!=currentsize&&array[child+1]<array[child])
                child++;
            if(array[child]<tmp)
                array[hole]=array[child];
            else
                break;
        }
        array[hole]=tmp;
    }
    int find(int x)
    {
        int tar=1,num=0;
        for(int i=1; i<=currentsize; i++)
        {
            if(array[i]>x&&num==0)
            {
                tar=i;
                num++;
            }
            if(array[i]>x&&array[i]<array[tar])
                tar=i;
        }
        return tar;
    }
    void d(int a,int b)
    {
        array[a]-=b;
        buildheap();
    }
public:
    int currentsize;
    int *array;
    int maxsize;
    void doublespace()
    {
        int *tmp=array;
        maxsize*=2;
        array=new int [maxsize];
        for(int i=0; i<=currentsize; ++i)
            array[i]=tmp[i];
        delete[]tmp;
    }
    void buildheap()
    {
        for(int i=currentsize/2; i>0; i--)
            percolatedown(i);
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    queue q;
    int m,x,i=0,y;
    char c[7];
    cin>>m;
    cin.get();
    while(i<m)
    {
        cin>>c;
        if(c[0]=='i')
        {
            cin>>x;
            q.enqueue(x);
        }
        if(c[0]=='f')
        {
            int min = 2000000000;
            cin >> x;
            for (int j = 1; j <= q.currentsize; j++)
                if (q.array[j] > x&&q.array[j]<min)
                {
                    min = q.array[j];
                    y = j;
                }
            cout << y<<'\n';
        }
        if(c[0]=='d')
        {
            cin>>x>>y;
            q.d(x,y);
        }
        i++;
    }
    return 0;
}
