#include <iostream>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    int **dp = new int *[n + 1];
    for (int i = 0; i <= n; i++)
    {
        dp[i] = new int[k + 1]{0};
    }
    for (int i = 1; i <= n; i++)
    {
        dp[i][0] = 1;
    }

    for (int i = 1; i <= k; i++)
    {
        for (int j = i; j <= n; j++)
        {
            if (i == j)
                dp[j][i] = 1;
            else
            {
                dp[j][i] = (dp[j - 1][i - 1] + dp[j - 1][i]) % 10007;
            }
        }
    }
    cout << dp[n][k];
}