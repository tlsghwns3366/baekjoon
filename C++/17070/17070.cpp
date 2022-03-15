#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int nn[n][n];
    int dp[n][n][3];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> nn[i][j];
            dp[i][j][0] = 0;
            dp[i][j][1] = 0;
            dp[i][j][2] = 0;
        }
    }
    dp[0][1][0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (dp[i][j][0] != 0)
            {
                if (j + 1 < n)
                {
                    if (nn[i][j + 1] != 1)
                        dp[i][j + 1][0] += dp[i][j][0];
                }
                if (j + 1 < n && i + 1 < n)
                {
                    if (nn[i][j + 1] != 1 && nn[i + 1][j + 1] != 1 && nn[i + 1][j] != 1)
                        dp[i + 1][j + 1][1] += dp[i][j][0];
                }
            }
            if (dp[i][j][1] != 0)
            {
                if (j + 1 < n)
                {
                    if (nn[i][j + 1] != 1)
                        dp[i][j + 1][0] += dp[i][j][1];
                }
                if (j + 1 < n && i + 1 < n)
                {
                    if (nn[i][j + 1] != 1 && nn[i + 1][j + 1] != 1 && nn[i + 1][j] != 1)
                        dp[i + 1][j + 1][1] += dp[i][j][1];
                }
                if (i + 1 < n)
                {
                    if (nn[i + 1][j] != 1)
                        dp[i + 1][j][2] += dp[i][j][1];
                }
            }
            if (dp[i][j][2] != 0)
            {
                if (j + 1 < n && i + 1 < n)
                {
                    if (nn[i][j + 1] != 1 && nn[i + 1][j + 1] != 1 && nn[i + 1][j] != 1)
                        dp[i + 1][j + 1][1] += dp[i][j][2];
                }
                if (i + 1 < n)
                {
                    if (nn[i + 1][j] != 1)
                        dp[i + 1][j][2] += dp[i][j][2];
                }
            }
        }
    }
    cout << dp[n - 1][n - 1][0] + dp[n - 1][n - 1][1] + dp[n - 1][n - 1][2];
}