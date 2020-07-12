#include <iostream>
#include <cmath>
using namespace std;

int length[15][15];
int abc[15][32768];
int n;
int count(int num)
{
    int answer = 0;
    while (num)
    {
        num = num & (num - 1);
        answer++;
    }
    return answer;
}
int get(int cur, int state)
{
    if (abc[cur][state] > -1)
        return abc[cur][state];
    if (count(state) == 2)
        return abc[cur][state] = length[cur][0];
    int t = 2; //不算出发点
    unsigned int mini = -1;
    int tem;
    for (int i = 1; i < n; ++i, t <<= 1)
    {
        if (i == cur)
            continue;
        if (state & t)
        {
            tem = get(i, state & (~(1 << cur))) + length[i][cur];
            if (tem < mini)
                mini = tem;
        }
    }
    return abc[cur][state] = mini;
}

int main()
{
    cin >> n;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> length[i][j];
    int num = pow(2, n);
    if (n == 1)
    {
        cout << 0;
        return 0;
    }
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < pow(2, n); ++j)
            abc[i][j] = -1;
    abc[0][1] = 0;
    unsigned int _min =-1;
    for (int i = 1; i < n; ++i)
    {
        int tmp = length[0][i] + get(i, num - 1);
        if (tmp < _min)
            _min = tmp;
    }
    cout << _min;

    return 0;
}
