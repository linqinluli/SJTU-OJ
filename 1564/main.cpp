#include <iostream>
using namespace std;

int ans;
int map[6][6];
int stax , stay ,ex, ey;
int dir[4][2] ={ { 0, 1 }, { 1, 0 },{ 0, -1 }, { -1, 0 } };
bool vis[6][6];

void dfs(int x , int  y  , int sum , int statu)
{
    if(sum < ans)
    {
        if(x == ex && y == ey)
        {
            ans = sum ;
            return ;
        }else{
            for (int i = 0; i < 4; i++)
            {
                int tempx = x + dir[i][0];
                int tempy = y + dir[i][1];
                if ( !vis[tempx][tempy] && tempx >= 0 && tempx < 6 && tempy >= 0 && tempy < 6)
                {
                    int cost = statu * map[tempx][tempy];
                    int sum2 = sum + cost;
                    int statu2 = cost % 4 + 1;
                    vis[tempx][tempy] = true ;
                    dfs(tempx , tempy , sum2 , statu2);
                    vis[tempx][tempy] = false ;
                }
            }
        }
    }
}
int main()
{
    int k;
    cin >> k;
    while (k--)
    {
        for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < 6; j++)
            {
                cin >> map[i][j];
                vis[i][j] = false;
            }
        }
        ans = 999999999;
        cin >> stax >> stay >> ex >> ey;
        dfs(stax , stay , 0 , 1);
        cout<<ans<<'\n';
    }
    return 0;
}
