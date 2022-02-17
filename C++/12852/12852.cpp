#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int dp[1000001];
int ans[1000001];
int main()
{
    int n;
    cin >> n;
    dp[2] = 1;
    ans[2] = 1;
    dp[3] = 1;
    ans[3] = 1;
    for (int i = 4; i <= n; i++)
    {
        dp[i] = dp[i - 1] + 1;
        ans[i] = i - 1;
        if (i % 2 == 0)
        {
            if (dp[i / 2] + 1 < dp[i])
            {
                dp[i] = dp[i / 2] + 1;
                ans[i] = i / 2;
            }
        }
        if (i % 3 == 0)
        {
            if (dp[i / 3] + 1 < dp[i])
            {
                dp[i] = dp[i / 3] + 1;
                ans[i] = i / 3;
            }
        }
    }
    cout << dp[n] << "\n";
    cout << n << " ";
    while (n != 1)
    {
        cout << ans[n] << " ";
        n = ans[n];
    }
}