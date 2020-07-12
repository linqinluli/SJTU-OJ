#include <iostream>
using namespace std;

const int N=500000;
char names[N][30];
int h[N],result[N],sstack[N];

int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>h[i];
        cin.get();
        cin.getline(names[i],30);
    }

    for(int i=0; i<n; ++i)
        result[i]=-1;

    int top=-1;
    for(int i=0; i<n; i++)
    {
        while(top>=0&&h[sstack[top]]<h[i])
        {
            result[sstack[top]]=i;
            --top;
        }
        sstack[++top]=i;
    }

    for(int i=0; i<n; ++i)
    {
        if(result[i]==-1)
        {
            cout<<"-1\n";
        }
        else
        {
            cout<<names[result[i]]<<'\n';
        }
    }
    return 0;
}
