#include <iostream>
using namespace std;
int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    int nm[n + 1][m + 1];
    int dp[n + 1][m + 1];
    int c = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            nm[i][j] = c;
            c++;
        }
    }
    fill(&dp[0][0], &dp[n][m], 0);
    dp[1][1] = 1;
    if (k == 0)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (i == 1 && j == 1)
                    continue;
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
    }
    else
    {
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (i == 1 && j == 1)
                    continue;
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                if (nm[i][j] == k)
                {
                    ans = dp[i][j];
                    fill(&dp[0][0], &dp[n][m], 0);
                    dp[i][j] = 1;
                    for (int ii = i; ii <= n; ii++)
                    {
                        for (int jj = j; jj <= m; jj++)
                        {
                            if (ii == i && jj == j)
                                continue;
                            dp[ii][jj] = dp[ii - 1][jj] + dp[ii][jj - 1];
                        }
                    }
                    i = n + 1;
                    break;
                }
            }
        }
        dp[n][m] *= ans;
    }
    cout << dp[n][m];
}