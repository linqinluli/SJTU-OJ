#include <iostream>
using namespace std;
int mapb[1000][1000];
int mapa[1000][1000];
int main()
{
    int length, width;
    cin>>length>>width;

    for(int i=0; i<length; i++)
        for(int j=0; j<width; j++)
        {
            cin>>mapa[i][j];
        }

    int alength,awidth;
    cin>>alength>>awidth;

    for(int i=0; i<alength; i++)
        for(int j=0; j<awidth; j++)
        {
            mapb[i][j]=0;
        }
    int max=0;
    for(int i=0; i<length-alength+1; i++)
        for(int j=0; j<width-awidth+1; j++)
        {
            for(int m=0; m<alength; m++)
                for(int n=0; n<awidth; n++)
                    mapb[i][j]+=mapa[i+m][j+n];
            if( mapb[i/alength][j/awidth]>=max)
                max=mapb[i/alength][j/awidth];
        }
    cout<<max;
    return 0;
}
