#include <iostream>
using namespace std;
int dp[501][501];
int xy[501][501][2];
int main()
{
    int n;
    cin >> n;
    int nx[n];
    int ny[n];
    for (int i = 0; i < n; i++)
    {
        cin >> xy[1][i][0] >> xy[1][i][1];
        dp[1][i] = 0;
    }
    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 2 && j < n - 1)
            {
                dp[i][j] = xy[1][j][0] * xy[1][j][1] * xy[1][j + 1][1];
                xy[i][j][0] = xy[1][j][0];
                xy[i][j][1] = xy[1][j + 1][1];
            }
            else
            {
                dp[i][j] = 987654321;
                xy[i][j][0] = 987654321;
                xy[i][j][1] = 987654321;
            }
        }
    }
    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j + i < n; j++)
        {
            for (int k = 1; k <= i; k++)
            {
                if (i + k > n)
                    break;
                if (dp[i + k][j] > dp[i][j] + dp[k][j + i] + (xy[i][j][0] * xy[i][j][1] * xy[k][j + i][1]))
                {
                    dp[i + k][j] = dp[i][j] + dp[k][j + i] + (xy[i][j][0] * xy[i][j][1] * xy[k][j + i][1]);
                    xy[i + k][j][0] = xy[i][j][0];
                    xy[i + k][j][1] = xy[k][j + i][1];
                }
            }
            for (int k = 1; k <= i; k++)
            {
                if (j - k < 0 || i + k < n)
                    break;
                if (dp[i + k][j - k] > dp[i][j] + dp[k][j - k] + (xy[i][j][0] * xy[i][j][1] * xy[k][j - k][0]))
                {
                    dp[i + k][j - k] = dp[i][j] + dp[k][j - k] + (xy[i][j][0] * xy[i][j][1] * xy[k][j - k][0]);
                    xy[i + k][j - k][0] = xy[k][j - k][0];
                    xy[i + k][j - k][1] = xy[i][j][1];
                }
            }
        }
    }
    cout << dp[n][0];
}