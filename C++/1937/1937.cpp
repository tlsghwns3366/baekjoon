#include <iostream>
using namespace std;
int n;
int **nn;
int **bb;
int nx[4] = {-1, 0, 1, 0};
int ny[4] = {0, 1, 0, -1};
int ans;
int ab(int a,int b)
{
    if(a<b)
        return b;
    else
        return a;
}
int f(int a, int b)
{
    if(bb[a][b] != 1)
    {
        return bb[a][b];
    }
    for (int i = 0; i < 4; i++)
    {
        if (a + nx[i] >= 0 && a + nx[i] < n && b + ny[i] >= 0 && b + ny[i] < n)
        {
            if (nn[a + nx[i]][b + ny[i]] > nn[a][b])
            {
                bb[a][b] = ab(bb[a][b],1+f(a + nx[i], b + ny[i]));
            }
        }
    }
    if (ans < bb[a][b])
        ans = bb[a][b];

    return bb[a][b];
}
int main()
{
    cin >> n;
    nn = new int *[n];
    bb = new int *[n];
    for (int i = 0; i < n; i++)
    {
        nn[i] = new int[n];
        bb[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            cin >> nn[i][j];
            bb[i][j] = 1;
        }
    }

    for (int x = 0; x < n; x++)
    {
        for (int y = 0; y < n; y++)
        {
            if (bb[x][y] == 1)
            {
                f(x, y);
            }
        }
    }
    cout << ans;
}