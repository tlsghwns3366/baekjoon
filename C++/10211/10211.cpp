#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
int main()
{
    int t;
    cin >> t;
    for (int q = 0; q < t; q++)
    {
        int n;
        cin >> n;
        int nn[n];
        int dp[n];
        fill(dp, dp + n, 0);
        for (int i = 0; i < n; i++)
        {
            cin >> nn[i];
        }
        int ans = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            dp[i] = max(0, dp[i - 1]) + nn[i];
            ans = max(ans, dp[i]);
        }
        cout << ans << endl;
    }
}