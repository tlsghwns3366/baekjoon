#include <iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    int ti[n + 1];
    int pi[n + 1];
    int dp[n + 1];
    int m = 0;
    fill(dp, dp + n + 1, 0);
    fill(ti, ti + n + 1, 0);
    fill(pi, pi + n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> ti[i] >> pi[i];
    }
    dp[ti[0]] = pi[0];
    for (int i = 1; i <= n; i++)
    {
        m = max(m, dp[i]);
        if (i + ti[i] <= n)
        {
            dp[i + ti[i]] = max(dp[i + ti[i]], m + pi[i]);
        }
    }
    cout << m;
}