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
    for (int i = n - 1; i >= 0; i--)
    {
        cin >> nn[i];
    }
    int dp[n];
    fill(dp, dp + n, 1);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (nn[i] > nn[j])
            {
                dp[i] = f(dp[i], dp[j] + 1);
            }
        }
        if (ans < dp[i])
            ans = dp[i];
    }
    cout << n - ans;
}