#include <iostream>
using namespace std;
int f(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}
int main()
{
    int n;
    cin >> n;
    int nn[n];
    int dp[n];
    fill(dp, dp + n, 1);
    for (int i = 0; i < n; i++)
    {
        cin >> nn[i];
    }
    int ans = dp[0];
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (nn[i] > nn[j] && dp[i] < dp[j] + 1)
                dp[i] = dp[j] + 1;
        }
        if (ans < dp[i])
            ans = dp[i];
    }
    cout << ans;
}