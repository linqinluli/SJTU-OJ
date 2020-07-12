#include <iostream>
#include<cstring>

using namespace std;

class balance
{
public:
    int top;
    int stack[4000];
    balance()
    {
        top=-1;
    }
    bool isempty()const
    {
        return top==-1;
    }
    void push(int x)
    {
        top++;
        stack[top]=x;
    }

    void pop()
    {
        top--;
    }

};
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    balance p;
    char a[100];
    while(cin>>a)
    {
        if(strcmp(a,"begin")==0)
            p.push(1);
        if(strcmp(a,"end")==0)
        {
            while(p.stack[p.top]==3)
                p.pop();
        }
        if(strcmp(a,"end")==0&&p.stack[p.top]==1)
            p.pop();
        else if(strcmp(a,"end")==0&&p.top==-1)
        {
            cout<<"Error!";
            return 0;
        }
        if(strcmp(a,"if")==0)
            p.push(2);
        if(strcmp(a,"then")==0&&p.stack[p.top]==2)
            p.stack[p.top]=3;
        else if(strcmp(a,"then")==0&&p.stack[p.top]!=2)
        {
            cout<<"Error!";
            return 0;
        }
        if(strcmp(a,"else")==0&&p.stack[p.top]==3)
            p.pop();
        else if(strcmp(a,"else")==0&&p.stack[p.top]!=3)
        {
            cout<<"Error!";
            return 0;
        }
    }
    while(p.stack[p.top]==3)
        p.pop();
    if(p.isempty())
        cout<<"Match!";
    else
        cout<<"Error!";
    return 0;
}

