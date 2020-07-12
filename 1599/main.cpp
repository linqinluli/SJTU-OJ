#include <iostream>

using namespace std;

class balance
{
public:
    int top;
    char a[1000000];
    balance()
    {
        top=-1;
    }
    bool isempty() const
    {
        return top==-1;
    }
    void push(const char&x)
    {
        a[++top]=x;
    }
    void pop()
    {
        if(top==-1)
            return ;
        top--;
    }
    void showtop()
    {
        if(top==-1)
            return ;
        else
            cout<<a[top]<<'\n';;
    }
    void checkbalance()
    {
        int top1=0;
        if(top==-1)
        {
            cout<<"YES"<<'\n';
            return;
        }

        char match[1000000];
        match[-1]='1';
        for(int i=0; i<=top; ++i)
        {

            match[top1]=a[i];
            if(top1==0)  	 ;
            else if(check(match[top1-1],match[top1]))
                top1=top1-2;
            ++top1;

        }
        if(top1==0)
            cout<<"YES"<<'\n';
        else
            cout<<"NO"<<'\n';

    }

    bool check(char x1,char x2)
    {
        if(x1=='('&&x2==')')
            return true;
        else if(x1=='['&&x2==']')
            return true;
        else if(x1=='{'&&x2=='}')
            return true;
        else
            return false;
    }


};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    char c[81];
    balance b;
    int m=0;
    cin>>n;
    cin.get();
    for(int j=0; j<n; j++)
    {
        cin.getline(c,81);
        if(c[0]=='1')
        {
            while(c[m]!='('&&c[m]!='{'&&c[m]!='['&&c[m]!='}'&&c[m]!=']'&&c[m]!=')')
                m++;
            b.push(c[m]);
            m=0;
        }
        if(c[0]=='2')
            b.pop();
        if(c[0]=='3')
            b.showtop();
        if(c[0]=='4')
            b.checkbalance();
    }
    return 0;
}
