#include <iostream>
using namespace std;
int dp[1001][1001];
int main()
{
    int n, k;
    cin >> n >> k;
    dp[1][0] = 1;
    dp[2][0] = 2;
    dp[3][0] = 3;
    dp[4][0] = 4;
    dp[4][1] = 2;


    for (int i = 4; i <= n; i++)
    {
        dp[i][0]=i;
        for (int j = 1; j < k ; j++)
        {
            dp[i][j] = (dp[i-1][j] + dp[i-2][j-1]) %1000000003;
        }
    }
    cout<<dp[n][k-1];
}