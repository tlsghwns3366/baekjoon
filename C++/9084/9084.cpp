#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int ts = 0; ts < t; ts++)
    {
        int n, m;
        cin >> n;
        int nn[n];
        for (int i = 0; i < n; i++)
        {
            cin >> nn[i];
        }
        cin >> m;
        int dp[10001];
        fill(dp, dp + 10001, 0);
        dp[0] = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = nn[i]; j <= m; j++)
            {
                dp[j] = dp[j] + dp[j - nn[i]];
            }
        }
        cout << dp[m] << "\n";
    }
}