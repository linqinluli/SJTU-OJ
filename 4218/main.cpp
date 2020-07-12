#include <iostream>

using namespace std;

const int N=5000000;
int p[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,d,count=0;
    cin>>n>>d;
    for(int i=0; i<n; i++)
        cin>>p[i];
    for(int i=0; i<n; i++)
        for(int j=1; j<=d; j++)
        {
            if(i+j<n&&(p[i]*2<p[i+j]||[i]*2>p[i+j]))
            {
                count++;
                break;
            }
        }
    cout<<count;
    return 0;
}
