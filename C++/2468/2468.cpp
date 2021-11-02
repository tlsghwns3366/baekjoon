#include <iostream>
using namespace std;
bool **bb;
int nx[4] = {-1, 0, 1, 0};
int ny[4] = {0, 1, 0, -1};
int n;
void f(int a, int b)
{
    bb[a][b] = true;
    for (int i = 0; i < 4; i++)
    {
        if (a + nx[i] >= 0 && a + nx[i] < n && b + ny[i] >= 0 && b + ny[i] < n)
        {
            if (bb[a + nx[i]][b + ny[i]] == false)
            {
                f(a + nx[i], b + ny[i]);
            }
        }
    }
}
int main()
{
    cin >> n;
    int nn[n][n];
    bb = new bool *[n];
    int temp = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> nn[i][j];
            if (temp < nn[i][j])
                temp = nn[i][j];
        }
    }
    int s = 0;
    for (int i = 0; i <= temp; i++)
    {
        int ans = 0;
        for (int x = 0; x < n; x++)
        {
            bb[x] = new bool[n];
            for (int y = 0; y < n; y++)
            {
                if (nn[x][y] <= i)
                    bb[x][y] = true;
                else
                    bb[x][y] = false;
            }
        }
        for (int x = 0; x < n; x++)
        {
            for (int y = 0; y < n; y++)
            {
                if (bb[x][y] == false)
                {
                    ans++;
                    f(x, y);
                }
            }
        }
        if (s < ans)
            s = ans;
    }
    cout << s;
}