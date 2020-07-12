#include <iostream>

using namespace std;

int percolatedown(int a[],int hole,int size)
{
    int child;
    int tmp=a[hole];
    int count=0;

    for(; hole*2+1<size; hole=child)
    {
        child=hole*2+1;
        if(child!=size-1&&a[child+1]>a[child])
        {
            child++;
            count++:
        }
        if(a[child]>tmp)
        {
            a[hole]=a[child];
            count++;
        }
        else
            break;
    }
    a[hole]=tmp;
}
void heapsort(int a[],int size)
{
    int i;
    int tmp;
    int c=0;
    for(i=size/2-1; i>=0; i--)
        c+=percolatedown(a,i,size);

    for(i=size-1; i>0; --i)
    {
        tmp=a[0];
        a[0]=a[i];
        a[i]=tmp;
        c+=percolatedown(a,0,i);
    }
    cout<<c;
}

int merge(int a[],int left,int mid,int right)
{
    int *tmp=new int[right-left+1];

    int i=left,j=mid,k=0,count=0;

    while(i<mid&&j<=right)
        if(a[i]<a[j])
        {
            tmp[k++]=a[i++];
            count++;
        }
        else
        {
            tmp[k++]=a[j++];
            count++;
        }

    while(i<mid)
        tmp[k++]=a[i++];
    while(j<=right)
        tmp[k++]=a[j++];

    for(i=0,k=left; k<=right;)
        a[k++]=tmp[i++];
    delete [] tmp;
    return count;
}
int mergesort(int a[],int left,int right)
{
    int mid=(left+right)/2;
    int c=0;

    if(left==right)
        return c;
    c+=mergesort(a,left,mid);
    c+=mergesort(a,mid+1,right);
    c+=merge(a,left,mid+1,right);
    return c;
}
int mergesort(int a[],int size)
{
    return mergesort(a,0,size-1);
}
int divide(int a[], int low, int high)
{
    int k=a[low];;
    do
    {
        while(low<high&&a[high]>=k)
            --high;
        if(low<high)
        {
            a[low]=a[high];
            ++low;
        }
        while(low<high&&a[low]<=k)
            ++low;
        if(low<high)
        {
            a[high]=a[low];
            --high;
        }
    }
    while(low!=high);
    a[low]=k;
    return low;
}
void quickSort(int a[], int low, int high)
{
    int mid;
    if(low>=high)
        return;
    mid=divide(a,low,high);
    quickSort(a,low,mid-1);
    quickSort(a,mid+1,high);
}
int main()
{
    int size,kind,*a,n;
    cin>>size>>kind;
    a=new int[size];
    for(int i=0; i<size; i++)
        cin>>a[i];
    switch(kind)
    {
    case 1:
        heapsort(a,size);
        break;
    case 2:
        n=mergesort(a,size);
        cout<<n;
        break;
    case 3:
        quickSort(a,0,size);
        break;
    }
    return 0;
}
