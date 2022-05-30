#include <iostream>
#include <climits>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int nn[n];
    int dp[n];
    for (int i = 0; i < n; i++)
    {
        cin >> nn[i];
        dp[i] = INT_MAX;
    }
    dp[0] = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= nn[i] && i + j < n; j++)
        {
            if (dp[i + j] > dp[i])
            {
                dp[i + j] = dp[i] + 1;
            }
        }
    }
    if (dp[n - 1] == INT_MAX)
        cout << -1;
    else
        cout << dp[n - 1];
}