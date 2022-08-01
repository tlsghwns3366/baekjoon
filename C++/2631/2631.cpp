#include <iostream>
using namespace std;
int nn[200];
int dp[200];
int main()
{
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> nn[i];
    }
    for (int i = 0; i < n; i++)
    {
        dp[i] = 1;
        for (int j = i - 1; j >= 0; j--)
        {
            if (nn[i] > nn[j])
                dp[i] = dp[i] > dp[j] + 1 ? dp[i] : dp[j] + 1;
        }
        if (ans < dp[i])
            ans = dp[i];
    }
    cout << n - ans;
}