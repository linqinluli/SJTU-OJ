#include<iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int a[250000]= {0};
    int n,i,j,max=0;
    cin>>n;
    cin.get();
    char b[7];
    while(true)
    {
        cin>>b;
        if(b[0]=='a')
        {
            cin>>i>>j;
            a[j]++;
            if(a[j]>a[max])
                max=j;
            else if(a[j]==a[max])
                max=(j>max)?max:j;
        }
        if(b[0]=='q')
        {
            cout<<max<<' '<<a[max]<<'\n';
        }
        if(b[0]=='f')
            break;
    }
    return 0;
}
