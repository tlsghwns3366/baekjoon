#include <iostream>
using namespace std;
int dp[31][1001];
int main()
{
    int t, w;
    cin >> t >> w;
    int n[t];
    int ans = 0;
    for (int i = 0; i < t; i++)
    {
        cin >> n[i];
        if (n[i] == 1)
            dp[0][i + 1] = dp[0][i] + 1;
        else
            dp[0][i + 1] = dp[0][i];
        if (ans < dp[0][i + 1])
            ans = dp[0][i + 1];
    }
    for (int i = 1; i <= w; i++)
    {
        for (int j = 1; j <= t; j++)
        {
            if (j == 1)
            {
                if (i % 2 == 1 && n[j - 1] == 2)
                    dp[i][j]++;
                else if (i % 2 == 0 && n[j - 1] == 1)
                    dp[i][j]++;
            }
            else
            {
                dp[i][j] = dp[i - 1][j - 1] < dp[i][j - 1] ? dp[i][j - 1] : dp[i - 1][j - 1];
                if (i % 2 == 1 && n[j - 1] == 2)
                    dp[i][j]++;
                else if (i % 2 == 0 && n[j - 1] == 1)
                    dp[i][j]++;
            }
            if (ans < dp[i][j])
                ans = dp[i][j];
        }
    }
    cout << ans;
}