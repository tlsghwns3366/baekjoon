#include <iostream>
#include <algorithm>
using namespace std;
int nn[101];
int dp[101][52];
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        int temp;
        cin >> temp;
        nn[i] = nn[i - 1] + temp;
    }
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            dp[i][j] = -987654321;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            dp[i][j] = dp[i - 1][j];
            for (int k = i - 1; k / 2 >= j - 1; k--)
            {
                dp[i][j] = max(dp[i][j], (j == 1 ? 0 : dp[k - 1][j - 1]) + nn[i] - nn[k]);
            }
        }
    }
    cout << dp[n][m];
}