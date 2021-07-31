#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    int **dp = new int *[41];
    for (int i = 0; i < 41; i++)
    {
        dp[i] = new int[2];
    }
    dp[0][0] = 1;
    dp[0][1] = 0;
    dp[1][0] = 0;
    dp[1][1] = 1;
    for (int i = 2; i < 41; i++)
    {
        dp[i][0] = 0;
        dp[i][1] = 0;
    }

    for (int j = 0; j < t; j++)
    {
        int n;
        cin >> n;
        if (dp[n][0] == 0 && dp[n][1] == 0)
        {
            for (int i = 0; i <= n; i++)
            {
                if (i > 1 && dp[i][0] == 0 && dp[i][1] == 0)
                {
                    dp[i][0] = dp[i - 1][0] + dp[i - 2][0];
                    dp[i][1] = dp[i - 1][1] + dp[i - 2][1];
                }
            }
            cout << dp[n][0] << " " << dp[n][1] << endl;
        }
        else
        {
            cout << dp[n][0] << " " << dp[n][1] << endl;
        }
    }
}