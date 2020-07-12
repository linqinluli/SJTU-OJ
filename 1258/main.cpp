#include<iostream>
using namespace std;

long int merge(long int a[],int left,int mid,int right)
{
    int *tmp=new int[right-left+1];

    long int num=0,c;

    int i=left,j=mid,k=0;

    while(i<mid&&j<=right)
        if(a[i]<a[j])
            tmp[k++]=a[i++];
        else if(a[i]>a[j])
        {
            tmp[k++]=a[j++];
            num+=(mid-i);
        }
        else
        {
            tmp[k++]=a[j++];
            for(c=i; c<mid-1&&a[c]==a[c+1]; c++);
            num+=(mid-c-1);
        }
    while(i<mid)
        tmp[k++]=a[i++];
    while(j<=right)
        tmp[k++]=a[j++];

    for(i=0,k=left; k<=right;)
        a[k++]=tmp[i++];
    delete [] tmp;
    return num;
}
long int mergesort(long int a[],int left,int right)
{
    int mid=(left+right)/2;

    long int count=0;
    if(left==right)
        return 0;
    count+=mergesort(a,left,mid);
    count+=mergesort(a,mid+1,right);
    count+=merge(a,left,mid+1,right);
    return count;
}
long int mergesort(long int a[],int size)
{
    return mergesort(a,0,size-1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long int n;
    long int a[200000];
    cin>>n;
    for(int i=0; i<n; i++)
        cin>>a[i];
    cout<<mergesort(a,n);
    return 0;

}
