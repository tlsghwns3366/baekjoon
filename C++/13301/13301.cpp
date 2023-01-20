#include <iostream>
using namespace std;
int main()
{
    int n;
    long long int dp[81];
    cin >> n;
    dp[0] = 4;
    dp[1] = 6;
    for (int i = 2; i < n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    cout<<dp[n-1];
}