#include <iostream>
#include <algorithm>
using namespace std;
int dp[101][10001];
int main()
{
    int n, m;
    cin >> n >> m;
    int a[n + 1];
    int b[n + 1];
    int ans = 987654321;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= 10000; j++)
        {
            if (b[i] <= j)
            {
                dp[i][j] = dp[i - 1][j] > dp[i - 1][j - b[i]] + a[i] ? dp[i - 1][j] : dp[i - 1][j - b[i]] + a[i];
            }
            else
                dp[i][j] = dp[i - 1][j];

            if (dp[i][j] >= m)
            {
                ans = ans < j ? ans : j;
            }
        }
    }
    cout << ans;
}