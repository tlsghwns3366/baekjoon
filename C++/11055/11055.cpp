#include <iostream>
using namespace std;
int f(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}
int main()
{
    int n;
    cin >> n;
    int nn[n];
    int dp[n];
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> nn[i];
        dp[i] = nn[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (nn[i] > nn[j])
            {
                dp[i] = f(dp[j] + nn[i], dp[i]);
            }
        }
        if (ans < dp[i])
            ans = dp[i];
    }
    cout << ans;
}