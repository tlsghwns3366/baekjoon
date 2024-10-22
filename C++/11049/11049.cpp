#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    vector<vector<int>> dp(505, vector<int>(505, 0));
    vector<vector<int>> xy(505, vector<int>(2));
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> xy[i][0] >> xy[i][1];
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j + i <= n; j++)
        {
			dp[j][i + j] = 987654321;
            for (int k = j; k <= i + j; k++)
            {
                dp[j][i+j] = min(dp[j][i+j],  dp[j][k] + dp[k + 1][i + j]  + (xy[j][0] * xy[k][1] * xy[j + i][1]));
            }
        }
    }
    cout<<dp[1][n];
}