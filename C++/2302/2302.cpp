#include <iostream>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    int dp[n + 1];
    dp[0] = 1;
    dp[1] = 1;
    bool vip[n + 1];
    fill(vip, vip + n + 1, false);
    for (int i = 0; i < m; i++)
    {
        int a;
        cin >> a;
        vip[a] = true;
    }
    for (int i = 2; i <= n; i++)
    {
        if (vip[i])
            dp[i] = dp[i - 1];
        else if (vip[i - 1])
            dp[i] = dp[i - 1];
        else
            dp[i] = dp[i - 1] + dp[i - 2];
    }
    cout << dp[n];
}