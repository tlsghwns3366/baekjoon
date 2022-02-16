#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int dp[n + 1];
    fill(dp, dp + n + 1, 0);
    dp[0] = 1;
    dp[2] = 3;
    for (int i = 4; i <= n; i += 2)
    {
        dp[i] += dp[i - 2] * 3;
        for (int j = 4; j <= i; j += 2)
        {
            dp[i] += dp[i - j] * 2;
        }
    }
    cout << dp[n];
}