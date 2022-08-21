#include <iostream>
using namespace std;

int nn[1000][1000];
int dp[1000][1000][3];
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> nn[i][j];
            if (i == 0)
                dp[i][j][0] = dp[i][j][1] = dp[i][j][2] = nn[i][j];
            else
                dp[i][j][0] = dp[i][j][1] = dp[i][j][2] = 987654321;
        }
    }
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (dp[i][j][0] != 987654321)
            {
                dp[i + 1][j][1] = dp[i + 1][j][1] < dp[i][j][0] + nn[i + 1][j] ? dp[i + 1][j][1] : dp[i][j][0] + nn[i + 1][j];
                if (j + 1 < m)
                {
                    dp[i + 1][j + 1][2] = dp[i + 1][j + 1][2] < dp[i][j][0] + nn[i + 1][j + 1] ? dp[i + 1][j + 1][2] : dp[i][j][0] + nn[i + 1][j + 1];
                }
            }
            if (dp[i][j][1] != 987654321)
            {
                if (j - 1 >= 0)
                {
                    dp[i + 1][j - 1][0] = dp[i + 1][j - 1][0] < dp[i][j][1] + nn[i + 1][j - 1] ? dp[i + 1][j - 1][0] : dp[i][j][1] + nn[i + 1][j - 1];
                }
                if (j + 1 < m)
                {
                    dp[i + 1][j + 1][2] = dp[i + 1][j + 1][2] < dp[i][j][1] + nn[i + 1][j + 1] ? dp[i + 1][j + 1][2] : dp[i][j][1] + nn[i + 1][j + 1];
                }
            }
            if (dp[i][j][2] != 987654321)
            {
                dp[i + 1][j][1] = dp[i + 1][j][1] < dp[i][j][2] + nn[i + 1][j] ? dp[i + 1][j][1] : dp[i][j][2] + nn[i + 1][j];
                if (j - 1 >= 0)
                {
                    dp[i + 1][j - 1][0] = dp[i + 1][j - 1][0] < dp[i][j][2] + nn[i + 1][j - 1] ? dp[i + 1][j - 1][0] : dp[i][j][2] + nn[i + 1][j - 1];
                }
            }
        }
    }
    int ans = 987654321;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            ans = ans < dp[n - 1][i][j] ? ans : dp[n - 1][i][j];
        }
    }
    cout << ans;
}