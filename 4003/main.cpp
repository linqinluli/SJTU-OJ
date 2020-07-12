#include <iostream>

using namespace std;

int zhuanhua(int a[],int length)
{
    int count=0,re=1;
    for(int i=length-1;i>=0;i--)
    {
        count+=re*a[i];
        re*=2;
    }
    return count;
}
int main()
{
    long int n,m,num=0,re=1;
    int k,count=0;
    int i=0,j=0,c=0,q=0;
    int a[30]= {0},b[30]= {0};
    int f[30]={0},g[30]={0},length1;
    cin>>n>>k;
    m=n;
    if(n<=k)
        cout<<k-n;
    while(m!=0)
    {
        if(m%2==1)
        {
            a[i]=1;
            b[q]=i;
            q++;
        }
        m/=2;
        i++;
    }
    for(j=0; j<=i; j++)
        count+=a[j];
    if(k>=count)
        cout<<0;
    else
    {
        if(q==1)
        {
            for(int r=0; r<b[0]; r++)
                re*=2;
            cout<<re;
        }
        else
        {
            f[0]=1;
            length1=b[q-k];
            for(j=0,i=b[q-k]-2;j<b[q-k]-1;j++,i--)
                g[j]=a[i];
            cout<<zhuanhua(f,length1)-zhuanhua(g,length1-1);
        }
    }

    return 0;
}
