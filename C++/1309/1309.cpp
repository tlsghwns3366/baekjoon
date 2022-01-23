#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int dp[n + 1];
    fill(dp, dp + n + 1, 0);
    dp[0] = 1;
    dp[1] = 3;
    for (int i = 1; i <= n; i++)
    {
        dp[i + 1] = (dp[i] * 2 + dp[i - 1]) % 9901;
    }
    cout << dp[n];
}