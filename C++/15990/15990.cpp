#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;

    long long int dp[100000][3] = {};
    dp[0][0] = 1;
    dp[1][1] = 1;
    dp[2][0] = 1;
    dp[2][1] = 1;
    dp[2][2] = 1;
    for (int i = 3; i < 100000; i++)
    {
        dp[i][0] = (dp[i - 1][1] + dp[i - 1][2]) % 1000000009;
        dp[i][1] = (dp[i - 2][0] + dp[i - 2][2]) % 1000000009;
        dp[i][2] = (dp[i - 3][0] + dp[i - 3][1]) % 1000000009;
    }
    for (int q = 0; q < t; q++)
    {
        int n;
        cin >> n;
        cout << (dp[n - 1][0] + dp[n - 1][1] + dp[n - 1][2]) % 1000000009 << "\n";
    }
}