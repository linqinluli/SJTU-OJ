#include<iostream>
using namespace std;
template<class T>
class list
{
public:
    int num;
    T*data;
public:
    list operator+(const list &n1)
    {
        list tmp(n1.num+num);
        for(int i=0; i<num; i++)
            tmp.data[i]=data[i];
        for(int i=0; i<n1.num; i++)
            tmp.data[i+num]=n1.data[i];
        return tmp;
    }
    list(int a=0)
    {
        num=a;
        data=new T[num];
    }
    void output()
    {
        for(int i=0; i<num; i++)
            cout<<data[i]<<" ";
            return;
    }
    void input()
    {
        for(int i=0; i<num; i++)
           cin>>data[i];
            return;
    }
    ~list()
    {
        delete [] data;
    }
};
int main()
{
    int n,m;
    char a[7];
 cin.getline(a,7);
   cin>>m>>n;
    cin.get();
    if(a[0]=='i')
        {list<int>n1(n),n2(m);
        n1.input();
        n2.input();
        (n1+n2).output();
        }
    else if(a[0]=='d')
        {list<double>n1(n),n2(m);
        n1.input();
        n2.input();
        (n1+n2).output();
        }
    else if(a[0]=='c')
        {list<char>n1(n),n2(m);
        n1.input();
        n2.input();
        (n1+n2).output();
        }
    cin>>m>>n;
    return 0;
}
