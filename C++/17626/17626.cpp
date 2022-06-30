#include <iostream>
using namespace std;
int f(int a, int b)
{
    if (a < b)
        return a;
    else
        return b;
}
int main()
{
    int n;
    cin >> n;
    int dp[50001];
    fill(dp, dp + 50001, 987654321);
    dp[0] = 0;
    for (int i = 0; i < 50001; i++)
    {
        for (int j = 1; i + (j * j) < 50001; j++)
        {
            dp[i + (j * j)] = f(dp[i + (j * j)], dp[i] + 1);
        }
    }
    cout << dp[n];
}