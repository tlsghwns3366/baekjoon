#include <iostream>
using namespace std;
int main()
{
    int n;
    int k = 1;
    while (cin >> n)
    {
        if (n == 0)
            break;
        int nn[n][3];
        int dp[n][3];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cin >> nn[i][j];
            }
        }
        dp[0][0] = nn[0][0];
        dp[0][1] = nn[0][1];
        dp[0][2] = nn[0][2];
        dp[1][0] = dp[0][1] + nn[1][0];
        dp[1][1] = min(min(dp[1][0] + nn[1][1], dp[0][1] + nn[1][1]), dp[0][1] + dp[0][2] + nn[1][1]);
        dp[1][2] = min(min(dp[1][1] + nn[1][2], dp[0][1] + nn[1][2]), dp[0][1] + dp[0][2] + nn[1][2]);
        for (int i = 2; i < n; i++)
        {
            dp[i][0] = min(dp[i - 1][0] + nn[i][0], dp[i - 1][1] + nn[i][0]);
            dp[i][1] = min(min(min(dp[i][0] + nn[i][1], dp[i - 1][0] + nn[i][1]), dp[i - 1][1] + nn[i][1]), dp[i - 1][2] + nn[i][1]);
            dp[i][2] = min(min(dp[i][1] + nn[i][2], dp[i - 1][1] + nn[i][2]), dp[i - 1][2] + nn[i][2]);
        }
        cout << k << ". " << dp[n - 1][1] << "\n";
        k++;
    }
}