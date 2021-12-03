#include <iostream>
#include <climits>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int dp[100000 + 1];
    fill(dp, dp + 100001, INT_MAX);
    for (int i = 1; i * i <= n; i++)
    {
        for (int j = 1; j * (i * i) <= n; j++)
        {
            dp[j * (i * i)] = j;
        }
    }
    dp[2] = 2;
    dp[3] = 3;
    for (int i = 4; i <= n; i++)
    {
        if (dp[i] == 1)
        {
            for (int j = 1; j <= i; j++)
            {
                if (i + j > n)
                    break;
                if (dp[i + j] > dp[i] + dp[j])
                    dp[i + j] = dp[i] + dp[j];
            }
        }
    }
    cout << dp[n];
}