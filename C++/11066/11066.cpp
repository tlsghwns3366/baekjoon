#include <iostream>
using namespace std;
int f(int a, int b)
{
    return a > b ? b : a;
}
int main()
{
    int t;
    cin >> t;
    for (int q = 0; q < t; q++)
    {
        int k;
        cin >> k;
        int dp[k][k];
        int sum[k][k];
        for (int i = 0; i < k; i++)
        {
            for (int j = 0; j < k; j++)
            {
                dp[i][j] = 987654321;
                sum[i][j] = 987654321;
            }
        }
        for (int i = 0; i < k; i++)
        {
            cin >> sum[0][i];
            dp[0][i] = 0;
            if (i > 0)
            {
                for (int j = 0; j < i; j++)
                {
                    sum[i - j][j] = sum[i - j - 1][j] + sum[0][i];
                }
            }
        }
        for (int i = 1; i < k; i++)
        {
            for (int j = 0; j < k - i; j++)
            {
                if (j + i < k)
                {
                    for (int l = 0; i + l < k && l < i; l++)
                    {
                        if (l == 0)
                            dp[i + l][j] = f(dp[i + l][j], (dp[i - 1][j] + sum[i + l][j]));
                        else
                            dp[i + l][j] = f(dp[i + l][j], (dp[i - 1][j] + dp[l][j + i] + sum[i + l][j]));
                    }
                }
                if (j > 0)
                {
                    for (int l = 1; l <= i && i + l < k; l++)
                    {
                        dp[i + l][j - l] = f(dp[i + l][j - l], dp[i][j] + dp[l - 1][j - l] + sum[i + l][j - l]);
                    }
                }
            }
        }
        cout << dp[k - 1][0] << endl;
    }
}