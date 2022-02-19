#include <iostream>
using namespace std;
int main()
{
    int d, k;
    cin >> d >> k;
    int dp[d];
    fill(dp, dp + d, 0);
    for (int i = 1; i < k; i++)
    {
        for (int j = i; j < k; j++)
        {
            if (i + j > k)
                break;
            else
            {
                dp[0] = i;
                dp[1] = j;
                for (int w = 2; w < d; w++)
                {
                    dp[w] = dp[w - 1] + dp[w - 2];
                }
                if (dp[d - 1] == k)
                {
                    cout << dp[0] << "\n";
                    cout << dp[1];
                    i = k;
                }
            }
        }
    }
}