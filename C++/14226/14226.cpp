#include <iostream>
#include <climits>
using namespace std;
int f(int a, int b)
{
    return a < b ? a : b;
}
int main()
{
    int s;
    cin >> s;
    int dp[1002];
    fill(dp, dp + 1002, INT_MAX / 2);
    dp[1] = 0;
    for (int i = 1; i <= 1000; i++)
    {
        for (int j = 2; i * j <= 1000; j++)
        {
            dp[i * j] = f(dp[i * j], dp[i] + j);
        }
        for (int j = 1000; j >= 2; j--)
        {
            dp[j] = f(dp[j], dp[j + 1] + 1);
        }
    }
    cout << dp[s];
}