#include <iostream>
using namespace std;
int dx[3] = {-1, 0, -1};
int dy[3] = {0, -1, -1};
int f(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}
int main()
{
    int n, m;
    cin >> n >> m;
    int nm[n][m];
    int dd[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> nm[i][j];
            dd[i][j] = 0;
        }
    }
    dd[0][0] = nm[0][0];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            dd[i][j] = nm[i][j];
            for (int k = 0; k < 3; k++)
            {
                if (i + dx[k] >= 0 && j + dy[k] >= 0)
                {
                    dd[i][j] = f(dd[i + dx[k]][j + dy[k]] + nm[i][j], dd[i][j]);
                }
            }
        }
    }
    cout << dd[n - 1][m - 1];
}