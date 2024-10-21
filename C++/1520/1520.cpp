#include <iostream>
using namespace std;
int n, m;
int nm[501][501];
int dp[501][501];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

int dfs(int x, int y)
{
    if (x == n - 1 && y == m - 1)
        return 1;
    if (dp[x][y] != -1)
        return dp[x][y];
    dp[x][y] = 0;
    for (int i = 0; i < 4; i++)
    {
        int ddx = x + dx[i];
        int ddy = y + dy[i];
        if (ddx >= 0 && ddx < n && ddy >= 0 && ddy < m)
        {
            if (nm[ddx][ddy] < nm[x][y])
                dp[x][y] += dfs(ddx, ddy);
        }
    }
    return dp[x][y];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> nm[i][j];
            dp[i][j] = -1;
        }
    }
    dfs(0, 0);
    cout << dp[0][0];
}