#include <iostream>
using namespace std;
int n, m;
int dp[1001][1001];
int main()
{
    int ans = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++)
        {
            dp[i][j] = s[j] - '0';
            ans = ans < dp[i][j] ? dp[i][j] : ans;
        }
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (dp[i - 1][j - 1] != 0 && dp[i - 1][j] != 0 && dp[i][j - 1] != 0 && dp[i][j] != 0)
                dp[i][j] = min(min(dp[i - 1][j - 1], dp[i - 1][j]), dp[i][j - 1]) + 1;
            ans = ans < dp[i][j] ? dp[i][j] : ans;
        }
    }
    cout << ans * ans;
}