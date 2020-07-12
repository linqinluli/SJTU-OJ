#include <iostream>

using namespace std;

class queue
{
public:
    queue(int capacity=100)
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
    int gethead() const
    {
        return array[1];
    }
private:
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
    queue q;
    int m,x,i=0;
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
        if(c[0]=='d')
        {
            q.dequeue();
        }
        if(c[0]=='m')
        {
            cout<<q.gethead()<<'\n';
        }
        i++;
    }

    return 0;
}
