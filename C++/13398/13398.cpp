#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int nn[100001];
    int dp[100001][2];
    for (int i = 0; i < n; i++)
    {
        cin >> nn[i];
    }
    dp[0][0] = nn[0];
    dp[0][1] = 0;
    int ans = nn[0];
    for (int i = 1; i < n; i++)
    {
        dp[i][0] = max(dp[i - 1][0] + nn[i], nn[i]);
        dp[i][1] = max(dp[i - 1][1] + nn[i], dp[i - 1][0]);
        ans = max(ans, max(dp[i][0], dp[i][1]));
    }
    cout << ans;
}