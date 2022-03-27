#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int nn[n];
    long long int dp[21];
    fill(dp, dp + 21, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> nn[i];
    }
    dp[nn[0]] = 1;
    for (int i = 1; i < n - 1; i++)
    {
        long long int dptemp[21];
        fill(dptemp, dptemp + 21, 0);
        for (int j = 0; j <= 20; j++)
        {
            if (dp[j] != 0)
            {
                if (j + nn[i] <= 20)
                {
                    dptemp[j + nn[i]] += dp[j];
                }
                if (j - nn[i] >= 0)
                {
                    dptemp[j - nn[i]] += dp[j];
                }
            }
        }
        for (int j = 0; j <= 20; j++)
        {
            dp[j] = dptemp[j];
        }
    }
    cout << dp[nn[n - 1]];
}