#include<iostream>
using namespace std;
int main()
{
    int height_pepople,height_stool,num;
    cin>>height_pepople>>height_stool>>num;
    int height;
    int count=0;

    for(int i=0;i<num;i++)
    {
        cin>>height;
        if(height_pepople+height_stool>=height)
            count++;
    }cout<<count;
    return 0;

}
