#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    int nn[n];
    for (int i = 0; i < n; i++)
    {
        cin >> nn[i];
    }
    sort(nn, nn + n);
    long long int dp[k + 1] = {};
    dp[0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = nn[i]; j <= k; j++)
        {
            dp[j] += dp[j - nn[i]];
        }
    }
    cout << dp[k];
}