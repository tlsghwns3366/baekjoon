#include <iostream>
#include <vector>

using namespace std;
int main()
{
    int n;
    cin >> n;

    vector<vector<vector<long long>>> dp(4, vector<vector<long long>>(2, vector<long long>(1001)));

    dp[0][0][0] = 1;
    dp[1][1][0] = 1;
    dp[2][0][0] = 1;

    for (int i = 1; i <= n; i++)
    {
        dp[0][0][i] = (dp[0][0][i - 1] + dp[2][0][i - 1] + dp[3][0][i - 1])% 1000000;
        dp[2][0][i] = (dp[0][0][i - 1])% 1000000;
        dp[3][0][i] = (dp[2][0][i - 1])% 1000000;

        dp[0][1][i] = (dp[0][1][i - 1] + dp[1][1][i - 1] + dp[2][1][i - 1] + dp[3][1][i - 1])% 1000000;
        dp[1][1][i] = (dp[0][0][i - 1] + dp[2][0][i - 1] + dp[3][0][i - 1])% 1000000;
        dp[2][1][i] = (dp[0][1][i - 1] + dp[1][1][i - 1])% 1000000;
        dp[3][1][i] = (dp[2][1][i - 1])% 1000000;
    }
    long long answer = 0;
    answer += (dp[0][0][n - 1] + dp[0][1][n - 1])% 1000000;
    answer += (dp[1][0][n - 1] + dp[1][1][n - 1])% 1000000;
    answer += (dp[2][0][n - 1] + dp[2][1][n - 1])% 1000000;
    answer += (dp[3][0][n - 1] + dp[3][1][n - 1])% 1000000;

    cout<<answer % 1000000;
}